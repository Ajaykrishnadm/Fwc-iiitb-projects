#include <stdio.h>

int Add(int a, int b) { return a + b; }
int Sub(int a, int b) { return a - b; }
int Mul(int a, int b) { return a * b; }
int Div(int a, int b) { return (b != 0) ? a / b : 0; }
int Mod(int a, int b) { return (b != 0) ? a % b : 0; }

int main() {
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    printf("Add=%d Sub=%d Mul=%d Div=%d Mod=%d\n",
           Add(a,b), Sub(a,b), Mul(a,b), Div(a,b), Mod(a,b));
    return 0;
}
