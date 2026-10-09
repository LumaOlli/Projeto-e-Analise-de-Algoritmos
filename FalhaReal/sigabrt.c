#include <stdio.h>
#include <string.h>
#include <assert.h>

/*
Comando de compilação: gcc -Wall -O0 sigabrt.c -o sigabrt && ./sigabrt
Hipótese: Ao passar uma string com tamanho maior ou igual a 8 caracteres, a validação de pré-condição da macro assert falhará e interromperá a execução do programa enviando SIGABRT.
Resultado Observado: Aborted (core dumped) (Código de saída: 134).
Explicação Técnica: A macro assert avalia a expressão strlen(texto) < 8. Como a condição resulta em falsa, o assert imprime a falha no stderr e invoca internamente a função abort(), que dispara o sinal SIGABRT.
Simulação via raise(): raise(SIGABRT); cancela a execução de forma idêntica à função abort(), mas sem imprimir as informações de linha, arquivo e expressão testada no stderr.
*/

void processar_dados(const char *texto) {
    // Validação de segurança de pré-condição:
    // Se o texto for maior do que o buffer suporta, o assert falha e dispara o SIGABRT limpo
    assert(strlen(texto) < 8);

    // Linha inalcançável se o assert falhar
    printf("Texto copiado: %s\n", texto);
}

int main(void) {
    processar_dados("Esta_string_e_muito_maior_que_o_buffer!");
    return 0;
}