#include <stdio.h>

int Square(int n) {
    int res = 0;
    for (int i = 0; i < n; i++) res += n;
    return res;
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d",&n);
    printf("Square = %d\n", Square(n));
    return 0;
}
