#include<stdio.h>
#include<string.h>
#include<ctype.h>

int count_vowels(char str[], int index) {
    if (str[index] == '\0') return 0;

    char ch = tolower(str[index]);
    int is_vowel = (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u');

    return is_vowel + count_vowels(str, index + 1);
}

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    printf("Number of vowels = %d\n", count_vowels(str, 0));
    return 0;
}
