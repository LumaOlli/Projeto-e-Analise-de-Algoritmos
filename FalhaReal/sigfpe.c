#include <stdio.h> // Inclui a biblioteca padrão para uso da função printf()

/*
Comando de compilação: gcc -Wall -O0 sigfpe.c -o sigfpe && ./sigfpe
Hipótese: A tentativa de calcular a divisão inteira por zero provocará uma exceção de hardware na ALU do processador, resultando na interrupção do programa por exceção aritmética.
Resultado Observado: Floating point exception (core dumped) (Código de saída: 136).
Explicação Técnica: Durante a execução da instrução de montagem IDIV, o processador detecta o divisor nulo e gera a interrupção de hardware por erro de divisão (#DE). O SO intercepta a exceção e entrega o sinal SIGFPE ao processo.
Simulação via raise(): raise(SIGFPE); dispara diretamente a rotina do sinal via software, sem acionar a interrupção física da Unidade Lógica e Aritmética (ALU) do processador.
*/

int main(void) {
    int total_desconto = 150; // Valor total do desconto acumulado
    int total_itens = 0;      // Quantidade de itens (simula uma entrada zerada ou lista vazia)

    printf("Calculando o desconto médio por item...\n");

    // LINHA CRÍTICA (O QUE NÃO QUEREMOS):
    // A ALU do processador tenta efetuar a divisão inteira por 0 (instrução IDIV).
    // O hardware dispara uma exceção (#DE) e o Linux envia o sinal SIGFPE, encerrando o processo.
    int desconto_por_item = total_desconto / total_itens; 

    // As linhas abaixo ficam inalcançáveis porque o programa sofre um crash imediato na linha anterior
    printf("Desconto por item: R$ %d\n", desconto_por_item);

    return 0; // Finalização normal (nunca será alcançada)
}