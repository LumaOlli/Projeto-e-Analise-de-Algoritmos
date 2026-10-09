#include <stdio.h>
#include <signal.h> 

/*
Comando de compilação: gcc -Wall -O0 sigabrt_raise.c -o sigabrt_raise && ./sigabrt_raise
Hipótese: A invocação manual de raise(SIGABRT) solicitará o aborto imediato do processo, gerando a mensagem de encerramento Aborted de forma direta.
Resultado Observado: Aborted (core dumped) (Código de saída: 134).
Explicação Técnica: A função raise(SIGABRT) envia o sinal de aborto ao processo atual. Diferente do assert, o raise() dispara o sinal sem imprimir dados de diagnóstico no stderr (como linha ou arquivo).
Simulação via raise(): Esta é a implementação direta da simulação via software.
*/

int main(void) {
    
    // Envia o sinal SIGABRT diretamente ao processo atual
    raise(SIGABRT);

    // Linha inalcançável
    printf("Execução concluída com sucesso.\n");
    return 0;
}