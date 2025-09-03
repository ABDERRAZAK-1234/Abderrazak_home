#include <stdio.h>
#include <stdlib.h>
int main() {
    int j1, m1, a1, j2, m2, a2;
    printf("Saisir le premier date : (jj/mm/aaaa) ");
    scanf("%d/%d/%d", &j1, &m1, &a1);
    printf("Saisir le deuxieme date : (jj/mm/aaaa) ");
    scanf("%d/%d/%d", &j2, &m2, &a2);
    if (a1 < a2 || (a1 == a2 && m1 < m2) || (a1 == a2 && m1 == m2 && j1 < j2)) {
        printf("La date %d/%d/%d est plus tot que la date %d/%d/%d.\n", j1, m1, a1, j2, m2, a2);
    } else {
        printf("La date %d/%d/%d est plus tot que la date %d/%d/%d.\n", j2, m2, a2, j1, m1, a1);
    }
    return 0;
}