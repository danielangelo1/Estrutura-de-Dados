#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "Pilhas.h"

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
  if (PVazia(*Pilha))
  {
    printf("Erro: lista vazia\n");
    return;
  }
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