#include <stdio.h>
#include <time.h>
#include <string.h>

// function to print the current date and time
void print_date(void) {
    time_t now = time(NULL);
    if (now == (time_t)-1) {
        printf("Unable to get current time\n");
        return;
    }

    // Convert to local time
    struct tm *local_time = localtime(&now);
    if (local_time == NULL) {
        printf("Unable to convert time\n");
        return;
    }

    // Format like: Mon Aug 31 14:32:07 2026
    char buffer[64];
    strftime(buffer, sizeof(buffer), "%a %b %d %H:%M:%S %Y", local_time);

    printf("%s\n", buffer);
}

// driver code
int main(int argc, char* argv[])
{
    // date real aceita formatos customizados (ex: +%Y-%m-%d), mas aqui
    // ignoramos argumentos e sempre imprimimos o formato padrão
    print_date();

    return 0;
}