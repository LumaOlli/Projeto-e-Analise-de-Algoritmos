#include <stdio.h>
#include <signal.h> 

int main(void) {

    raise(SIGILL);

    printf("Execução concluída com sucesso.\n");
    return 0;
}