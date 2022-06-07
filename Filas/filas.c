#include <stdlib.h>
#include <stdio.h>
#include "filas.h"

void FFVazia(TFila *Fila)
{
    Fila->frente =
        (TCelula*) malloc(sizeof(TCelula));
    Fila->tras = Fila->frente;
    Fila->frente->prox = NULL;
    Fila->tamanho = 0;
}

int Vazia(TFila Fila)
{
    return (Fila.frente == Fila.tras);
}

void Enfileirar(TProduto x, TFila *Fila)
{
    Fila->tras->prox =
        (TCelula*) malloc(sizeof(TCelula));
    Fila->tras = Fila->tras->prox;
    Fila->tras->item = x;
    Fila->tras->prox = NULL;
    Fila->tamanho++;
}

void Desenfileirar(TFila *Fila, TProduto *Item){
    TCelula* aux;
    if (!Vazia(*Fila)){
        aux = Fila->frente->prox;
        Fila->frente->prox = aux->prox;
        *Item = aux->item;
        free(aux);
        if (Fila->frente->prox == NULL)
            Fila->tras = Fila->frente;
        Fila->tamanho--;
        printf("\nProduto desenfileirado com sucesso!\n");
    }else{
        printf("\n A fila ja esta vazia!\n");
    }
}

void LerProduto(TProduto *item){
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

void ImprimirProduto(TProduto item)
{
    printf("\n CODIGO do produto: %d", item.codigo);
    printf("\n NOME do produto: %s", item.nome);
    printf("\n PRECO do produto: %.2f\n", item.preco);

}

void Imprimir(TFila Filas){
    TCelula* Aux;
    Aux = Filas.frente -> prox;
    printf("Fila:\n");
    if(Aux != NULL)
    {
        while(Aux != NULL)
        {
                ImprimirProduto(Aux->item);
                 Aux = Aux -> prox;
        }
    }else{
        printf("Fila vazia.\n");
        return;
    }
}

int Pesquisar(TFila fila, TProduto x)
{
   TCelula* Aux;
   Aux = fila.frente;
   while(Aux->prox != NULL){
      if(Aux->prox->item.codigo == x.codigo)
         return 1;
      Aux = Aux->prox;
   }
   return 0;
}


void LiberarFila(TFila *fila)
{
    TCelula* Aux = fila->frente;

    while(Aux != NULL){
        TCelula* Aux2 = Aux->prox;
        free(Aux);
        Aux = Aux2;
    }
    free(fila);
}






