#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,i;
   printf("Saisir un nombre : ");
   scanf("%d", &n);
   for ( i = 1; (i * i) <= n; i++) {
       if ((i * i) % 2 == 0) {
           printf("%d \n", i * i);
       }
    }
   return 0;
}
