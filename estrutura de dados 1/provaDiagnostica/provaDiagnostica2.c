#include <stdio.h>
#include <stdlib.h>

void troca (int a, int b);

	int main(){
		int a, b;
	
		printf("Escreva o valor de A:");
		scanf("%d",&a);
	
		printf("\nEscreva o valor de B:");
		scanf("%d",&b);
		
		troca(a,b);
		
		pritf("A:%d",a);
		pritf("\nB:%d",b);
		
	}
	
	void troca (int a, int b) {
		int c;
		c = a;
		a = b;
		b = c;
	}



