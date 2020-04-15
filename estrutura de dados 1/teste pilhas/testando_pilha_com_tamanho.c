#include <stdio.h>

#define Max 3

int inicio, fim;
int pilha[Max];

void push (int x);
int pop ();

int pilhaVazia();
int pilhaCheia();

int main (){
	inicio = 0;
	fim = 0;
	int i;
	
	push(12);
	push(13);
	push(4);
	push(14);
	
	do{
		printf("\n%d",push());
	}while(i<4);
	
	return 0;
}

int pilhaVazia (){
	return (inicio == fim);
}

int pilhaCheia(){
	return (fim == Max);
}

void push (int x){
	if(!pilhaCheia()){
		pilha[fim++]=x;
	}else{
		printf("\npilha cheia\n");
	}
}

int pop (){
	int aux;
	if(!pilhaVazia()){
		aux = pilha[fim-1];
		fim--;
		return aux;
	}else {
		printf("\npilha vazia...\n");
		return -1; 
	}
}
  

