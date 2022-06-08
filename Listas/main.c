#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

void MSG_MENU(){
    printf("\n******************** MENU ***********************");
    printf("\n\t1. INSERIR"); // done
    printf("\n\t2. PESQUISAR"); // done
    printf("\n\t3. EXCLUIR"); //done
    printf("\n\t4. ALTERAR");
    printf("\n\t5. IMPRIMIR"); //done 
    printf("\n\t6. SAIR"); //done
}

int main()
{
    // Declaração de variáveis:
    TLista lista;
    TProduto item;
    TCelula *Aux;

    // Inicialização da lista
    FLVazia(&lista);

    int opcao = 0;
    do
    {
        system("cls");
        MSG_MENU();
        printf("\n\nDIGITE UMA OPCAO:");
        fflush(stdin);
        scanf("%d", &opcao);

        switch(opcao)
        {
        case 1:
            system("cls");
            LerProduto(&item);
            Inserir(item, &lista);
            system("PAUSE");
            break;
        case 2:
            system("cls");
            printf("\nDigite o codigo do produto a ser procurado: ");
            fflush(stdin);
            scanf("%d", &item.codigo);
            Aux = PesquisarLista(lista, item);
            if(Aux == NULL){
                printf("\nProduto nao encontrado!\n");
            }else{
                ImprimirProduto(Aux->prox->item);
            }
            system("PAUSE");
            break;
        case 3:
            system("cls");
            printf("\nDigite o codigo do produto que deseja excluir: ");
            fflush(stdin);
            scanf("%d", &item.codigo);

            Aux = PesquisarLista(lista, item);
            if(Aux == NULL){
                printf("\nProduto nao encontrado!\n");
            }else{
                Excluir(&lista, &item);
             printf("\nProduto excluido com sucesso!\n");
            }
            system("PAUSE");
            break;
        case 4:
            system("cls");
            printf("Digite o codigo do produto que deseja alterar: \n");
            fflush(stdin);
            scanf("%d", &item.codigo);
            Alterar(&lista, item);
            system("PAUSE");
            break;
        case 5:
            system("cls");
            ImprimirLista(lista);
            system("PAUSE");
            break;
        case 6:
            system("cls");
            system("PAUSE");
            break;
        default:
            system("cls");
            system("PAUSE");
        }
    } while(opcao != 6);

    return 0;
}
 