#include <stdio.h>
#include <stdlib.h>
#include "cliente_struct.c"
#include <time.h>

int main(){
    printf("------- Algoritmos de ordenacao -------\n\n");
    int choice, tamanho;
    char caminho[1024];

    printf("Informe o nome do arquivo csv: (ex.: dados1000decrescente.csv) ");
    scanf("%s", &caminho);
    printf("Informe o tamanho desse csv: ");
    scanf("%d", &tamanho);

    Cliente *clientes = read_csv(caminho, tamanho);

    printf("\nEsse são os 10 primeiros clientes do arquivo escolhido:\n");
    print_clientes(clientes, 10);

    while(choice < 1 || choice > 5){
        printf("Escolha uma opcao:\n\n");
        printf("1 - Insertion sort\n");
        printf("2 - Selection sort\n");
        printf("3 - Shell sort\n");
        printf("4 - Quick sort\n");
        printf("5 - Merge sort\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nInsertion sort\n");
                insertion_sort(clientes, tamanho);
                break;
            case 2:
                printf("\nSelection sort\n");
                selection_sort(clientes, tamanho);
                break;
            case 3:
                printf("\nShell sort\n");
                shell_sort(clientes, tamanho);
                break;
            case 4:
                printf("\nQuick sort\n");
                trocas_quick = 0;
                comparacoes_quick = 0;
                double tempo_quick = 0.0;
                clock_t inicio_quick = clock();
                quick_sort(clientes, 0, tamanho-1);
                clock_t fim_quick = clock();
                tempo_quick += (double) (fim_quick - inicio_quick) / CLOCKS_PER_SEC;
                printf("Trocas: %d, Comparacoes: %d, Tempo: %f", trocas_quick, comparacoes_quick, tempo_quick);

                break;
            case 5:
                printf("\nMerge sort\n");
                comparacoes_merge = 0;
                double tempo_merge = 0.0;
                clock_t inicio_merge = clock();
                merge_sort(clientes, 0, tamanho-1);
                clock_t fim_merge = clock();
                tempo_merge += (double) (fim_merge - inicio_merge) / CLOCKS_PER_SEC;
                printf("Comparacoes: %d, Tempo: %f\n", comparacoes_merge, tempo_merge);
                break;
            default:
                printf("Opcao invalida\n\n");
        }
    }

    char resp;

    printf("\n\nVoce deseja fazer alguma busca? [s/n]\n");

    while(scanf(" %c", &resp) && resp == 's'){
        int meto_busc;


        printf("\n\nQual metodo de busca voce quer usar?\n");
        printf("1 - Busca sequencial\n");
        printf("2 - Busca binaria\n");

        scanf("%d", &meto_busc);

        switch(meto_busc){
            case 1:
                printf("\nBusca sequencial");
                sequencial_search(clientes, tamanho);
                break;
            case 2:
                printf("\nBusca binaria");
                int chave;
                printf("\n\nQual cliente voce procura: ");
                scanf("%d", &chave);
                buscaBinaria(clientes, chave, 0, tamanho);
                break;
            default:
                printf("Opcao  invalida\n");
        }
        printf("Continuar?");
    }

    printf("\nFim do programa.");


    return 0;
}
