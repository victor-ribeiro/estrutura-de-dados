void lerLinhas(char *arq_nome, int* linhas, int* colunas){
    FILE* arq = fopen(arq_nome, "r");
    fscanf(arq, "%d\n%d\n", linhas, colunas);
    fclose(arq);
}

int lerArquivo(char *arq_nome, float** matriz){
    int linhas, colunas;
    FILE *arq = fopen(arq_nome, "r");
    if(!arq){
        return 1;
    }
    fscanf(arq, "%d\n%d\n", &linhas, &colunas);
    for(int i = 0; i < linhas; i++){ 
        for(int j = 0; j < colunas; j++){
            fscanf(arq, "%f,", &matriz[i][j]);
        }
    }
    fclose(arq);
    return 0;
}