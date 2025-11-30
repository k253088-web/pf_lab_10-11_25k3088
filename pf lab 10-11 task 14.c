#include <stdio.h>
#include <time.h>

int main() {
    FILE *fp = fopen("log.txt", "a");
    if (!fp) {
        printf("Unable to open log file!\n");
        return 1;
    }

    time_t t;
    time(&t);

    fprintf(fp, "Program run at: %s", ctime(&t));
    fclose(fp);

    printf("Timestamp appended to log.txt\n");
    return 0;
}
