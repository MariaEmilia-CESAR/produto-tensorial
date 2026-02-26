#include "matriz.h"
#include <stdlib.h>
#include <stdio.h>

Matriz* ler_matriz(const char *arquivonome) {
    FILE *arquivo = fopen(arquivonome, "r");

    if(arquivo == NULL){
        return NULL;
    }

    int linhas, colunas;
    if(fscanf(arquivo, "%d %d", &linhas, &colunas) != 2){
        fclose(arquivo);
        return NULL;
    }
    Matriz *m = malloc(sizeof(Matriz));
    if(m == NULL){
        fclose(arquivo);
        return NULL;
    }
    m->linhas = linhas;
    m->colunas = colunas;
    m->alocar = malloc(linhas*sizeof(double*));

    if(m->alocar == NULL){
        free(m);
        fclose(arquivo);
        return NULL;
    }

    for(int i =0;i<linhas;i++){
        m->alocar[i] = malloc(colunas*sizeof(double));
        if(m->alocar[i] == NULL){
            fclose(arquivo);
            return NULL;
        }
    }

    for(int i=0;i<linhas;i++){
        for(int j=0;j<colunas;j++){
            fscanf(arquivo, "%lf", &m->alocar[i][j]);
        }
    }
    fclose(arquivo);
    return m;

}

Matriz* produto_tensorial(Matriz *A, Matriz *B) {

    if (A == NULL || B == NULL) {
        return NULL;
    }

    int novalinha = A->linhas * B->linhas;
    int novacoluna = A->colunas * B->colunas;

    Matriz *resultado = malloc(sizeof(Matriz));
    if (resultado == NULL) {
        return NULL;
    }

    resultado->linhas = novalinha;
    resultado->colunas = novacoluna;

    resultado->alocar = malloc(novalinha * sizeof(double*));
    if (resultado->alocar == NULL) {
        free(resultado);
        return NULL;
    }

    for (int i = 0; i < novalinha; i++) {
        resultado->alocar[i] = malloc(novacoluna * sizeof(double));
        if (resultado->alocar[i] == NULL) {
            free(resultado);
            return NULL;
        }
    }

    for (int i = 0; i < A->linhas; i++) {
        for (int j = 0; j < A->colunas; j++) {

            for (int k = 0; k < B->linhas; k++) {
                for (int l = 0; l < B->colunas; l++) {
                    resultado->alocar[i * B->linhas + k][j * B->colunas + l] = A->alocar[i][j] * B->alocar[k][l];
                }
            }
        }
    }

    return resultado;
}
void liberar_matriz(Matriz *m) {
    if(m == NULL){
        return;
    }

    for(int i =0;i<m->linhas;i++){
        free(m->alocar[i]);
    }
    free(m->alocar);
    free(m);
}

void imprimir_matriz(Matriz *m) {

    if (m == NULL) return;

    for (int i = 0; i < m->linhas; i++) {
        for (int j = 0; j < m->colunas; j++) {
            printf("%.2lf ", m->alocar[i][j]);
        }
        printf("\n");
    }
}

void salvararquivo(Matriz *m, const char *nome) {

    FILE *f = fopen(nome, "w");
    if (!f) {
        fprintf(stderr, "Erro ao criar arquivo de saída.\n");
        return;
    }

    for (int i = 0; i < m->linhas; i++) {
        for (int j = 0; j < m->colunas; j++) {
            fprintf(f, "%.2lf ", m->alocar[i][j]);
        }
        fprintf(f, "\n");
    }

    fclose(f);
}