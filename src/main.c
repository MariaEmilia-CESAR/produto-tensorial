#include "matriz.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    if(argc != 3){
        fprintf(stderr, "Erro! Precisa ser 2 arquivos.");
        return 1;
    }else{
        printf("Arquivo aberto com sucesso!");
    }

    Matriz *A = ler_matriz(argv[1]);
    if(A == NULL){
        fprintf(stderr, "Matriz vazia!");
        return 1;
    }

    Matriz *B = ler_matriz(argv[2]);
    if(B == NULL){
        fprintf(stderr, "Matriz vazia!");
        liberar_matriz(A);
        return 1;
    }

    Matriz *T = produto_tensorial(A, B);

    if (T == NULL) {
        printf("Erro ao calcular produto tensorial\n");
        liberar_matriz(A);
        liberar_matriz(B);
        return 1;
    }

    printf("Resultado: %d x %d\n", T->linhas, T->colunas);
    salvararquivo(T, "tensor_mess.out");

    liberar_matriz(T);
    liberar_matriz(A);
    liberar_matriz(B);
    return 0;
}