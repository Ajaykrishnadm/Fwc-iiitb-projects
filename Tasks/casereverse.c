#include <stdio.h>

char CaseReverse(char c) {
    if (c >= 'a' && c <= 'z') return c - 32;
    if (c >= 'A' && c <= 'Z') return c + 32;
    return c;
}

int main() {
    char c;
    printf("Enter a character: ");
    scanf(" %c",&c);
    printf("Reversed Case: %c\n", CaseReverse(c));
    return 0;
}
