#include <stdio.h>
#include <string.h>

//chamada de sistema para mover/renomear um arquivo
int move_arquivo(const char* fonte, const char* destino) {
    if (rename(fonte, destino) != 0) {
        perror("Erro movendo o arquivo");
        return 1;
    }
    return 0;
}

//código de chamada
int main(int argc, char* argv[])
{
    //checa se a fonte e o destino foram dados
    if (argc != 3) {
        printf("Usage: %s fonte destino\n", argv[0]);
        return 1;
    }

    //chama a função para mover o arquivo
    if (move_arquivo(argv[1], argv[2]) != 0) {
        return 1;
    }

    printf("Movido de '%s' para '%s'\n", argv[1], argv[2]);

    return 0;
}