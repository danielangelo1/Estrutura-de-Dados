#ifndef FILAS_H_INCLUDED
#define FILAS_H_INCLUDED

typedef struct item
{
    int codigo;
    char nome[100];
    double preco;

} TProduto;

typedef struct celula
{
    TProduto item;
    struct celula* prox;
} TCelula;

typedef struct fila
{
    TCelula* frente;
    TCelula* tras;
    int tamanho;
} TFila;

#include <stdio.h>
#include <stdlib.h>

void FFVazia(TFila *Fila);

int Vazia(TFila Fila);

void Enfileirar(TProduto x, TFila *Fila);

void Desenfileirar(TFila *Fila, TProduto *Item);

void Imprimir(TFila Fila);

void LerProduto(TProduto *item);

void ImprimirProduto(TProduto item);

int Pesquisar(TFila fila, TProduto x);

void LiberarFila(TFila *fila);


#endif // FILA_H_INCLUDED