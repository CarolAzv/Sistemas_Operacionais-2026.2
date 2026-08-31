#include <stdio.h>
#include <string.h>

// function to remove a file
int remove_file(const char* filename) {
    if (remove(filename) != 0) {
        perror("Error removing file");
        return 1;
    }
    return 0;
}

// driver code
int main(int argc, char* argv[])
{
    // Check if filename was given
    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }

    // calling function to remove file
    if (remove_file(argv[1]) != 0) {
        return 1;
    }

    printf("Removed '%s'\n", argv[1]);

    return 0;
}