#include<stdio.h>
#include<unistd.h>
#include"matriz.h"
#include "arquivo.h"

int main(){
    int linhas, colunas, iter=0, anima=1;
    float **ilha, **ilha_aux1, ** ilha_aux2;
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
    printf("\n");
    do{
        dispersao(linhas, colunas, ilha,ilha_aux1, ilha_aux2);
        copiaMatriz(ilha_aux1, ilha_aux2, linhas, colunas);
        if(anima){
            imprimirMatriz(ilha_aux2, linhas, colunas);
            sleep(1);
            printf("\n");
        }
        iter++;
    } while(concentracao(ilha_aux1, ilha_aux2, linhas, colunas) > 0.0001);
    if(!anima) imprimirMatriz(ilha_aux1, linhas, colunas);
    printf("\n");
    printf("%d iterações\n", iter);

    liberaMatriz(ilha, linhas);
    liberaMatriz(ilha_aux1, linhas);
    liberaMatriz(ilha_aux2, linhas);
    return 0;
}