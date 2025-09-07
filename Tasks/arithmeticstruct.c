#include <stdio.h>
struct Obj{int add,sub,mul,rem;float div;};
struct Obj calc(int a,int b){return (struct O){a+b,a-b,a*b,a%b,(float)a/b};}
int main(){
    int x,y; scanf("%d%d",&x,&y);
    struct Obj r=calc(x,y);
    printf("Add=%d\nSub=%d\nMul=%d\nQuot=%.2f\nRem=%d",r.add,r.sub,r.mul,r.div,r.rem);
}
