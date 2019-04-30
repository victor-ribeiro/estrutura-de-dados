#define origem 2
float* alocaVetor(int iTam){
    return (float*) malloc(iTam * sizeof(int));
}

void iniciaMatriz(int linhas, int colunas, float** matriz_controle, float **matriz_destino){
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            matriz_destino[i][j] = matriz_controle[i][j] == 2 ? 100: 0;
        }
    }
}

float** alocaMatriz(int iLinhas, int iColumas){
    float** tmp = (float**) malloc(iLinhas * sizeof(int*));
    for(int i=0; i < iLinhas; i++) tmp[i] = alocaVetor(iColumas);
    return tmp;
}

void liberaMatriz(float** matriz, int linhas){
    for(int i = 0; i < linhas; free(matriz[i++]));
    free(matriz);
}

float concentracao(float** matriz_atual, float** matriz_anterior, int linhas, int colunas){
    float **dif = alocaMatriz(linhas, colunas);
    float maior;
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas ; j ++){
            if(matriz_atual[i][j]){
                dif[i][j] = fabs(matriz_atual[i][j] - matriz_anterior[i][j]) / matriz_atual[i][j];
                maior = dif[i][j];
            } 
            else dif[i][j] = 0;
        }
    }
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas ; j ++){
            if(dif[i][j] > maior) maior = dif[i][j];
        }
    }
    return maior;
}

float media(float valor_1, float valor_2, float valor_3, float valor_4){
    return (float) (valor_1 +  valor_2 + valor_3 + valor_4)/4;
}

void imprimirMatriz(float** fMatriz, int linhas, int colunas){
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; printf("%8.4f ", fMatriz[i][j++]));
        printf("\n");
    }
}

void dispersao(int linhas, int colunas, float** matriz_controle, float** matriz_inicial, float** matriz_destinho){
    float soma = 0;
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            soma=0;
            if( (matriz_controle[i][j]) && matriz_controle[i][j] != 2){
                soma += j < colunas ? matriz_inicial[i][j+1] : 0;
                soma += i < (linhas - 1) ? matriz_inicial[i+1][j] : 0;
                soma += j && (j < colunas) ? matriz_inicial[i][j-1]: 0;
                soma += i && (i < linhas) ? matriz_inicial[i-1][j]:0;
                matriz_destinho[i][j] = soma/4.;
            }
        }
    }
}

void copiaMatriz(float** matriz_original, float** matriz_destino, int linhas, int colunas){
    for(int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            matriz_destino[i][j] = matriz_original[i][j];
        }
    }
}