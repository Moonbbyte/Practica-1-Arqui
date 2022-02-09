//importamos librerias
#include <LedControl.h>
#include "letras.h"

// MOSTRAR ARRIBA ABAJO Y MOSTRA ABAJO ARRIBA MENSAJE INICIAL
// VELOCIDAD CON POTENCIOMETRO
// CONTADOR DE PUNTAJE 
// LA PAUSA SHUTDOWN 
// UTILIZAR 2DA MATRIZ

//analogRead(a2)
//Declaracion de variables
unsigned long tiempo1 = 0;
unsigned long tiempo2 = 0;
unsigned long tiempo3 = 0;
int potenciometro=A2;
int velocidad=0;
//salidas de arduino MEGA 51, 52, 53 video
//DNI, CLK, LOAD
//salidas de arduino UNO 11, 13, 10 video 

//manejo de matriz
int filas[] = {22, 23, 24, 25, 26, 27, 28, 29};
//int columnas[] = {53, 52, 51, 50, 49, 48, 47, 46};
int columnas[] = {46, 47, 48, 49, 50, 51, 52, 53};

int letra[][8]={
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0}
};

LedControl lc = LedControl(11,13,10,1); //1 dispositivo

void setup() {
  Serial.begin(9600);
  //inicializamos driver
    lc.shutdown(0, false); //inicia apagado - dispositivo 1
    lc.setIntensity(0, 4);
    lc.clearDisplay(0);
  
  for(int i = 0; i < 8; i++){
      pinMode(filas[i], OUTPUT);
      pinMode(columnas[i], OUTPUT);
    }
    LimpiarMatriz();
    tiempo1 = millis();
}

void loop() {
    tiempo2 = millis();
    tiempo3 = millis();
    velocidad=(potenciometro);

    //probamos la matriz
    for(int fila = 0; fila < 8; fila++){
      digitalWrite(filas[fila], HIGH);
      for(int columna = 0; columna < 8; columna++)
      {
        
        if(tiempo2 > (tiempo1)){
          letra[columna][fila] = ASTERISCO[columna][fila];
        }
       if (tiempo3 > (tiempo1+1000)){
          letra[columna][fila] = P[columna][fila];
          lc.setLed(0, columna, fila, ASTERISCO[fila][columna]);
          delay(1);
          //Serial.println(tiempo3);
        }
        
        if (tiempo3 > (tiempo1+2000)){
          letra[columna][fila] = UNO[columna][fila];
          lc.setLed(0, columna, fila, P[fila][columna]);
          delay(1);
        }
        if (tiempo3 > (tiempo1+3000)){
          letra[columna][fila] = GUION[columna][fila];
          lc.setLed(0, columna, fila, UNO[fila][columna]);
          delay(1);
        }
        /*----------------------------------------------------------------*/
        if (tiempo3 > (tiempo1+4000)){
          letra[columna][fila] = G[columna][fila];
          lc.setLed(0, columna, fila, GUION[fila][columna]);
          delay(1);
        }
        if (tiempo3 > (tiempo1+5000)){
          letra[columna][fila] = R[columna][fila];
          lc.setLed(0, columna, fila, G[fila][columna]);
          delay(1);
        }
        if (tiempo3 > (tiempo1+6000)){
          letra[columna][fila] = U[columna][fila];
          lc.setLed(0, columna, fila, R[fila][columna]);
          delay(1);
        }
        if (tiempo3 > (tiempo1+7000)){
          letra[columna][fila] = P[columna][fila];
          lc.setLed(0, columna, fila, U[fila][columna]);
          delay(1);
        }
        /*****/
        if (tiempo3 > (tiempo1+8000)){
          letra[columna][fila] = O[columna][fila];
          lc.setLed(0, columna, fila, P[fila][columna]);
          delay(1);
        }
        if (tiempo3 > (tiempo1+9000)){
          letra[columna][fila] = CUATRO[columna][fila];
          lc.setLed(0, columna, fila, O[fila][columna]);
          delay(1);
        }
        if (tiempo3 > (tiempo1+10000)){
          letra[columna][fila] = GUION[columna][fila];
          lc.setLed(0, columna, fila, CUATRO[fila][columna]);
          delay(1);
        }
        if (tiempo3 > (tiempo1+11000)){
          letra[columna][fila] = S[columna][fila];
          lc.setLed(0, columna, fila, GUION[fila][columna]);
          delay(1);
        }
        if (tiempo3 > (tiempo1+12000)){
          letra[columna][fila] = E[columna][fila];
          lc.setLed(0, columna, fila, S[fila][columna]);
          delay(1);
        }
        if (tiempo3 > (tiempo1+13000)){
          letra[columna][fila] = C[columna][fila];
          lc.setLed(0, columna, fila, E[fila][columna]);
          delay(1);
        }
        if (tiempo3 > (tiempo1+14000)){
          letra[columna][fila] = C[columna][fila];
          lc.setLed(0, columna, fila, C[fila][columna]);
          delay(1);
        }
        if (tiempo3 > (tiempo1+15000)){
          letra[columna][fila] = I[columna][fila];
          lc.setLed(0, columna, fila, C[fila][columna]);
          delay(1);
        }
        if (tiempo3 > (tiempo1+16000)){
          letra[columna][fila] = O[columna][fila];
          lc.setLed(0, columna, fila, I[fila][columna]);
          delay(1);
        }
        if (tiempo3 > (tiempo1+17000)){
          letra[columna][fila] = N[columna][fila];
          lc.setLed(0, columna, fila, O[fila][columna]);
          delay(1);
        }
        if (tiempo3 > (tiempo1+18000)){
          letra[columna][fila] = ASTERISCO[columna][fila];
          lc.setLed(0, columna, fila, A[fila][columna]);
          delay(1);
        }

       
      }
    Encender();
    LimpiarMatriz();
    }
}
//MANIPULACION DE LA VELOCIDAD GRACIAS AL POTENCIOMETRO


void LimpiarMatriz(){
  for(int i = 0; i < 8; i++){
    digitalWrite(filas[i], LOW);
    digitalWrite(columnas[i], HIGH);
  }
}
void  Pausa(){
  lc.shutdown(0, true);
  
  //apaga
  
}
void Adelante(){}
void Atras(){}

void Encender(){

 for(int columna = 0; columna < 8; columna++){
      digitalWrite(filas[columna],HIGH);
      for(int fila=0; fila < 8; fila++){
        if(letra[columna][fila] == 1){
          digitalWrite(columnas[fila],LOW);
        }
      }
      delay(1);
      digitalWrite(filas[columna],LOW);
      for(int j = 0; j < 8;j++){
        digitalWrite(columnas[j],HIGH);
      }
    }

 


    
    //delay(2);
    //LimpiarMatriz();

    //}


   








    
}
