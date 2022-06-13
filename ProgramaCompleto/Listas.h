#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "util.h"

typedef struct lista{
  TCelula *primeiro;
  TCelula *ultimo;
  int tamanho;
} TLista;

void FLVazia(TLista *Lista);

int LVazia(TLista Lista);

void Inserir(TProduto x, TLista *Lista);

TCelula* PesquisarLista(TLista Lista, TProduto Item);

void Excluir(TLista *Lista, TProduto *Item);

void ImprimirLista(TLista Lista);

void Alterar(TLista *Lista, TProduto item );

void LiberarLista(TLista * Lista);

#endif // LISTA_H_INCLUDED