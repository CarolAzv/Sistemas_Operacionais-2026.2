#include <stdio.h>
#include <time.h>
#include <string.h>
#include <locale.h>

//chamado de sistema para imprimir o tempo e a data atual
void print_data(void) {
    if (setlocale(LC_TIME, "pt_BR.UTF-8") == NULL &&
        setlocale(LC_TIME, "pt_BR.utf8") == NULL &&
        setlocale(LC_TIME, "pt_PT.UTF-8") == NULL &&
        setlocale(LC_TIME, "pt_PT.utf8") == NULL) {
        setlocale(LC_TIME, "");
    }

    time_t now = time(NULL);
    if (now == (time_t)-1) {
        printf("Não foi possível pegar o tempo atual\n");
        return;
    }

    // Convert to local time
    struct tm *local_time = localtime(&now);
    if (local_time == NULL) {
        printf("Não foi possível converter o horário\n");
        return;
    }

    //formato: 31/08/2026 14:32:07
    char bufer[64];
    strftime(bufer, sizeof(bufer), "%d/%m/%Y %H:%M:%S", local_time);

    printf("%s\n", bufer);
}

// driver code
int main(int argc, char* argv[])
{
    //impressão da data no formato padrão
    print_data();

    return 0;
}