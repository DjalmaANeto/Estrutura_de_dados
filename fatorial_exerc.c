#include <stdio.h>
int fatorial(int i){
	if(i <= 1){
		return 1;
	}else{
		return i * fatorial(i-1);
	}
}
main(){
	printf("%d",fatorial(5));
}
