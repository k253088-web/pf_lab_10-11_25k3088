#include <stdio.h>

int main() {
    FILE *fp = fopen("data.txt", "w"); // opening in write mode clears file
    if (!fp) {
        printf("Unable to open file!\n");
        return 1;
    }
    fclose(fp);

    // Confirm file is empty
    fp = fopen("data.txt", "r");
    if (fp) {
        fseek(fp, 0, SEEK_END);
        if (ftell(fp) == 0) printf("File is empty.\n");
        else printf("File not empty.\n");
        fclose(fp);
    }

    return 0;
}
