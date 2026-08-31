#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>

//chamada de sistema para criar uma pasta
int make_pasta(const char* pastanome) {
    // 0755 = permissões: dono lê/escreve/executa, grupo e outros só leem/executam
    if (mkdir(pastanome, 0755) != 0) {
        perror("Erro criando a pasta");
        return 1;
    }
    return 0;
}

//código de chamada
int main(int argc, char* argv[])
{
    //checa se o nome da pasta foi dado
    if (argc != 2) {
        printf("Usage: %s pastanome\n", argv[0]);
        return 1;
    }

    //chama da função para criar a pasta
    if (make_pasta(argv[1]) != 0) {
        return 1;
    }

    printf("Pasta criada '%s'\n", argv[1]);

    return 0;
}