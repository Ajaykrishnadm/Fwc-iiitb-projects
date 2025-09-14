#include <stdio.h>

int IsLeap(int year) {
    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
        return 1;
    return 0;
}

int DaysInMonth(int month, int year) {
    if (month == 2) return IsLeap(year) ? 29 : 28;
    if (month == 4 || month == 6 || month == 9 || month == 11) return 30;
    return 31;
}

int main() {
    int m,y;
    printf("Enter month and year: ");
    scanf("%d %d",&m,&y);
    printf("Days = %d\n", DaysInMonth(m,y));
    return 0;
}
