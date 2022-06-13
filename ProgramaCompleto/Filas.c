#include <stdlib.h>
#include <stdio.h>
#include "Filas.h"

void FFVazia(TFila *Fila)
{
    Fila->frente =
        (TCelula *)malloc(sizeof(TCelula));
    Fila->tras = Fila->frente;
    Fila->frente->prox = NULL;
    Fila->tamanho = 0;
}

int FVazia(TFila Fila)
{
    return (Fila.frente == Fila.tras);
}

void Enfileirar(TProduto x, TFila *Fila)
{
    Fila->tras->prox =
        (TCelula *)malloc(sizeof(TCelula));
    Fila->tras = Fila->tras->prox;
    Fila->tras->item = x;
    Fila->tras->prox = NULL;
    Fila->tamanho++;
}

void Desenfileirar(TFila *Fila, TProduto *Item)
{
    TCelula *aux;
    if (!FVazia(*Fila))
    {
        aux = Fila->frente->prox;
        Fila->frente->prox = aux->prox;
        *Item = aux->item;
        free(aux);
        if (Fila->frente->prox == NULL)
            Fila->tras = Fila->frente;
        Fila->tamanho--;
    }
    else
    {
        printf("\n A fila ja esta vazia!\n");
    }
}

void ImprimirFila(TFila Fila)
{
    TFila Faux;
    TProduto x;
    FFVazia(&Faux);
    if (FVazia(Fila))
        printf("Fila vazia\n");
    while (!FVazia(Fila))
    {
        Desenfileirar(&Fila, &x);
        ImprimirProduto(x);
        Enfileirar(x, &Faux);
    }
    while ((!FVazia(Faux)))
    {
        Desenfileirar(&Faux, &x);
        Enfileirar(x, &Fila);
    }
    free(Faux.frente);
}

int PesquisarFila(TFila fila, TProduto x)
{
    TFila Faux;
    TProduto item;
    FFVazia(&Faux);
    int flag = 0;
    while ((!FVazia(fila)))
    {
        Desenfileirar(&fila, &item);
        if (item.codigo == x.codigo)
            flag = 1;
        Enfileirar(item, &Faux);
    }
    while (!FVazia(Faux))
    {
        Desenfileirar(&Faux, &x);
        Enfileirar(x, &Faux);
    }
    free(Faux.frente);
    return flag;
}

void LiberarFila(TFila *fila)
{
    TProduto x;
    while (!FVazia(*fila))
    {
        Desenfileirar(fila, &x);
    }
    free(fila->frente);
}