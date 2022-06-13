#include <stdio.h>
#include <stdlib.h>
#include "Pilhas.h"
#include "Filas.h"
#include "Listas.h"

void MSG_MENU()
{
    printf("\n******************** MENU ********************");
    printf("\n\t 1. INSERIR NA LISTA");     // done
    printf("\n\t 2. ENFILEIRAR NA FILA");   // done
    printf("\n\t 3. EMPILHAR NA PILHA");    // done
    printf("\n\t 4. INVERTER ORDEM PILHA"); // done
    printf("\n\t 5. INVERTER ORDEM FILA");  // done
    printf("\n\t 6. INVERTER ORDEM LISTA"); // nao funfa
    printf("\n\t 7. PESQUISAR E EXCLUIR FILA"); // nao funfa 
    printf("\n\t 8. PESQUISAR E EXCLUIR PILHA"); // done
    printf("\n\t 9. IMPRIMIR LISTA");           // done
    printf("\n\t 10. IMPRIMIR FILA");           // done
    printf("\n\t 11. IMPRIMIR PILHA");          // done
    printf("\n\t 12. DIVIDIR ELEMENTOS PILHA"); // done
    printf("\n\t 13. CONCATENAR DUAS FILAS");   // done
    printf("\n\t 14. SAIR");                    // done
}

int main()
{
    // Declaracao de variaveis:
    TPilha pilha;
    TFila fila;
    TLista lista;
    TProduto item;

    // Inicialização da fila
    FPVazia(&pilha);
    FLVazia(&lista);
    FFVazia(&fila);

    int opcao = 0;
    do
    {
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
            Inserir(item, &lista);
            system("PAUSE");
            break;

        case 2:
            system("cls");
            LerProduto(&item);
            Enfileirar(item, &fila);
            system("PAUSE");
            break;

        case 3:
            system("cls");
            LerProduto(&item);
            Empilhar(item, &pilha);
            system("PAUSE");
            break;

        case 4:
            system("cls");
            ImprimirPilha(&pilha);
            TFila laux;
            FFVazia(&laux);
            if (PVazia(pilha))
                printf("Pilha vazia.");
            while (!PVazia(pilha))
            {
                Desempilhar(&pilha, &item);
                Enfileirar(item, &laux);
            }
            while (!FVazia(laux))
            {
                Desenfileirar(&laux, &item);
                Empilhar(item, &pilha);
            }
            free(laux.frente);
            ImprimirPilha(&pilha);

            system("PAUSE");
            break;

        case 5:
            system("cls");
            ImprimirFila(fila);
            TPilha paux;
            FPVazia(&paux);
            while (!FVazia(fila))
            {
                Desenfileirar(&fila, &item);
                Empilhar(item, &paux);
            }
            while (!PVazia(paux))
            {
                Desempilhar(&paux, &item);
                Enfileirar(item, &fila);
            }
            free(paux.topo);
            ImprimirFila(fila);

            system("PAUSE");
            break;

        case 6:
            system("cls");
            ImprimirLista(lista);
            TPilha paux6;
            FPVazia(&paux6);
            while (!LVazia(lista))
            {
                Excluir(&lista, &item);
                Empilhar(item, &paux6);
            }
            while (!PVazia(paux6))
            {
                Desempilhar(&paux6, &item);
                Inserir(item, &lista);
            }
            free(paux6.topo);
            ImprimirLista(lista);
            system("PAUSE");
            break;

        case 7:
            system("cls");
            printf("Qual elemento deseja retirar da Fila? \n");
            fflush(stdin);
            scanf("%d", &item.codigo);
            if (PesquisarFila(fila, item) == 1)
            {
                Desenfileirar(&fila, &item);
                printf("\nProduto desenfileirado com sucesso\n");
            }
            else
                printf("\nProduto nao encontrado.\n");

            system("PAUSE");
            break;

        case 8:
            system("cls");
            printf("Qual elemento deseja retirar da Pilha? \n");
            fflush(stdin);
            scanf("%d", &item.codigo);
            if (PesquisarPilha(pilha, item) == 1)
            {
                Desempilhar(&pilha, &item);
                printf("\nProduto desenfileirado com sucesso\n");
            }
            else
                printf("\nProduto nao encontrado.\n");
            system("PAUSE");
            break;

        case 9:
            system("cls");
            ImprimirLista(lista);
            system("PAUSE");
            break;

        case 10:
            system("cls");
            ImprimirFila(fila);
            system("PAUSE");
            break;

        case 11:
            system("cls");
            ImprimirPilha(&pilha);
            system("PAUSE");
            break;

        case 12:
            system("cls");
            TPilha paux2;
            TPilha paux1;
            FPVazia(&paux1);
            FPVazia(&paux2);
            while ((!PVazia(pilha)))
            {
                Desempilhar(&pilha, &item);
                if ((item.codigo % 2) == 0)
                    Empilhar(item, &paux1);
                else
                    Empilhar(item, &paux2);
            }

            printf("\n\tPILHA AUXILIAR 1: \n");
            ImprimirPilha(&paux1);
            printf("\n\tPILHA AUXILIAR 2: \n");
            ImprimirPilha(&paux2);
            system("PAUSE");
            break;

        case 13:
            system("cls");
            TFila FilaAux1, FilaAux2, FilaAux3;
            FFVazia(&FilaAux1);
            FFVazia(&FilaAux2);
            FFVazia(&FilaAux3);
            int n;
            printf("Quantos elementos voce deseja enfileirar: ");
            fflush(stdin);
            scanf("%i", &n);
            printf("\n\t******INSIRA OS ELEMENTOS DA FILA AUXILIAR 1:");
            for (int i = 0; i < n; i++)
            {
                LerProduto(&item);
                Enfileirar(item, &FilaAux1);
            }

            printf("\n\t******INSIRA OS ELEMENTOS DA FILA AUXILIAR 2:");
            for (int j = 0; j < n; j++)
            {
                LerProduto(&item);
                Enfileirar(item, &FilaAux2);
            }

            while (!FVazia(FilaAux1))
            {
                Desenfileirar(&FilaAux1, &item);
                Enfileirar(item, &FilaAux3);
            }

            while (!FVazia(FilaAux2))
            {
                Desenfileirar(&FilaAux2, &item);
                Enfileirar(item, &FilaAux3);
            }
            system("cls");
            printf("FILAS CONCATENADAS:");
            LiberarFila(&FilaAux2);
            LiberarFila(&FilaAux1);
            ImprimirFila(FilaAux3);
            LiberarFila(&FilaAux3);
            system("PAUSE");
            break;

        case 14:
            system("cls");
            system("PAUSE");
            break;

        default:
            system("cls");
            printf("\n\n>>>>>>>>>>>>>>>>>>>>>>>>> MSG: DIGITE UMA OPCAO VALIDA! <<<<<<<<<<<<<<<<<<<<<<<\n\n");
            system("PAUSE");
            break;
        }
    } while (opcao != 14);

    LiberarPilha(&pilha);
    LiberarFila(&fila);
    LiberarLista(&lista);
    return 0;
}