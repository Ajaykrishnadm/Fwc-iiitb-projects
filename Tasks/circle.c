#include <stdio.h>
#define PI 3.14
struct C {float a,p;};
struct C calc(float r){return (struct C){PI*r*r,2*PI*r};}
int main(){
    float r; scanf("%f",&r);
    struct C x=calc(r);
    printf("Area=%.2f\nPerimeter=%.2f",x.a,x.p);
}
