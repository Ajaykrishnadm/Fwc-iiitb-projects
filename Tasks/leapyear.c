#include <stdio.h>

int IsLeap(int year) {
    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
        return 1;
    return 0;
}

int main() {
    int y;
    printf("Enter a year: ");
    scanf("%d", &y);
    if (IsLeap(y)) printf("%d is Leap Year\n", y);
    else printf("%d is Not Leap Year\n", y);
    return 0;
}
