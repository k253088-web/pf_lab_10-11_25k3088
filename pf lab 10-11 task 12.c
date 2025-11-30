#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *fp = fopen("file.txt", "r");
    
    if (!fp) {
        printf("File not found! Creating file...\n");
        fp = fopen("file.txt", "w");  // create empty file
        if (!fp) {
            printf("Failed to create file.\n");
            return 1;
        }
        fclose(fp);

        fp = fopen("file.txt", "r");
        if (!fp) {
            printf("Failed to open file.\n");
            return 1;
        }
    }

    char ch;
    int charCount = 0, wordCount = 0, lineCount = 0;
    int inWord = 0;

    while ((ch = fgetc(fp)) != EOF) {
        charCount++;
        if (ch == '\n') lineCount++;
        if (isspace(ch)) inWord = 0;
        else if (!inWord) {
            inWord = 1;
            wordCount++;
        }
    }

    fclose(fp);
    printf("Characters: %d\nWords: %d\nLines: %d\n", charCount, wordCount, lineCount);

    return 0;
}
