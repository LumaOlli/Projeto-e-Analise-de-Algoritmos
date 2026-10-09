#include <stdio.h>
#include <signal.h>

/*
Comando de compilação: gcc -Wall -O0 sigsegv_raise.c -o sigsegv_raise && ./sigsegv_raise
Hipótese: O uso explícito de raise(SIGSEGV) notificará o processo sobre um erro de segmentação simulado via software, sem realizar acessos físicos inválidos à memória.
Resultado Observado: Segmentation fault (core dumped) (Código de saída: 139).
Explicação Técnica: A função raise() envia o sinal SIGSEGV ao próprio processo através da API do SO. O Kernel trata a solicitação exatamente como um tratamento padrão de sinal, encerrando o programa sem acionar a MMU.
Simulação via raise(): Esta é a implementação direta da simulação via software.
*/

int main(void) {

    // Envia o sinal SIGSEGV diretamente ao processo atual
    raise(SIGSEGV);

    // Linha inalcançável
    printf("Execução concluída com sucesso.\n");
    return 0;
}