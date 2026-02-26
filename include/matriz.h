#ifndef MATRIZ_H
#define MATRIZ_H

typedef struct {
    int linhas, colunas;
    double **alocar;
} Matriz;

Matriz* criar_matriz(int linhas, int colunas);
Matriz* ler_matriz(const char *arquivonome);
Matriz* produto_tensorial(Matriz *A, Matriz *B);
void liberar_matriz(Matriz *m);
void imprimir_matriz(Matriz *m);
void salvararquivo(Matriz *m, const char *nomearquivo);


#endif