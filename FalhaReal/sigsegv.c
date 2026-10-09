#include <stdio.h>   
#include <stdlib.h>  

/*
Comando de compilação: gcc -o sigsegv sigsegv.c && ./sigsegv
Hipótese: A escrita repetida a partir de um ponteiro já liberado (dangling pointer) ultrapassará o espaço do processo e acessará uma página de memória não mapeada, gerando um erro de segmentação.
Resultado Observado: Segmentation fault (core dumped) (Código de saída: 139).
Explicação Técnica: Ao tentar alterar uma posição de memória desalocada ou fora da tabela de páginas do processo, a MMU (Memory Management Unit) detecta a violação de acesso e o Kernel do Linux envia o sinal SIGSEGV.
Simulação via raise(): raise(SIGSEGV); apenas envia a notificação do sinal ao processo sem efetuar nenhuma tentativa real de acesso à memória.
*/

int main(void) {
    // Aloca dinamicamente na memória Heap um bloco suficiente para armazenar 10 números inteiros
    int *array = (int *)malloc(10 * sizeof(int));

    // Verifica se a alocação falhou (se o sistema não conseguiu reservar a memória, malloc retorna NULL)
    if (array == NULL) return 1;

    // Atribui o valor 100 à primeira posição da memória recém-alocada
    array[0] = 100;

    // Libera o bloco de memória de volta para o sistema operacional
    // A partir deste ponto, o ponteiro 'array' torna-se um "dangling pointer" (aponta para memória inviabilizada)
    free(array);

    // Tenta acessar e escrever em 100.000 posições a partir do ponteiro que já foi liberado
    for (int i = 0; i < 100000; i++) {
        array[i] = i; // Tenta escrever na memória desalocada
    }

    return 0; // Finalização normal (esta linha nunca será alcançada devido à falha)
}