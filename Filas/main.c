#include <stdio.h>
#include <stdlib.h>
#include "filas.h"

void MSG_MENU(){
    printf("\n******************** MENU ********************");
    printf("\n\t 1. ENFILEIRAR");
    printf("\n\t 2. DESENFILEIRAR");
    printf("\n\t 3. PESQUISAR");
    printf("\n\t 4. IMPRIMIR");
    printf("\n\t 5. SAIR");

}

int main(){
    //Declaracao de variaveis:
    TFila fila;
    TProduto item;

    // Inicialização da fila
    FFVazia(&fila);

    int opcao = 0;
    do{
        system("cls");
        MSG_MENU();
        printf("\n\n DIGITE UMA OPCAO:");
        fflush(stdin);
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            system("cls");
            LerProduto(&item);
            Enfileirar(item, &fila);
            printf("\n\n >>>>>>>>>>>>>>>>>>>>> MSG: PRODUTO INSERIDO COM SUCESSO! <<<<<<<<<<<<<<<<<\n");
            system("\nPAUSE");
            break;

        case 2:
            system("cls");
            Desenfileirar(&fila, &item);
            system("PAUSE");
            break;

        case 3:
            system("cls");
            printf("\nDigite o codigo do produto a ser procurado: ");
            fflush(stdin);
            scanf("%d", &item.codigo);
            if(PesquisarFila(fila, item)== 1){
                printf("\nProduto Encontrado na Fila!\n");
                ImprimirProduto(item);
            }
            else
                printf("\nProduto nao encontrado na  Fila!\n");
            
            system("PAUSE");
            break;

        case 4:
            system("cls");
            ImprimirFila(fila);
            system("PAUSE");
            break;

        case 5:
            system("cls");

            system("PAUSE");
            break;

        default:
            system("cls");
            printf("\n\n>>>>>>>>>>>>>>>>>>>>>>>>> MSG: DIGITE UMA OPCAO VALIDA! <<<<<<<<<<<<<<<<<<<<<<<\n\n");
            system("PAUSE");
            break;
        }
    } while (opcao != 5);

   LiberarFila(&fila);   
   return 0;

    
}