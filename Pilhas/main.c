#include <stdio.h>
#include <stdlib.h>
#include "pilhas.h"

void MSG_MENU(){
    printf("\n******************** MENU ********************");
    printf("\n\t 1. EMPILHAR");
    printf("\n\t 2. DESEMPILHAR");
    printf("\n\t 3. PESQUISAR");
    printf("\n\t 4. IMPRIMIR");
    printf("\n\t 5. SAIR");

}

int main(){
    //Declaracao de variaveis:
    TPilha pilha;
    TProduto item;

    // Inicialização da fila
    FPVazia(&pilha);

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
            Empilhar(item, &pilha);
            printf("\n\n >>>>>>>>>>>>>>>>>>>>> MSG: PRODUTO INSERIDO COM SUCESSO! <<<<<<<<<<<<<<<<<<\n");
            system("PAUSE");
            break;

        case 2:
            system("cls");
            Desempilhar(&pilha, &item);
            system("PAUSE");
            break;

        case 3:
            system("cls");
            printf("\nDigite o codigo do produto a ser procurado: ");
            fflush(stdin);
            scanf("%d", &item.codigo);
            if(PesquisarPilha(pilha,item) == 1)
            {
                printf("\nProduto Encontrado na Pilha!\n");
                ImprimirProduto(item);
            }
            else
                printf("\nProduto nao encontrado na Pilha :/\n");
                
            system("PAUSE");
            break;

        case 4:
            system("cls");
            ImprimirPilha(&pilha);
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

   LiberarPilha(&pilha);   
   return 0;

    
}