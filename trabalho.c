#include <stdio.h>
#include <stdlib.h>

typedef int TIPOCHAVE;

typedef struct {
    TIPOCHAVE* A;  
    int nroElem;    
    int capacidade;
} LISTA;

void inicializarLista(LISTA* l) {
    l->capacidade = 50;
    l->nroElem = 0;
    l->A = (TIPOCHAVE*)malloc(l->capacidade * sizeof(TIPOCHAVE));
    if (l->A == NULL) exit(1);
}

void resize(LISTA* l, int novaCapacidade) {
    l->capacidade = novaCapacidade;
    l->A = (TIPOCHAVE*)realloc(l->A, l->capacidade * sizeof(TIPOCHAVE));
    if (l->A == NULL) exit(1);
}

void inserirElemento(LISTA* l, TIPOCHAVE ch) {
    if (l->nroElem == l->capacidade) resize(l, l->capacidade + l->capacidade / 4);
    l->A[l->nroElem++] = ch;
}

void removerElemento(LISTA* l, TIPOCHAVE ch) {
    int pos = -1;
    int i;  
    for (i = 0; i < l->nroElem; i++) {
        if (l->A[i] == ch) {
            pos = i;
            break;
        }
    }
    if (pos == -1) return;
    for (i = pos; i < l->nroElem - 1; i++) {  
        l->A[i] = l->A[i + 1];
    }
    l->nroElem--;
    if (l->nroElem < l->capacidade * 0.75) resize(l, l->capacidade - l->capacidade / 4);
}

void exibirLista(LISTA* l) {
    int i;  
    for (i = 0; i < l->nroElem; i++) {
        printf("%d ", l->A[i]);
    }
    printf("\n");
}

void liberarLista(LISTA* l) {
    free(l->A);
    l->A = NULL;
    l->capacidade = 0;
    l->nroElem = 0;
}

int main() {
    LISTA lista;
    inicializarLista(&lista);

    int i;  
    for (i = 1; i <= 55; i++) inserirElemento(&lista, i);
    exibirLista(&lista);

    for (i = 1; i <= 30; i++) removerElemento(&lista, i);
    exibirLista(&lista);

    liberarLista(&lista);
    return 0;
}

