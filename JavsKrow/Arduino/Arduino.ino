#include <LedControl.h>
#include <Arduino.h>

LedControl lc=LedControl(51,52,53,1);
int btnDisparo = A0;
int btnIzq = A2;
int btnDer = A3;
bool GAME_OVER = true;
byte cuadriculaLimpia[16] = {};
const int VELOCIDAD_JUEGO = 5;

// PROYECTIL -----------------------------------------------------------------------------
const int MAX_NUMERO_DE_PROYECTILES = 20;
const int TODOS_LOS_COHETES_HAN_SIDO_USADOS = -1;

struct Proyectil {  
  int coordX, coordY;
  long unsigned tiempoActualizacion;

  bool golpeoNave(int, int);
};

Proyectil PROYECTIL_NULO = {0, 0, 0};
Proyectil proyectilesActivos[MAX_NUMERO_DE_PROYECTILES] = {};

bool esProyectilNulo(Proyectil proyectil) {
  return ((proyectil.coordX == PROYECTIL_NULO.coordX) && (proyectil.coordY == PROYECTIL_NULO.coordY) && (proyectil.tiempoActualizacion == PROYECTIL_NULO.tiempoActualizacion));
}

int nuevoIdProyectil(){
  for (int i = 0; i < MAX_NUMERO_DE_PROYECTILES; i++) {
    if (esProyectilNulo(proyectilesActivos[i])) {
      return i;
    }
  }
  return TODOS_LOS_COHETES_HAN_SIDO_USADOS;
}


void eliminarProyectil(int idProyectil){
  proyectilesActivos[idProyectil] = PROYECTIL_NULO;
}

bool Proyectil::golpeoNave(int enemigoX, int enemigoY) {
  return ((coordX == enemigoX) && (coordY == enemigoY));
}

// NAVE ----------------------------------------------------------------------------------
class Nave {
  public:
    int coordX, velMov, velDisparo, score[2]; // [0]: Decenas, [1]; Unidades
  
    bool puedeMovIzq();
    bool puedeMovDer();
    bool puedeDisparar();
  
    bool estaTocandoCoordenadas(int, int); // x, y
  
    void moverseIzq();
    void moverseDer();
    void disparar();

  private:
    long unsigned int tiempoUltimoMov;
    long unsigned int tiempoUltimoDisparo;
};

bool Nave::puedeMovIzq() {
  return (coordX > 1 && (millis() - tiempoUltimoMov) > velMov);
}

bool Nave::puedeMovDer() {
  return (coordX < 6 && (millis() - tiempoUltimoMov) > velMov);
}

bool Nave::puedeDisparar() {
  return (millis() - tiempoUltimoDisparo) > velDisparo;
}

bool Nave::estaTocandoCoordenadas(int x, int y) {
  bool estaTocandoLadoDer = ((x == coordX + 1) && (y == 1));
  bool estaTocandoLadoIzq = ((x == coordX - 1) && (y == 1));
  bool estaTocandoLadoFrontal = ((x == coordX) && (y == 2));

  return (estaTocandoLadoDer || estaTocandoLadoIzq  || estaTocandoLadoFrontal);
}

void Nave::moverseIzq() {
  if (coordX > 1) {
    coordX -= 1;
  }
  tiempoUltimoMov = millis();
}

void Nave::moverseDer() {
  if (coordX < 6) {
    coordX += 1;
  }
  tiempoUltimoMov = millis();
}

void Nave::disparar() {
  int idProyectil = nuevoIdProyectil();

  if (idProyectil != TODOS_LOS_COHETES_HAN_SIDO_USADOS) {
    proyectilesActivos[idProyectil] = (Proyectil){coordX, 2, millis()};
  }

  tiempoUltimoDisparo = millis();
}

Nave nave;


// ENEMIGO ----------------------------------------------------------------------------------


// JUEGO ------------------------------------------------------------------------------------
byte cuadriculaActual[16] = {};


void dibujarCuadricula(byte * cuadricula){
  int contadorM2 = 7;
  for (int i = 0; i < 16; i++){
    if(i < 8){
      digitalWrite(i + 32, HIGH);
      for (int j = 7; j>=0; j--){
        int a = cuadricula[i] >> j;
        bool valor = a & 1;
        if(valor){
          digitalWrite(j + 22,LOW);
        }else{
          digitalWrite(j + 22,HIGH);
        }        
      }
      delay(VELOCIDAD_JUEGO);
      digitalWrite(i + 32, LOW);
      for (int j = 22; j<30; j++){
        digitalWrite(j, HIGH);
      }
      
    }else{
        lc.setColumn(0, contadorM2, cuadricula[i]);
        delay(VELOCIDAD_JUEGO);
        //lc.setColumn(0, contadorM2, B00000000);
        contadorM2--;
    }
  }
}

void dibujarNave(int coord){
  cuadriculaActual[14] = B01000000 >> coord - 1;
  cuadriculaActual[15] = B11100000 >> coord - 1;
}

void dibujarProyectiles(){
  Proyectil proyectil;
  for (int idProyectil = 0; idProyectil < MAX_NUMERO_DE_PROYECTILES; idProyectil++){
    proyectil = proyectilesActivos[idProyectil];
    if(!esProyectilNulo(proyectil)){
      if(proyectil.coordY < 8){
        lc.setLed(0, proyectil.coordX, proyectil.coordY, true);  
      }else {
        byte arregloTemp[16] = {};
        memcpy(arregloTemp, cuadriculaActual, 16);
        arregloTemp[15-proyectil.coordY] = B10000000 >> proyectil.coordX;
        dibujarCuadricula(arregloTemp);
        /*
        for (int i = 0; i < 8; i++){
          if(i == (proyectil.coordY-8)){
            digitalWrite(32+i, HIGH);
            for (int j = 7; j >= 0; j--){
              if(j == proyectil.coordX-j){
                digitalWrite(j + 22, LOW);
              }
            }
            delay(VELOCIDAD_JUEGO);
            digitalWrite(32+i, LOW);
            for (int j = 22; j<30; j++){
              digitalWrite(j, HIGH);
            }
          }      
        }*/
      }      
      if(proyectil.coordY < 16){
        proyectilesActivos[idProyectil].coordY += 1;
        proyectilesActivos[idProyectil].tiempoActualizacion += millis();          
      }else {
        eliminarProyectil(idProyectil);
      }
    }
  }
}

bool estaPresionado(int idBtn){
  int estadoBtn = digitalRead(idBtn);
  return (estadoBtn == HIGH);
}

void reiniciarJuego(){
  GAME_OVER = true;
  dibujarCuadricula(cuadriculaLimpia);
  // Nave
  nave.coordX = 3;
  nave.velMov = 50;
  nave.velDisparo = 200;
  // Proyectiles
  for (int idProyectil = 0; idProyectil < MAX_NUMERO_DE_PROYECTILES; idProyectil++){
    eliminarProyectil(idProyectil);    
  }  
}

// SETUP ------------------------------------------------------------------------------------
void setup() {
  Serial.begin(9600); 
  
  // Pines Matriz 1
  for (int i=22; i<30; i++){ 
    pinMode(i, OUTPUT); 
  }
  for (int i=32; i<40; i++){
    pinMode(i, OUTPUT); 
  }

  // Driver Matriz 2
  lc.shutdown(0, false);  
  lc.setIntensity(0, 15); 
  lc.clearDisplay(0);

  reiniciarJuego();
}

void loop() {
  if (!GAME_OVER) {
    if (estaPresionado(btnIzq) && nave.puedeMovIzq()) {
      nave.moverseIzq();
    }
  
    if (estaPresionado(btnDer) && nave.puedeMovDer()) {
      nave.moverseDer();
    }
    
    if (estaPresionado(btnDisparo) && nave.puedeDisparar()) {
      nave.disparar();
    }
    /*
    if (random(10) < 3) {
      createMeteor();
    }*/
  
    memcpy(cuadriculaActual, cuadriculaLimpia, 16);

    dibujarNave(nave.coordX);
    dibujarCuadricula(cuadriculaActual);
    dibujarProyectiles();
    //drawMeteors();
  
    //checkIfMeteorTouchedNave();
    //checkIfNaveHitMeteor();

  } else {
    if (estaPresionado(btnIzq) || estaPresionado(btnDer)  || estaPresionado(btnDisparo)) {
      GAME_OVER = false;
    }
    delay(250);
  }
}
