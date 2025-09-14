#include <stdio.h>

float totalAmount(float p, float r, int months) {
    float t = months / 12.0;
    float si = (p * r * t) / 100.0;
    return p + si;
}

int main() {
    float p, r;
    int months;
    printf("Enter Principal, Rate, Time(in months): ");
    scanf("%f %f %d", &p, &r, &months);
    printf("Total Amount = %.2f\n", totalAmount(p, r, months));
    return 0;
}
