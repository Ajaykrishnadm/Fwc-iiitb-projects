#include <stdio.h>

void Swap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    printf("After Swap: a=%d b=%d\n", a, b);
}

int main() {
    int x, y;
    printf("Enter two numbers: ");
    scanf("%d %d", &x, &y);
    Swap(x, y);
    return 0;
}
