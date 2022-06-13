#include <stdlib.h>
#include <stdio.h>
#include "util.h"

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

void ImprimirProduto(TProduto item)
{
    printf("\n CODIGO do produto: %d", item.codigo);
    printf("\n NOME do produto: %s", item.nome);
    printf("\n PRECO do produto: %.2f\n", item.preco);
}