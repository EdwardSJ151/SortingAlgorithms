# SortingAlgorithms
#### Sorting and Search algorithm report (in portuguese)

Introdução
	O propósito do seguinte trabalho foi testar 5 algoritmos de ordenação (Insertion, Selection, Shell, Quick e Merge Sorts) em diferentes datasets, a fim de entender suas diferenças, semelhanças, vantagens e desvantagens. Ademais, objetivou-se utilizar algoritmos de busca sequencial e binária, e a criação de uma interface (menu), para, respectivamente, recuperar informações do conjuntos de dados e facilitar o acesso aos algoritmos.
Métodos de Ordenação
Algoritmos de ordenação são códigos com objetivo de colocar uma certa sequência em uma ordem específica. No caso deste trabalho foi utilizado uma lista com valores: ID, Nome, Profissão e Idade. A ordenação foi de ordem crescente utilizando o ID informado.
InsertionSort 
	A ordenação por inserção compara um item i, iniciando pelo segundo item do struct, com todos os seguintes. Enquanto o item anterior a i, j, for maior ou igual a 0 e seu valor for maior que o valor de i, andaremos uma casa com j. Se ao final das comparações, o valor de i for diferente do valor inicial do loop, irá trocar.
	Esse algoritmo mostrou não precisar de comparações nem trocas quando a lista já está crescente (C(n) = O(n)). Ele possui um caso médio quando os dados são aleatórios (C(n) = O(n^2), M(n) = O(n^2)) e o pior caso quando são decrescentes (C(n) = O(n^2), M(n) = O(n^2).  Por fim, destaca-se que o InsertionSort é estável.

SelectionSort
  Esse algoritmo irá iniciar com item i, posição 0, e enquanto i for menor que o tamanho da lista - 1, irá considerar i como o valor mínimo, sendo j inicialmente igual a i e percorrendo o caminho até o fim da lista. Caso j seja menor que o mínimo, j será o novo mínimo e no final do loop; se i for diferente do mínimo, o mínimo assumirá a posição de i e i a posição do mínimo.
O número de comparações sempre será o mesmo independente da ordem inicial da lista, havendo variações apenas no número de trocas. Assim, nota-se que esse método não é o melhor indicado para uma grande quantidade de dados. O método não é estável e sua complexidade é C(n) = O(n2), M(n) = O(n).
ShellSort
O ShellSort é um algoritmo de ordenação que age como se fosse uma versão "avançada" do InsertionSort. Ele funciona por meio da escolha de pares de números, que são separados por um intervalo, o que seria um determinado valor que separa esse par de valores dentro do vetor, uma antes do intervalo e um depois do intervalo. Depois, o algoritmo faz um InsertionSort nesse par e posteriormente repete o processo, porém toda vez que ele for repetir, ele divide esse intervalo por 2. Esse intervalo é comumente determinado pela fórmula de Knuth, em que: h = h * 3 + 1, em que h é o intervalo com um valor inicial 1. A complexidade desse algoritmo para a sequência de Knuth em média é C(n) = O(n^1,25). No melhor caso ele é O(nlogn) e no pior caso ele é O(n^2). O ShellSort é especialmente bom quando os menores números estão mais para a direita do vetor, considerando que a ordenação é em ordem crescente. Shell Sort não é estável.

Quick Sort
  O QuickSort é um dos métodos mais comuns de ordenação atualmente. No projeto, código é separado em duas funções, “partição” e "quick_sort". A função de partição irá, como o nome diz, partir a lista a partir de um pivô, e através da “Esq” e “Dir” irá comparar o valor de “Esq” com o item que foi escolhido para partição, e incrementar a cada comparação. Caso a próxima comparação apresente um valor menor que o valor do item de partição, irá trocar esse item menor com o item “Esq”. O processo é repetido quantas vezes necessárias através da função “quick_sort”.
Como esse método divide listas grandes em menores, é o mais recomendado para grande quantidade de dados, mas não apresenta diferença em comparação e trocas mesmo se a estrutura de dados estiver ordenada crescentemente. O melhor caso é C(n) = nlogn (partições divididas em duas partes iguais), e pior caso caso Cn= O(n^2) (pivôs escolhidos, de maneira sistemática, como um dos extremos de um arquivo já ordenado). QuickSort não é estável.

MergeSort
  Utilizando também o princípio de dividir para conquistar, o Merge divide de modo equilibrado (meio) o vetor até encontrar em n partes menores de tamanho 1. Ele ordenará cada subparte separadamente e depois as unirá. Há recursividade no processo até que todo vetor esteja ordenado. A complexidade do Merge, C(n) = (nlogn), é a mesma para todos os casos (pior, médio e melhor). Entre os algoritmos de ordenação eficiente, ele é o mais lento por utilizar vetor auxiliar. O método também não é estável.

Métodos de Busca

Busca Sequencial 
	O algoritmo de busca sequencial é consideravelmente simples. Em um vetor o algoritmo vai de valor em valor na sequência até ele achar o valor que ele estava procurando (chave). Essa busca é útil com uma quantidade muito pequena de dados, mas logo vai ficar menos eficiente por causa da sua complexidade O(n).

Busca Binária
	Considerando a lista ordenada, verificamos, inicialmente, se o valor buscado é o mesmo do meio da lista. Se sim, encontramos o valor buscado; se não, iremos repetir o processo. Ao repetir, é necessário analisar se o valor do meio anteriormente encontrado é maior ou menor a chave: se menor, início passará a ser meio+1; se maior, fim passará a ser meio-1. A busca binária é indicada para listas ordenadas.

Ferramenta Desenvolvida
	A ferramenta iniciará com um pedido para informar o nome do documento csv, por exemplo “dados1000aleatorio.csv”. É possível inserir o caminho do documento no computador caso o documento não esteja dentro da pasta, assim como o tamanho desse documento. O usuário pode digitar um número correspondente a determinado método de ordenação e o arquivo será ordenado. Se desejado há a opção de busca, binária ou sequencial. O código irá num loop até o usuário decidir não buscar nenhum cliente.

