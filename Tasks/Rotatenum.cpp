//Code 3
#include <stdio.h>
void rotate(int *a, int *b, int *c) {
 int temp = *a;
*a = *b;
*b = *c;
*c = temp;
}
int main() {
int a = 1,b = 2, c = 3;
printf("Before:a=%d b=%d c=%d\n", a,b,c);
rotate(&a, &b, &c);
printf("After:a=%d b=%d c=%d\n", a,b,c);
return 0;
}
