//code 4 arithmetic
#include <stdio.h>

void ops(int a, int b, int *c, int *d, int *e, int *f, int *g) {
    *c = a+b; *d = a-b; *e = a*b; *f = a/b; *g = a%b;
}

int main() {
    int x=15, y=6, c,d,e,f,g;
    ops(x,y,&c,&d,&e,&f,&g);
    printf("Sum=%d\nDiff=%d\nProd=%d\nQuot=%d\nRem=%d\n", c,d,e,f,g);
}
