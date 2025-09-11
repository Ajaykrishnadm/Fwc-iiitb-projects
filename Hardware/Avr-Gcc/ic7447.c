#include <stdio.h>

int F(int X, int Y, int Z) {
    return ((!X && !Y) || (Y && Z));
}

int main() {
    printf("X Y Z | F\n");
    printf("------------\n");
    for (int X = 0; X <= 1; X++) {
        for (int Y = 0; Y <= 1; Y++) {
            for (int Z = 0; Z <= 1; Z++) {
                printf("%d %d %d | %d\n", X, Y, Z, F(X, Y, Z));
            }
        }
    }
    return 0;
}
