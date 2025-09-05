//code 4 arithmetic
#include <stdio.h>

void ops(int a, int b, int *c, int *d, int *e, int *f, int *g) {
    *c = a+b; *d = a-b; *e = a*b; *f = a/b; *g = a%b;
}

int main() {
    int x=24, y=10, c,d,e,f,g;
    ops(x,y,&c,&d,&e,&f,&g);
    printf("add=%d\nsub=%d\nmult=%d\ndiv=%d\nmod=%d\n", c,d,e,f,g);
}
