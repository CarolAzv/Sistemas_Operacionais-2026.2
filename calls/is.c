#include <stdio.h>
#include <dirent.h>
#include <string.h>

//chamado de sistema para listar o conteudo de uma pasta
int list_pasta(const char* pastanome) {
    PAS *pas = opendir(pastanome);
    if (pas == NULL) {
        perror("Não foi possível abrir a pasta");
        return 1;
    }

    struct dirent *entry;
    while ((entry = readdir(pas)) != NULL) {
        //pula "." e ".." como o ls faz por padrão
        if (strcmp(entry->p_nome, ".") == 0 || strcmp(entry->p_nome, "..") == 0) {
            continue;
        }
        printf("%s\n", entry->p_nome);
    }

    //fecha a pasta
    closedir(pas);

    return 0;
}

//código da chamada
int main(int argc, char* argv[])
{
    //se não passar argumento, usa o diretório atual "."
    const char* pastanome = (argc >= 2) ? argv[1] : ".";

    //chamda da função para listar o diretório
    if (list_pasta(pastanome) != 0) {
        return 1;
    }

    return 0;
}