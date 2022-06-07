#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct produto{
    int codigo;
    char nome[100];
    char descricao[100];
    double preco;
    int unidade;
} TProduto;

typedef struct celula{
    TProduto item;
    struct celula *prox;
} TCelula;


typedef struct {
  TCelula *primeiro;
  TCelula *ultimo;
  int tamanho;
} TLista;

void FLVazia(TLista *Lista);

int Vazia(TLista Lista);

void Inserir(TProduto x, TLista *Lista);

TCelula* Pesquisar(TLista Lista, TProduto Item);

void Excluir(TLista *Lista, TProduto *Item);

void Imprimir(TLista Lista);

void ImprimirProduto(TProduto item);

void LerProduto(TProduto *item);

void Alterar(TLista *Lista, TProduto item );

#endif // LISTA_H_INCLUDED
