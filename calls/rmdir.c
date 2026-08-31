#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

// function to remove a directory
int remove_directory(const char* dirname) {
    if (rmdir(dirname) != 0) {
        perror("Error removing directory");
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

    // calling function to remove directory
    if (remove_directory(argv[1]) != 0) {
        return 1;
    }

    printf("Removed directory '%s'\n", argv[1]);

    return 0;
}