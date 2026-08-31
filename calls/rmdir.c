#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

//chamada do sistema para remover uma pasta
int remove_pasta(const char* pastaname) {
    if (rmdir(pastaname) != 0) {
        perror("Erro removendo a pasta");
        return 1;
    }
    return 0;
}

// código de chamada
int main(int argc, char* argv[])
{
    //checa se o nome da pasta foi dado
    if (argc != 2) {
        printf("Usage: %s pastaname\n", argv[0]);
        return 1;
    }

    //chama a função para remover a pasta
    if (remove_pasta(argv[1]) != 0) {
        return 1;
    }

    printf("Pasta removida '%s'\n", argv[1]);

    return 0;
}