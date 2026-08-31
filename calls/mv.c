#include <stdio.h>
#include <string.h>

// function to move/rename a file
int move_file(const char* source, const char* destination) {
    if (rename(source, destination) != 0) {
        perror("Error moving file");
        return 1;
    }
    return 0;
}

// driver code
int main(int argc, char* argv[])
{
    // Check if source and destination were given
    if (argc != 3) {
        printf("Usage: %s source destination\n", argv[0]);
        return 1;
    }

    // calling function to move file
    if (move_file(argv[1], argv[2]) != 0) {
        return 1;
    }

    printf("Moved '%s' to '%s'\n", argv[1], argv[2]);

    return 0;
}