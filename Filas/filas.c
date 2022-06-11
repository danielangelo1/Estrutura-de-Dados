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

int FVazia(TFila Fila)
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
    if (!FVazia(*Fila)){
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

void ImprimirFila(TFila Fila){
   TFila Faux; TProduto x;
   FFVazia(&Faux);
   while(!FVazia(Fila)){
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
   int flag = 0;
   while ((!FVazia(fila)))
   {
       Desenfileirar(&fila, &item);
       if(item.codigo == x.codigo);
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
    while(!FVazia(*fila)){
        Desenfileirar(fila, &x);
    }
    free(fila->frente);
}






