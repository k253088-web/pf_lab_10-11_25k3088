#include <stdio.h>

int sum_of_digits(int n) {
    if (n == 0) return 0;
    return (n % 10) + sum_of_digits(n / 10);
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    printf("Sum of digits = %d\n", sum_of_digits(n));
    return 0;
}
