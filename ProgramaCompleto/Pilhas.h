#ifndef PILHAS_H_INCLUDED
#define PILHAS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "util.h"

typedef struct pilha
{
    TCelula *fundo;
    TCelula *topo;
    int tamanho;
} TPilha;

void FPVazia(TPilha *Pilha);

int PVazia(TPilha Pilha);

void Empilhar(TProduto x, TPilha *Pilha);

void Desempilhar(TPilha *Pilha, TProduto *Item);

void ImprimirPilha(TPilha *Pilha);

int PesquisarPilha(TPilha pilha, TProduto x);

void LiberarPilha(TPilha *pilha);

int Tamanho(TPilha Pilha);

#endif // PILHAS_H_INCLUDED