#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "pilhas.h"

void FPVazia(TPilha *Pilha)
{
  Pilha->topo = (TCelula *)
      malloc(sizeof(TCelula));
  Pilha->fundo = Pilha->topo;
  Pilha->topo->prox = NULL;
  Pilha->tamanho = 0;
}

int PVazia(TPilha Pilha)
{
  return (Pilha.topo == Pilha.fundo);
}

void Empilhar(TProduto x, TPilha *Pilha)
{
  TCelula *Aux;
  Aux = (TCelula *)
      malloc(sizeof(TCelula));
  Pilha->topo->item = x;
  Aux->prox = Pilha->topo;
  Pilha->topo = Aux;
  Pilha->tamanho++;
}

void Desempilhar(TPilha *Pilha, TProduto *Item)
{
  TCelula *q;
  q = Pilha->topo;
  Pilha->topo = q->prox;
  *Item = q->prox->item;
  free(q);
  Pilha->tamanho--;
}

void ImprimirPilha(TPilha *Pilha)
{
  TPilha PilhaAux;
  FPVazia(&PilhaAux);
  TProduto Item;
  if (PVazia(*Pilha))
    printf("Lista vazia.\n");

  // Pop de PIlha e Push em Pilha auxiliar
  while (!PVazia(*Pilha))
  {
    Desempilhar(Pilha, &Item);
    Empilhar(Item, &PilhaAux);
  }

  while (!PVazia(PilhaAux))
  {
    Desempilhar(&PilhaAux, &Item);
    ImprimirProduto(Item); // realizar a impressão
                           // de cada campo do produto
    Empilhar(Item, Pilha);
  }
  free(PilhaAux.topo); // eliminar a célula cabeça
}

void ImprimirProduto(TProduto item)
{
  printf("\n CODIGO do produto: %d", item.codigo);
  printf("\n NOME do produto: %s", item.nome);
  printf("\n PRECO do produto: %.2f\n", item.preco);
}

int PesquisarPilha(TPilha pilha, TProduto x)
{
  TPilha Paux;
  TProduto item;
  int flag = 0;
  FPVazia(&Paux);
  if (PVazia(pilha))
  {
    printf("Pilha vazia.\n");
  }

  while ((!PVazia(pilha)))
  {
    Desempilhar(&pilha, &item);
    if (item.codigo == x.codigo)
      flag = 1;
    Empilhar(item, &Paux);
    
  }
  while (!PVazia(Paux))
  {
    Desempilhar(&Paux, &x);
    Empilhar(x, &pilha);
  }
  free(Paux.topo);
  return flag;
}

void LerProduto(TProduto *item)
{
  printf("\nDIGITE O CODIGO DO PRODUTO: ");
  fflush(stdin);
  scanf("%d", &item->codigo);
  printf("\nDIGITE O NOME DO PRODUTO: ");
  fflush(stdin);
  fgets(item->nome, 100, stdin);
  printf("\nDIGITE O PRECO DO PRODUTO: ");
  fflush(stdin);
  scanf("%lf", &item->preco);
}

void LiberarPilha(TPilha *Pilha)
{
  TProduto Item;
  while (!PVazia(*Pilha))
  {
    Desempilhar(Pilha, &Item);
  }
  free(Pilha->topo);
}

int Tamanho(TPilha Pilha)
{
  return (Pilha.tamanho);
}
