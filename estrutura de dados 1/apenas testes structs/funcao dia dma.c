#include <stdio.h>
#include <stdlib.h>

void main(){
	int *v, *V;
	int i, j;
	
	V = malloc(3*sizeof(int));
	v = malloc(3*sizeof(int));
	 
	for(i=0; i<3; i++)
	{
		scanf("%d", &v[i]);
	}
	
	
	for(j=0; j<3; j++)
	{
		printf("\n%d", v[j]);	
	}
}


