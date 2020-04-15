#include <stdio.h>
#include <stdlib.h>

void troca (int a, int b);

int main() {
int a, b;
printf("Escreva o valor de A:");
scanf ("%d", &a);
printf("Escreva o valor de B:");
scanf("%d", &b);
troca(a, b);
printf("A - %d B - %d", a, b);
return 0;
}

void troca (int a, int b) {
int c;
c = a;
a = b;
b = c;
}


