#include <stdio.h>
#include <stdlib.h>

void createFileIfNotExist(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("%s not found. Creating file and entering sample text...\n", filename);
        fp = fopen(filename, "w");
        if (!fp) {
            printf("Failed to create %s\n", filename);
            exit(1);
        }
        
        printf("Enter text for %s (end input with a single line containing only '.'): \n", filename);
        char line[256];
        while (1) {
            fgets(line, sizeof(line), stdin);
            if (line[0] == '.' && line[1] == '\n') break;
            fputs(line, fp);
        }
        fclose(fp);
    } else {
        fclose(fp); 
    }
}

void mergeFiles(const char *file1, const char *file2, const char *file3) {
    FILE *f1 = fopen(file1, "r");
    FILE *f2 = fopen(file2, "r");
    FILE *f3 = fopen(file3, "w");

    if (!f1 || !f2 || !f3) {
        printf("Error opening files!\n");
        return;
    }

    char ch;

    while ((ch = fgetc(f1)) != EOF) fputc(ch, f3);
    while ((ch = fgetc(f2)) != EOF) fputc(ch, f3);

    fclose(f1);
    fclose(f2);
    fclose(f3);

    printf("Files merged into %s\n", file3);
}

int main() {
    // Check and create files if not exist
    createFileIfNotExist("file1.txt");
    createFileIfNotExist("file2.txt");

    // Merge files
    mergeFiles("file1.txt", "file2.txt", "merged.txt");

    return 0;
}
