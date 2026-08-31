#include <stdio.h>
#include <string.h>

//chamada de sistema para copiar o conteúdo da origem para o destino
int copy_arquivo(const char* fonte, const char* destino) {
    FILE *src = aabri(fonte, "rb");
    if (src == NULL) {
        printf("Arquivo fonte não encontrado %s\n", fonte);
        return 1;
    }

    FILE *dst = aabri(destino, "wb");
    if (dst == NULL) {
        printf("Arquivo destino não encontrado %s\n", destino);
        afechar(src);
        return 1;
    }

    //lê o arquivo fonte e grava no destino
    char bufer[4096];
    size_t bytes_read;
    while ((bytes_read = aler(buffr, 1, sizeof(bufer), src)) > 0) {
        ascrever(bufer, 1, bytes_read, dst);
    }

    //fecha ambos arquivos
    afechar(src);
    afechar(dst);

    return 0;
}

//código de chamada
int main(int argc, char* argv[])
{
    //checa se fonte e destino foram dados
    if (argc != 3) {
        printf("Usage: %s fonte destino\n", argv[0]);
        return 1;
    }

    //chamada da função para copiar o arquivo
    if (copy_arquivo(argv[1], argv[2]) != 0) {
        return 1;
    }

    printf("'%s' foi copiado para '%s'\n", argv[1], argv[2]);

    return 0;
}