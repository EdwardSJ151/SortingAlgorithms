#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
    int chave;
    char nome[20];
    char profissao[50];
    int idade;
} Cliente;


void print_clientes(Cliente *clientes, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d, %s, %s, %d",
               clientes[i].chave,
               clientes[i].nome,
               clientes[i].profissao,
               clientes[i].idade);
        printf("\n");
    }
}

Cliente *read_csv(char caminho[1024], int tamanho)
{
    FILE *arquivo = fopen(caminho, "r");

    if (arquivo == NULL)
    {
        printf("Erro abrindo arquivo.\n");
        exit(1);
    }


    Cliente *clientes = (Cliente*)malloc(tamanho*sizeof(Cliente));

    int read = 0;
    int records = 0;

    char buffer[1024];
    fgets(buffer, 1024, arquivo); // pular primeira linha
    do
    {

        read = fscanf(arquivo, "%d;%19[^;];%49[^;];%d\n",
                      &clientes[records].chave, clientes[records].nome,
                      clientes[records].profissao, &clientes[records].idade);
        if (read == 4) records ++;

        if (read != 4 && !feof(arquivo))
        {
            printf("Formato do arquivo incorreto.\n");
            exit(1);
        }
        if (ferror(arquivo))
        {
            printf("Erro lendo arquivo.\n");
            exit(1);
        }
    }
    while(!feof(arquivo));

    fclose(arquivo);

    return clientes;
}

void insertion_sort(Cliente *clientes, int tamanho)
{
    int i, j;
    Cliente aux;
    int trocas = 0;
    int comparacoes = 0;
    double tempo = 0.0;

    clock_t begin = clock();
    for (i = 1; i < tamanho; i++){
        aux = clientes[i];
        j = i - 1;

        while (j >= 0 && clientes[j].chave > aux.chave){
            clientes[j + 1] = clientes[j];
            j--;
            comparacoes++;
        }

        if (aux.chave != clientes[i].chave){
            clientes[j+1] = aux;
            trocas++;
        }
    }
    clock_t end = clock();
    tempo += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nTrocas: %d\nComparacoes: %d\nTempo: %f", trocas, comparacoes, tempo);

}

void selection_sort(Cliente *clientes, int tamanho)
{
    int i, j, min;
    Cliente aux;
    int trocas = 0;
    int comparacoes = 0;
    double tempo = 0.0;

    clock_t begin = clock();
    for (i = 0; i < tamanho - 1; i++)
    {
        min = i;
        for (j = i + 1; j < tamanho; j++)
        {
            comparacoes++;
            if (clientes[min].chave > clientes[j].chave)
            {
                min = j;
            }
        }
        if (min != i)
        {
            aux = clientes[i];
            clientes[i] = clientes[min];
            clientes[min] = aux;
            trocas++;
        }
    }
    clock_t end = clock();
    tempo += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nTrocas: %d\nComparacoes: %d\nTempo: %f", trocas, comparacoes, tempo);
}

void shell_sort(Cliente *clientes, int tamanho)
{
    int i, j, salto;
    Cliente aux;
    salto = 1;

    int comparacoes = 0;
    int trocas = 0;
    double tempo = 0.0;

    clock_t begin = clock();
    while (salto < tamanho){
        salto = 3 * salto + 1;

    }
    while (salto > 1){
        salto /=3;

        for (i=salto; i<tamanho; i++){
            aux = clientes[i];
            j = i - salto;
            while (j>=0 && aux.chave < clientes[j].chave){
                clientes[j + salto] = clientes[j];

                j -= salto;
                comparacoes ++;
            }
            clientes[j+salto] = aux;
            trocas++;
        }
    }
    clock_t end = clock();
    tempo += (double)(end - begin) / CLOCKS_PER_SEC;

    printf("\nTrocas: %d\nComparacoes: %d\nTempo: %f", trocas, comparacoes, tempo);

}

int trocas_quick, comparacoes_quick;

int particao(Cliente *clientes, int Esq, int Dir)
{
    Cliente pivo, aux;
    pivo = clientes[Dir];
    int i = Esq;

    for (int j = Esq; j <= Dir-1; j++){
        comparacoes_quick++;
        if (clientes[j].chave <= pivo.chave){
            aux = clientes[i];
            clientes[i] = clientes[j];
            clientes[j] = aux;
            trocas_quick++;
            i++;
        }
    }
    aux = clientes[i];
    clientes[i] = clientes[Dir];
    clientes[Dir] = aux;
    trocas_quick++;

    return (i);
}

void quick_sort(Cliente *clientes, int Esq, int Dir)
{
    if (Esq < Dir){
        int index = particao(clientes, Esq, Dir);
        quick_sort(clientes, Esq, index-1);
        quick_sort(clientes, index+1, Dir);
    }
}

int comparacoes_merge;

void merge(Cliente *clientes, int Esq, int Meio, int Dir)
{
    Cliente *clientes_auxiliar = (Cliente*)malloc((Dir+1)*sizeof(Cliente));
    int i = Esq, j = Meio+1, k = 0;

    while (i <= Meio && j <= Dir){
        if(clientes[i].chave <= clientes[j].chave)
            clientes_auxiliar[k++] = clientes[i++];
        else{
            clientes_auxiliar[k++] = clientes[j++];
        }
        comparacoes_merge++;
    }

    while (i<=Meio){
        clientes_auxiliar[k++] = clientes[i++];
        comparacoes_merge++;
    }
    while (j<=Dir){
        clientes_auxiliar[k++] = clientes[j++];
        comparacoes_merge++;
    }

    for (i = Esq, k = 0; i<=Dir; i++, k++){
        clientes[i] = clientes_auxiliar[k];
    }
}

void merge_sort(Cliente *clientes, int Esq, int Dir)
{
    int Meio;
    if (Esq == Dir)
        return;
    else{
        Meio = (Esq+Dir)/2;
        merge_sort(clientes, Esq, Meio);
        merge_sort(clientes, Meio+1, Dir);

        merge(clientes, Esq, Meio, Dir);
    }
}

void sequencial_search(Cliente *clientes, int tamanho)
{
    int i, key, success; // key is number to be searched
    printf("\n\nQual cliente voce procura: :" );
    scanf("%d", &key);
    for( i =0; i< tamanho - 1; i++)
        if( clientes[i].chave == key){
            //printf("\nYes, it is in Array. Array[%d]=%d\n\n", i, clientes[i].chave);
            success = 1;
            printf("\n\nID: %d, Nome: %s, Profissao: %s, Idade: %d",
            clientes[i].chave,
            clientes[i].nome,
            clientes[i].profissao,
            clientes[i].idade);
            printf("\nComparacoes: %d", i+1);
        printf("\n");
    }
    if(i == tamanho - 1 && success != 1){
        printf("The number is not in Array.\n\n");
    }
    return 0;
}

int comparacoesBinaria = 0;

void buscaBinaria(Cliente *clientes, int chave, int inicio, int fim){
    int meio;

    if(inicio <= fim){
        meio = (inicio + fim)/2;
        comparacoesBinaria++;
        if(chave == clientes[meio].chave){
            printf("\n\nID: %d, Nome: %s, Profissao: %s, Idade: %d",clientes[chave-1].chave,clientes[chave-1].nome,clientes[chave-1].profissao,clientes[chave-1].idade);
            printf("\n\nComparisions: %d.\n\n", comparacoesBinaria);
            return meio;
        }
        else{
            if(chave < clientes[meio].chave)
                return buscaBinaria(clientes, chave, inicio, meio -1);
            else
                return buscaBinaria(clientes, chave, meio + 1, fim);
        }
    }
    printf("The number is not in Array.\n\n");
    printf("Comparisions: %d.\n\n", comparacoesBinaria);
    return -1;
}


