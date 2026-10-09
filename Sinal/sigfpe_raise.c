
#include <stdio.h>
#include <signal.h>

/*
Comando de compilação: gcc -Wall -O0 sigfpe_raise.c -o sigfpe_raise && ./sigfpe_raise
Hipótese: A chamada de raise(SIGFPE) simulará uma exceção aritmética de ponto flutuante/divisão por zero sem depender de uma operação inválida na ALU.
Resultado Observado: Floating point exception (core dumped) (Código de saída: 136).
Explicação Técnica: A função raise(SIGFPE) gera uma interrupção por software que faz o Kernel entregar o sinal SIGFPE ao processo. O resultado visual e o código de saída no Linux são idênticos aos de uma divisão por zero real.
Simulação via raise(): Esta é a implementação direta da simulação via software.
*/

int main(void) {

    // Envia o sinal SIGFPE diretamente ao processo atual
    raise(SIGFPE);

    // Linha inalcançável
    printf("Execução concluída com sucesso.\n");
    return 0;
}