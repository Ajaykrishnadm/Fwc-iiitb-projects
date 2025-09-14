#include <stdio.h>

int fun_alpha_num(char c) {
    if ((c >= '0' && c <= '9') || 
        (c >= 'A' && c <= 'Z') || 
        (c >= 'a' && c <= 'z'))
        return 1;
    return 0;
}

int main() {
    char c;
    printf("Enter a character: ");
    scanf(" %c", &c);
    if (fun_alpha_num(c)) printf("%c is Alphanumeric\n", c);
    else printf("%c is Not Alphanumeric\n", c);
    return 0;
}
