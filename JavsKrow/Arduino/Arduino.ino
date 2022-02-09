#include <LedControl.h>
#include <Arduino.h>

LedControl lc=LedControl(51,52,53,1);

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
byte cuadriculaActual[16] = {
  B10000000,// 0
  B01000000,// 1
  B00100000,// 2
  B00010000,// 3
  B00001000,// 4
  B00000100,// 5
  B00000010,// 6
  B00000001,// 7
  B00000010,// 8
  B00000100,// 9
  B00001000,// 10
  B00010000,// 11
  B00100000,// 12
  B01000000,// 13
  B10000000,// 14
  B01000000,// 15
};
int velJuego = 500;

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
      delay(1);
      digitalWrite(i + 32, LOW);
      for (int j = 22; j<30; j++){
        digitalWrite(j, HIGH);
      }
      
    }else{
        lc.setColumn(0, contadorM2, cuadricula[i]);
        delay(1);
        //lc.setColumn(0, contadorM2, B00000000);
        contadorM2--;
    }
  }
}













/*
//ESTE ARRAY ES PARA LIMPIAR MATRIZ
const byte MATRIZ1_NONE []= { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }; 
*/
//FUNCIÓN PARA LIMPIAR MATRIZ-TODOS LOS LEDS APAGADOS
void limpiarMatriz1() { 
  for (int i=22; i<30; i++){
    digitalWrite(i, HIGH);
  }
    for (int j= 32 ; j<40 ; j++){
      digitalWrite(j, LOW);
    }
} 

void setup() {
  // put your setup code here, to run once:
  for (int i=22; i<30; i++){ 
    pinMode(i, OUTPUT); 
  }
  for (int i=32; i<40; i++){
    pinMode(i, OUTPUT); 
  }
  Serial.begin(9600); 
  lc.shutdown(0, false);  // turn off power saving, enables display
  lc.setIntensity(0, 15);  // sets brightness (0~15 possible values)
  lc.clearDisplay(0);  // clear screen
}

void loop() {
  // put your main code here, to run repeatedly:
  limpiarMatriz1();
  dibujarCuadricula(cuadriculaActual);
}

/*
//FUNCIÓN PARA CONVETIR HEXADECIMAL A BINARIO
bool getBit( byte N, int pos) {
  int b = N >> pos ; 
  b = b & 1 ; 
  return b ; 
} 
*/
