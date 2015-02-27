#ifndef EINSTEIN_H
#define EINSTEIN_H



#include <cmath>
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <cstdio>
#include <list>

using namespace std;

typedef enum {BRITANICO =0, SUECO, DANES, NORUEGO, ALEMAN} nacionalidad; 
typedef enum {ROJA = 10, VERDE, BLANCA, AMARILLA, AZUL} casa;
typedef enum {PERRO = 100, PAJARO, GATO, CABALLO, PECECITO} mascota;
typedef enum {TE = 1000, CAFE, LECHE, CERVEZA, AGUA} bebida;
typedef enum {PALL = 10000, DUNHILL, BRENDS, BLUEMASTERS, PRINCE} fuma; 


#define Y 0
#define IZQUIERDA 1
#define DERECHA 2
#define VECINO 4

//posiciones de casa
#define ENMEDIO 2
#define PRIMERO 0

#define NACIONALIDAD 0
#define CASA 1
#define MASCOTA 2
#define BEBIDA 3
#define FUMA 4
#define POSICION 5

#define C1 0x1
#define C2 0x2
#define C3 0x4
#define C4 0x8
#define C5 0x10


#define UNDEF 0x0FFFFFFF

#define MASCARA_PERSISTENTE 0xF0000000
#define MASCARA_VALOR 0x0FFFFFFFF


//valores funciones auxiliares
#define TRUE 1
#define FALSE 0
#define ERROR -1


struct regla{
	int tipo1;
	int regal1;
	int conector;
	int tipo2;
	int regla2;
};


//funciones para cola


unsigned int tabla[5][6];

void init_entidades();
void define_reglas();
void agrega_regla(int, int, int, int, int);
int esta_izquierda(int, int);
int es_vecino(int, int);

char * get_nacionalidad(int);


//busqueda de mascota
int buscar_owner(int);
int bfs(int nac, int objetivo);

struct regla reglas[20];
int r_index;
char p_nacionalidad[50];


#endif
