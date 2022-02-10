#include "LedControl.h"

LedControl lc = LedControl(51, 52, 53, 1);

#define demora 80

// Las matrices de enteros se usan para mostrar el asterisco en la primer matriz

int asterisco_abajo_1[8][8] = {
  {0, 1, 0, 1, 0, 1, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
};


int asterisco_abajo_2[8][8] = {
  {0, 0, 1, 1, 1, 0, 0, 0},
  {0, 1, 0, 1, 0, 1, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
};



int asterisco_abajo_3[8][8] = {
  {0, 0, 0, 1, 0, 0, 0, 0},
  {0, 0, 1, 1, 1, 0, 0, 0},
  {0, 1, 0, 1, 0, 1, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
};

int asterisco_abajo_4[8][8] = {
  {0, 0, 1, 1, 1, 0, 0, 0},
  {0, 0, 0, 1, 0, 0, 0, 0},
  {0, 0, 1, 1, 1, 0, 0, 0},
  {0, 1, 0, 1, 0, 1, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
};

int asterisco_abajo_5[8][8] = {
  {0, 1, 0, 1, 0, 1, 0, 0},
  {0, 0, 1, 1, 1, 0, 0, 0},
  {0, 0, 0, 1, 0, 0, 0, 0},
  {0, 0, 1, 1, 1, 0, 0, 0},
  {0, 1, 0, 1, 0, 1, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
};

int asterisco_abajo_6[8][8] = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 1, 0, 1, 0, 1, 0, 0},
  {0, 0, 1, 1, 1, 0, 0, 0},
  {0, 0, 0, 1, 0, 0, 0, 0},
  {0, 0, 1, 1, 1, 0, 0, 0},
  {0, 1, 0, 1, 0, 1, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
};

int asterisco_abajo_7[8][8] = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 1, 0, 1, 0, 1, 0, 0},
  {0, 0, 1, 1, 1, 0, 0, 0},
  {0, 0, 0, 1, 0, 0, 0, 0},
  {0, 0, 1, 1, 1, 0, 0, 0},
  {0, 1, 0, 1, 0, 1, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
};

int asterisco_abajo_8[8][8] = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 1, 0, 1, 0, 1, 0, 0},
  {0, 0, 1, 1, 1, 0, 0, 0},
  {0, 0, 0, 1, 0, 0, 0, 0},
  {0, 0, 1, 1, 1, 0, 0, 0},
  {0, 1, 0, 1, 0, 1, 0, 0},
};

int asterisco_abajo_9[8][8] = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 1, 0, 1, 0, 1, 0, 0},
  {0, 0, 1, 1, 1, 0, 0, 0},
  {0, 0, 0, 1, 0, 0, 0, 0},
  {0, 0, 1, 1, 1, 0, 0, 0}
};

int asterisco_abajo_10[8][8] = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 1, 0, 1, 0, 1, 0, 0},
  {0, 0, 1, 1, 1, 0, 0, 0},
  {0, 0, 0, 1, 0, 0, 0, 0},
};

int asterisco_abajo_11[8][8] = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 1, 0, 1, 0, 1, 0, 0},
  {0, 0, 1, 1, 1, 0, 0, 0},
};

int asterisco_abajo_12[8][8] = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 1, 0, 1, 0, 1, 0, 0}
};


// Se usaran arreglos de bytes para la segunda matriz (la del controlador)
// se empiezan usar hasta la transicion 13, porque es hasta esta transicion cuando
// se empieza a ver en la matriz de abajo (con controlador)

byte asterisco_abajo_13[16] = {
  B01010100,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000
};

byte asterisco_abajo_14[16] = {
  B00111000,
  B01010100,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,

};

byte asterisco_abajo_15[16] = {
  B00010000,
  B00111000,
  B01010100,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000
};

byte asterisco_abajo_16[16] = {
  B00111000,
  B00010000,
  B00111000,
  B01010100,
  B00000000,
  B00000000,
  B00000000,
  B00000000
};

byte asterisco_abajo_17[16] = {
  B01010100,
  B00111000,
  B00010000,
  B00111000,
  B01010100,
  B00000000,
  B00000000,
  B00000000
};

byte asterisco_abajo_18[16] = {
  B00000000,
  B01010100,
  B00111000,
  B00010000,
  B00111000,
  B01010100,
  B00000000,
  B00000000
};

byte asterisco_abajo_19[16] = {
  B00000000,
  B00000000,
  B01010100,
  B00111000,
  B00010000,
  B00111000,
  B01010100,
  B00000000
};

byte asterisco_abajo_20[16] = {
  B00000000,
  B00000000,
  B00000000,
  B01010100,
  B00111000,
  B00010000,
  B00111000,
  B01010100
};

byte asterisco_abajo_21[16] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B01010100,
  B00111000,
  B00010000,
  B00111000
};

byte asterisco_abajo_22[16] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B01010100,
  B00111000,
  B00010000
};

byte asterisco_abajo_23[16] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B01010100,
  B00111000
};

byte asterisco_abajo_24[16] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B01010100
};



void setup() {
  
  // Inicializando los pines como salidas
  // Filas
  for (int i = 22; i < 30; i++) {
    pinMode(i, OUTPUT);
  }
  // Columnas
  for (int j = 32; j < 40; j++) {
    pinMode(j, OUTPUT);
  }

  // Para la matriz con driver (la de abajo)
  lc.shutdown(0, false); // Activando la matriz
  lc.setIntensity(0, 4); // Estableciendo la intensidad en la matriz 
  lc.clearDisplay(0); // "Limpiando" toda la matriz
  
}

void loop() {
  // Mostrando el * con un for en la primera matriz (sin controlador)
  mostrarAsteriscoConFor(asterisco_abajo_1);
  delay(demora);
  mostrarAsteriscoConFor(asterisco_abajo_2);
  delay(demora);
  mostrarAsteriscoConFor(asterisco_abajo_3);
  delay(demora);
  mostrarAsteriscoConFor(asterisco_abajo_4);
  delay(demora);
  mostrarAsteriscoConFor(asterisco_abajo_5);
  delay(demora);
  mostrarAsteriscoConFor(asterisco_abajo_6);
  delay(demora);
  mostrarAsteriscoConFor(asterisco_abajo_7);
  delay(demora);
  mostrarAsteriscoConFor(asterisco_abajo_8);
  delay(demora);
  
  // A partir de aqui, la primera parte del asterisco (*) se tiene que empezar a ver en la segunda matriz (la de abajo, sin contrador) pero igual siempre 
  // mostrando lo que resta del * en la primer matriz (la de arriba) con el for (sin controlador)
  // por lo que hay que intercalarlos
  mostrarAsteriscoConLibreria(asterisco_abajo_13);
  delay(50);
  
  mostrarAsteriscoConFor(asterisco_abajo_9);
  delay(50);

  mostrarAsteriscoConLibreria(asterisco_abajo_14);
  delay(50);
  
  mostrarAsteriscoConFor(asterisco_abajo_10);
  delay(50);

  mostrarAsteriscoConLibreria(asterisco_abajo_15);
  delay(50);
  
  mostrarAsteriscoConFor(asterisco_abajo_11);
  delay(50);

  // A partir de aqui, el * ya se deja de ver en el primer matriz (la de arriba), por lo que ya no es necesario ejecutarla con el bucle for, solo con ayuda de la libreria

  mostrarAsteriscoConLibreria(asterisco_abajo_16);
  delay(demora);
  mostrarAsteriscoConFor(asterisco_abajo_12);
  delay(demora);
  mostrarAsteriscoConLibreria(asterisco_abajo_17);
  delay(demora);
  mostrarAsteriscoConLibreria(asterisco_abajo_18);
  delay(demora);
  mostrarAsteriscoConLibreria(asterisco_abajo_19);
  delay(demora);
  mostrarAsteriscoConLibreria(asterisco_abajo_20);
  delay(demora);
  mostrarAsteriscoConLibreria(asterisco_abajo_21);
  delay(demora);
  mostrarAsteriscoConLibreria(asterisco_abajo_22);
  delay(demora);
  mostrarAsteriscoConLibreria(asterisco_abajo_23);
  delay(demora);
  mostrarAsteriscoConLibreria(asterisco_abajo_24);
  delay(demora);
  lc.setRow(0,7,B00000000); // Esto se usa para apagar la ultima fila de la matriz de abajo (con controlador), (porque sin esto se quedaba encendida la ultima fila)
}


// Muestra el asterisco en la primer matriz (la de arriba, sin controlador)
void mostrarAsteriscoConFor(int asterisco[8][8]){
  for (int i = 0; i < 8; i++) {
    digitalWrite(i + 22, LOW);
    for (int j = 0; j < 8; j++) {
      if (asterisco[i][j] == 1) {
        digitalWrite(j + 32, HIGH);
      }
    }
    delay(2);
    digitalWrite(i + 22, HIGH);
    for (int j = 32; j < 40; j++) {
      digitalWrite(j, LOW);
    }
  }
}

void mostrarAsteriscoConLibreria(byte asterisco[16]) {
  for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, asterisco[i]);
    
  }
  
}
