#include <stdio.h>
#include <string.h>

//chamado do sistema para remover um arquivo
int remove_arquivo(const char* arquivonome) {
    if (remove(arquivonome) != 0) {
        perror("Erro removendo o arquivo");
        return 1;
    }
    return 0;
}

//código de chamada
int main(int argc, char* argv[])
{
    //checa se o nome do arquivo foi dado
    if (argc != 2) {
        printf("Usage: %s arquivonome\n", argv[0]);
        return 1;
    }

    //chama a função para remover o arquivo
    if (remove_arquivo(argv[1]) != 0) {
        return 1;
    }

    printf("Removido '%s'\n", argv[1]);

    return 0;
}