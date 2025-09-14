#include <stdio.h>

int OlderDate(int d1, int m1, int y1, int d2, int m2, int y2) {
    if (y1 < y2) return 1;
    else if (y1 > y2) return 0;
    else if (m1 < m2) return 1;
    else if (m1 > m2) return 0;
    else if (d1 < d2) return 1;
    else return 0;
}

int main() {
    int d1,m1,y1,d2,m2,y2;
    printf("Enter first date (dd mm yyyy): ");
    scanf("%d %d %d",&d1,&m1,&y1);
    printf("Enter second date (dd mm yyyy): ");
    scanf("%d %d %d",&d2,&m2,&y2);
    if (OlderDate(d1,m1,y1,d2,m2,y2)) printf("First date is older\n");
    else printf("Second date is older\n");
    return 0;
}
