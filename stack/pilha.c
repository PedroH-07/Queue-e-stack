#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define MAX_STRING 256

// Estrutura da pilha para operações de desfazer
typedef struct {
    char operacoes[MAX_SIZE][MAX_STRING];
    int topo;
} PilhaDesfazer;

// Inicializar pilha
void inicializarPilha(PilhaDesfazer* pilha) {
    pilha->topo = -1;
}

// Verificar se a pilha está vazia
int pilhaVazia(PilhaDesfazer* pilha) {
    return pilha->topo == -1;
}

// Verificar se a pilha está cheia
int pilhaCheia(PilhaDesfazer* pilha) {
    return pilha->topo == MAX_SIZE - 1;
}

// Push - Adicionar operação na pilha
int push(PilhaDesfazer* pilha, const char* operacao) {
    if (pilhaCheia(pilha)) {
        printf("Erro: Pilha cheia! Não é possível adicionar mais operações.\n");
        return 0;
    }
    
    pilha->topo++;
    strcpy(pilha->operacoes[pilha->topo], operacao);
    printf("Operação adicionada: %s\n", operacao);
    return 1;
}

// Pop - Remover e retornar a última operação
char* pop(PilhaDesfazer* pilha) {
    if (pilhaVazia(pilha)) {
        printf("Erro: Pilha vazia! Não há operações para desfazer.\n");
        return NULL;
    }
    
    static char operacaoDesfeita[MAX_STRING];
    strcpy(operacaoDesfeita, pilha->operacoes[pilha->topo]);
    pilha->topo--;
    return operacaoDesfeita;
}

// Top - Ver a última operação sem removê-la
char* top(PilhaDesfazer* pilha) {
    if (pilhaVazia(pilha)) {
        printf("Pilha vazia!\n");
        return NULL;
    }
    
    return pilha->operacoes[pilha->topo];
}

// Mostrar histórico completo de operações
void mostrarHistorico(PilhaDesfazer* pilha) {
    if (pilhaVazia(pilha)) {
        printf("Nenhuma operação no histórico.\n");
        return;
    }
    
    printf("Histórico de operações (%d total):\n", pilha->topo + 1);
    for (int i = pilha->topo; i >= 0; i--) {
        printf("%d. %s\n", pilha->topo - i + 1, pilha->operacoes[i]);
    }
}

// Desfazer última operação
void desfazer(PilhaDesfazer* pilha) {
    char* operacao = pop(pilha);
    if (operacao != NULL) {
        printf("Operação desfeita: %s\n", operacao);
    }
}

int main() {
    PilhaDesfazer pilha;
    inicializarPilha(&pilha);
    
    // Exemplo de uso das funções da pilha
    printf("Testando pilha de desfazer ações:\n\n");
    
    // Adicionando algumas operações
    push(&pilha, "Escreveu palavra 'Hello'");
    push(&pilha, "Escreveu palavra 'World'");
    push(&pilha, "Escreveu palavra 'Test'");
    
    // Mostrando histórico
    mostrarHistorico(&pilha);
    
    // Testando função top
    printf("\nÚltima operação (top): %s\n", top(&pilha));
    
    // Desfazendo operações
    printf("\n--- Desfazendo operações ---\n");
    desfazer(&pilha);
    desfazer(&pilha);
    
    // Mostrando histórico após desfazer
    mostrarHistorico(&pilha);
    
    return 0;
}

// Testado e aprovado por Raí