#ifndef FILAS_H_INCLUDED
#define FILAS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "util.h"

typedef struct fila
{
    TCelula *frente;
    TCelula *tras;
    int tamanho;
} TFila;

void FFVazia(TFila *Fila);

int FVazia(TFila Fila);

void Enfileirar(TProduto x, TFila *Fila);

void Desenfileirar(TFila *Fila, TProduto *Item);

void ImprimirFila(TFila Fila);

int PesquisarFila(TFila fila, TProduto x);

void LiberarFila(TFila *fila);

#endif // FILA_H_INCLUDED