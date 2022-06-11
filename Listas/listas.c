#include <stdlib.h>
#include <stdio.h>
#include "listas.h"

// passagem por referência: alteração será permanente!
void FLVazia(TLista *Lista)
{
  Lista->primeiro =
      (TCelula *)malloc(sizeof(TCelula));
  Lista->ultimo = Lista->primeiro;
  Lista->primeiro->prox = NULL;
  Lista->tamanho = 0;
}

// passagem de parâmetro por valor: a alteração NÃO é permanente!
int LVazia(TLista Lista)
{
  return (Lista.primeiro == Lista.ultimo);
}

void Inserir(TProduto x, TLista *Lista)
{
  Lista->ultimo->prox =
      (TCelula *)malloc(sizeof(TCelula));
  Lista->ultimo = Lista->ultimo->prox;
  Lista->ultimo->item = x;
  Lista->ultimo->prox = NULL;
  Lista->tamanho++;
}

TCelula *PesquisarLista(TLista Lista, TProduto Item)
{
  TCelula *Aux;
  Aux = Lista.primeiro;
  while (Aux->prox != NULL)
  {
    if (Aux->prox->item.codigo == Item.codigo)
      return Aux;
    Aux = Aux->prox;
  }
  return NULL;
}

void Excluir(TLista *Lista, TProduto *Item)
{
  /* Obs.: o item a ser retirado e o apontado por p */
  TCelula *Aux1, *Aux2;
  Aux1 = PesquisarLista(*Lista, *Item);
  if (Aux1 != NULL)
  {
    Aux2 = Aux1->prox;
    Aux1->prox = Aux2->prox;
    *Item = Aux2->item;
    if (Aux1->prox == NULL)
      Lista->ultimo = Aux1;
    free(Aux2);
    Lista->tamanho--;
  }
}

void ImprimirLista(TLista Lista)
{
  TCelula *Aux;
  Aux = Lista.primeiro->prox;
  if (LVazia(Lista))
    printf("Lista vazia.\n");
  while (Aux != NULL)
  {
    ImprimirProduto(Aux->item);
    Aux = Aux->prox;
  }
}

void ImprimirProduto(TProduto item)
{
  printf("\n CODIGO do produto: %d", item.codigo);
  printf("\n NOME do produto: %s", item.nome);
  printf("\n DESCRICAO do produto: %s", item.descricao);
  printf("\n PRECO do produto: %.2f", item.preco);
  printf("\n UNIDADE do produto: %d\n\n", item.unidade);
}

void LerProduto(TProduto *item)
{
  printf("\nDIGITE O CODIGO DO PRODUTO: ");
  fflush(stdin);
  scanf("%d", &item->codigo);
  printf("\nDIGITE O NOME DO PRODUTO: ");
  fflush(stdin);
  fgets(item->nome, 100, stdin);
  printf("\nDIGITE A DESCRICAO DO PRODUTO: ");
  fflush(stdin);
  fgets(item->descricao, 100, stdin);
  printf("\nDIGITE O PRECO DO PRODUTO: ");
  fflush(stdin);
  scanf("%lf", &item->preco);
  printf("\nDIGITE A QUANTIDADE DO PRODUTO: ");
  fflush(stdin);
  scanf("%d", &item->unidade);
}

void Alterar(TLista *lista, TProduto item)
{
  TCelula *Aux;
  Aux = PesquisarLista(*lista, item);
  if (Aux == NULL)
  {
    printf("\nProduto nao encontrado!\n");
  }
  else
  {
    Excluir(lista, &item);
    LerProduto(&item);
    Inserir(item, lista);
  }

  void LiberarLista(TLista * Lista)
  {
    while ((!LVazia(*lista)))
    {
      Excluir(Lista, &Lista->primeiro->item);
    }
    free(Lista->primeiro);
  }
}
