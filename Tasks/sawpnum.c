//Code 1
#include <stdio.h>
void swap(int *a, int *b) {
    int x = *a; *a = *b; *b = x;
}
int main() {
    int x = 100, y = 200;
    printf("Before: x=%d y=%d\n", x, y);
    swap(&x, &y);  
    printf("After:  x=%d y=%d\n", x, y);
}
