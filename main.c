#include<stdio.h>
#include"matriz.h"
#include "arquivo.h"

#define TOLERANCIA 0.0001

int main(){
    int linhas, colunas, iter=0, anima=1;
    float **ilha, **ilha_aux1, ** ilha_aux2;
    float dif;
    char arq[100];
    
    printf("insita o nome do arquivo que deseja abrir: ");
    scanf("%s", arq);
    printf("abrindo - '%s'\n", arq);
    printf("Deseja animar a simulacao?\ndigite 0 para pular animacao: ");
    scanf("%d", &anima);

    lerLinhas(arq, &linhas, &colunas);
    printf("%d, %d\n", linhas, colunas);
    ilha=alocaMatriz(linhas, colunas);
    ilha_aux1=alocaMatriz(linhas, colunas); /* aloca matriz auxiliar*/
    ilha_aux2=alocaMatriz(linhas, colunas);

    lerArquivo(arq, ilha);

    iniciaMatriz(linhas, colunas, ilha, ilha_aux1);    
    iniciaMatriz(linhas, colunas, ilha, ilha_aux2);

    do{
        if(anima){
            system("clear");
            imprimirMatriz(ilha_aux2, linhas, colunas);
            sleep(.5);
            printf("\n");
        }
        dispersao(linhas, colunas, ilha, ilha_aux2, ilha_aux1);
        dif = concentracao(ilha_aux2, ilha_aux1, linhas, colunas);
        float **tmp = ilha_aux1;
        ilha_aux1 = ilha_aux2;
        ilha_aux2 = tmp;
//        copiaMatriz(ilha_aux2, ilha_aux1, linhas, colunas);
        iter++;
    } while(dif > TOLERANCIA);
    
    if(!anima) imprimirMatriz(ilha_aux1, linhas, colunas);
    printf("\n");
    printf("%d iterações\n", iter);

    liberaMatriz(ilha, linhas);
    liberaMatriz(ilha_aux1, linhas);
    liberaMatriz(ilha_aux2, linhas);
    return 0;
}