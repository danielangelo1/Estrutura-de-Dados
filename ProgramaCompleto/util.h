#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED 

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

#include <stdio.h>
#include <stdlib.h>

void LerProduto(TProduto *item);

void ImprimirProduto(TProduto item);

#endif // UTIL_H_INCLUDED