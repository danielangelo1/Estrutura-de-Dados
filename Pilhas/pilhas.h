#ifndef PILHAS_H_INCLUDED
#define PILHAS_H_INCLUDED

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

typedef struct pilha
{
    TCelula* fundo;
    TCelula* topo;
    int tamanho;
} TPilha;

#include <stdio.h>
#include <stdlib.h>

void FPVazia(TPilha *Pilha);

int PVazia(TPilha Pilha);

void Empilhar(TProduto x, TPilha *Pilha);

void Desempilhar(TPilha *Pilha, TProduto *Item);

void ImprimirPilha(TPilha *Pilha);

void LerProduto(TProduto *item);

void ImprimirProduto(TProduto item);

int PesquisarPilha(TPilha pilha, TProduto x);

void LiberarPilha(TPilha *pilha);

int Tamanho(TPilha Pilha);

#endif // PILHAS_H_INCLUDED
