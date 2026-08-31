Seguindo o mesmo estilo, um mkdir básico usa a função mkdir() de sys/stat.h (em sistemas POSIX/Linux):

c
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>

// function to create a directory
int make_directory(const char* dirname) {
    // 0755 = permissões: dono lê/escreve/executa, grupo e outros só leem/executam
    if (mkdir(dirname, 0755) != 0) {
        perror("Error creating directory");
        return 1;
    }
    return 0;
}

// driver code
int main(int argc, char* argv[])
{
    // Check if directory name was given
    if (argc != 2) {
        printf("Usage: %s dirname\n", argv[0]);
        return 1;
    }

    // calling function to create directory
    if (make_directory(argv[1]) != 0) {
        return 1;
    }

    printf("Created directory '%s'\n", argv[1]);

    return 0;
}