#include <stdio.h>
void swap(int *a, int *b);

int main() {
  int arr[2] = {10, 20};
  printf("Before:%d %d\n", arr[0], arr[1]);

swap(&arr[0], &arr[1]);
 printf("After:%d %d\n", arr[0], arr[1]);
 return 0;
}
// same method in the first question 
void swap(int *a, int *b) {
    int x = *a;
    *a = *b;
    *b = x;
}
