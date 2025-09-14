#include <stdio.h>

int isPrime(int number) {
    if (number < 2) {
        return 0;
    }
    for (int divisor = 2; divisor * divisor <= number; divisor++) {
        if (number % divisor == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    if (isPrime(number)) {
        printf("%d is a Prime number.\n", number);
    } else {
        printf("%d is NOT a Prime number.\n", number);
    }
    return 0;
}
