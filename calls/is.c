Para o ls, usamos opendir()/readdir()/closedir() de dirent.h, que servem pra percorrer o conteúdo de um diretório (parecido com como o cat.c percorre um arquivo):

c
#include <stdio.h>
#include <dirent.h>
#include <string.h>

// function to list contents of a directory
int list_directory(const char* dirname) {
    DIR *dir = opendir(dirname);
    if (dir == NULL) {
        perror("Unable to open directory");
        return 1;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // skip "." and ".." como o ls faz por padrão
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        printf("%s\n", entry->d_name);
    }

    // Close the directory
    closedir(dir);

    return 0;
}

// driver code
int main(int argc, char* argv[])
{
    // se não passar argumento, usa o diretório atual "."
    const char* dirname = (argc >= 2) ? argv[1] : ".";

    // calling function to list directory
    if (list_directory(dirname) != 0) {
        return 1;
    }

    return 0;
}