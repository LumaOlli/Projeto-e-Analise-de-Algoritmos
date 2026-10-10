#include <stdio.h>
#include <signal.h> // Biblioteca necessária para a função raise()

/*
Comando de compilação: gcc -Wall -O0 sigill_raise.c -o sigill_raise && ./sigill_raise
Hipótese: Chamando raise(SIGILL), o programa sinalizará a ocorrência de uma instrução ilegal sem precisar manipular opcodes inválidos ou permissões da pilha.
Resultado Observado: Illegal instruction (core dumped) (Código de saída: 132).
Explicação Técnica: O método raise(SIGILL) envia o sinal de instrução ilegal por software. A CPU não chega a tentar decodificar opcodes indefinidos (como UD2); o sinal é entregue diretamente pelo Kernel.
Simulação via raise(): Esta é a implementação direta da simulação via software.
*/

int main(void) {

    // Envia o sinal SIGILL diretamente ao processo atual
    raise(SIGILL);

    // Linha inalcançável
    printf("Execução concluída com sucesso.\n");
    return 0;
}