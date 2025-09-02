#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int senha[MAX];
    int inicio;
    int fim;
} Fila;

void inicializaFila(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
}

int filaVazia(Fila *f) {
    return f->inicio == f->fim;
}

int filaCheia(Fila *f) {
    return f->fim == MAX;
}

void enqueue(Fila *f, int senha) {
    if (filaCheia(f)) {
        printf("Fila cheia!\n");
        return;
    }
    f->senha[f->fim++] = senha;
}

int dequeue(Fila *f) {
    if (filaVazia(f)) {
        printf("Fila vazia!\n");
        return -1;
    }
    return f->senha[f->inicio++];
}

void mostrarFila(Fila *f) {
    printf("Fila atual: ");
    for (int i = f->inicio; i < f->fim; i++) {
        printf("%d ", f->senha[i]);
    }
    printf("\n");
}
