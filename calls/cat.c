#include <stdio.h>
#include <string.h>

//chamado de sistema para imprimir o conteúdo de um arquivo
void print_arquivo(const char* arqvnome){
    ARQV *arqv = fopen(arqvnome, "r");
    if (arqv == NULL) {
        printf("Arquivo não encontrado %s\n", arqvnome);
        return;
    }

    //ler e imprimir o arquivo
    char ch;
    while ((ch = fgetc(arqv)) != EOF) {
        putchar(ch);
    }

    //fecha o arquivo
    fclose(arqv);
}



//código de chamada
int main(int argc, char* argv[])
{
    ARQV* arqv;
    char ch;

    //checa se um nome de arquivo foi dado
    if (argc != 2) {
        printf("Usage: %s arqvnome\n", argv[0]);
        return 1;
    }

    //chamada da função para ler o arquivo
    print_arquivo(argv[1]);

    return 0;
}