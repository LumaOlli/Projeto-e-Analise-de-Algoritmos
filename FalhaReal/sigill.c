#include <stdio.h>

/*
Comando de compilação: gcc -Wall -O0 -z execstack sigill.c -o sigill && ./sigill
Hipótese: O desvio do ponteiro de instrução da CPU (RIP/EIP) para um vetor de bytes contendo a sequência 0x0F 0x0B fará o decodificador do processador rejeitar a instrução por ser ilegal/indefinida.
Resultado Observado: Illegal instruction (core dumped) (Código de saída: 132).
Explicação Técnica: Os bytes 0x0F 0x0B correspondem à instrução UD2 (Undefined Instruction) nas arquiteturas x86/x64. Ao tentar decodificá-los, a CPU dispara uma exceção #UD, e o Kernel do Linux repassa o sinal SIGILL ao programa.
Simulação via raise(): raise(SIGILL); notifica o processo sobre o recebimento do sinal sem forçar a CPU a decodificar opcodes inválidos na memória.
*/

// Define um tipo de ponteiro para uma função sem parâmetros e sem retorno
typedef void (*FuncaoInvalida)(void);

int main(void) {
    printf("Iniciando execução do programa...\n");
    printf("Tentando executar uma instrução de máquina inválida...\n");

    // Sequência de bytes que não forma uma instrução válida de processador (opcode ilegal)
    unsigned char codigo_ilegal[] = { 0x0F, 0x0B }; // Instrução 'UD2' (Undefined Instruction em x86/x64)

    // Converte o ponteiro do vetor de dados para um ponteiro de função executável
    FuncaoInvalida executar = (FuncaoInvalida)codigo_ilegal;

    // O QUE NÃO QUEREMOS QUE ACONTEÇA EM UM SISTEMA REAL:
    // Tenta saltar o ponteiro de instrução da CPU (RIP/EIP) para os bytes inválidos
    executar();

    // Linha inalcançável
    printf("Execução concluída com sucesso.\n");
    return 0;
}