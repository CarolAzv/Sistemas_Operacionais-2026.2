#include <stdio.h>
#include <string.h>

// function to copy contents from source to destination
int copy_file(const char* source, const char* destination) {
    FILE *src = fopen(source, "rb");
    if (src == NULL) {
        printf("Unable to open source file %s\n", source);
        return 1;
    }

    FILE *dst = fopen(destination, "wb");
    if (dst == NULL) {
        printf("Unable to open destination file %s\n", destination);
        fclose(src);
        return 1;
    }

    // Read from source and write to destination, in chunks
    char buffer[4096];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, bytes_read, dst);
    }

    // Close both files
    fclose(src);
    fclose(dst);

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

    // calling function to copy file
    if (copy_file(argv[1], argv[2]) != 0) {
        return 1;
    }

    printf("Copied '%s' to '%s'\n", argv[1], argv[2]);

    return 0;
}