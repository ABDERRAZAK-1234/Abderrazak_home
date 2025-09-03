#include <stdio.h>
#include <stdlib.h>
int main(){
    int a, b, gcd;
    printf("Entrez deux entiers : ");
    scanf("%d %d", &a, &b);
    for (int i = 1; i <= a && i <= b; i++) {
        if (a % i == 0 && b % i == 0) {
            gcd = i;
        }
    }
    printf("Le plus grand commun diviseur de %d et %d est : %d\n", a, b, gcd);
    return 0;
}