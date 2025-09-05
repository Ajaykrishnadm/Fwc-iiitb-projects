#include <stdio.h>
int* fun() {
    static int n;
    if (n) 
    printf("Square = %d\n", n*n);
    return &n;
}
int main() {
    int arr[] = {2,4,6,8}, *p;
    for (int i=0;i<4;i++) {
        p = fun(); 
        *p = arr[i]; 
        fun();       
    }
}
