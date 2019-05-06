#include<stdlib.h>
#include<math.h>
#include "matriz.c"

float* alocaVetor(int);
float** alocaMatriz(int, int);
void iniciaMatriz(int, int, float**, float **);
void liberaMatriz(float**, int);
float concentracao(float**, float**, int, int);
float media(float, float, float, float);
void imprimirMatriz(float**, int, int);
void dispersao(int, int, float**, float**, float**);
void copiaMatriz(float***, float***);