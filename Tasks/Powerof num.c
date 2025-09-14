#include <stdio.h>

int Power(int a, int n) {
    int res = 1;
    for (int i = 0; i < n; i++) res *= a;
    return res;
}

int main() {
    int a, n;
    printf("Enter base and exponent: ");
    scanf("%d %d", &a, &n);
    printf("%d^%d = %d\n", a, n, Power(a, n));
    return 0;
}
