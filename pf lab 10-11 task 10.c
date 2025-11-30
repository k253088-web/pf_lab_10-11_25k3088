#include <stdio.h>
#include <string.h>

int is_palindrome(char str[]) {
    int i = 0, j = strlen(str) - 1;
    if (str[j] == '\n') j--;
    while (i < j) {
        if (str[i] != str[j]) return 0;
        i++;
        j--;
    }
    return 1;
}

int main() {
    char words[5][20]; int i;

    printf("Enter 5 words:\n");
    for (i = 0; i < 5; i++) {
        fgets(words[i], sizeof(words[i]), stdin);
    }

    for (i = 0; i < 5; i++) {
        if (is_palindrome(words[i]))
            printf("%s -> Palindrome\n", words[i]);
        else
            printf("%s -> Not Palindrome\n", words[i]);
    }

    return 0;
}
