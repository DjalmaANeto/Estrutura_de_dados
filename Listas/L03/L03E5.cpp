#include <iostream>
#include <conio.h>

#define N 20

int main (void){
	using namespace std;

	//estrutura de lista 
	struct LISTA{
		int num;
		struct LISTA *prox;//ponteiro de encadeamento 
		struct LISTA *ant;
	};
	
	typedef LISTA IMPAR;
	
	typedef LISTA PAR;
	
	//lista inicia vazia
	//ponteiro inicio contera sempre o primeiro elemento da lista
	PAR *inicioPar = NULL;
	
	//ponteiro fim contera o final da lista 
	PAR *fimPar = NULL;
	
	//criando um ponteiro auxiliar
	PAR *auxPar = NULL;
	
	//ponteiro auxiliar da versao anterior
	PAR *anteriorPar;
	
	//lista inicia vazia
	//ponteiro inicio contera sempre o primeiro elemento da lista
	IMPAR *inicioImpar = NULL;
	
	//ponteiro fim contera o final da lista 
	IMPAR *fimImpar = NULL;
	
	//criando um ponteiro auxiliar
	IMPAR *auxImpar = NULL;
	
	//ponteiro auxiliar da versao anterior
	IMPAR *anteriorImpar;

	//preenchendo as lista
	int i, numero;
	cout<<"\nInforme uma sequencia de 20 numeros: \n";
	for(i = 0; i < N; i++){
		cin>>numero;
		//verificando se o numero é par ou impar 
		if(numero % 2 == 0){	
			PAR *novoPar = new PAR();
			novoPar->num = numero;
			
			if(inicioPar == NULL){
				//lista vazia, insere-se no primeiro
				inicioPar = novoPar;
				fimPar = novoPar;
				fimPar->prox == NULL;
			}else{
				//se a lista ja contem elementos, insere-se no inicio 
				novoPar->prox = inicioPar;
				inicioPar = novoPar;
			}
			
		}else{
			IMPAR *novoImpar = new IMPAR();
			novoImpar->num = numero;
			
			if(inicioImpar == NULL){
				//lista vazia, insere-se no primeiro
				inicioImpar = novoImpar;
				fimImpar = novoImpar;
				fimImpar->prox == NULL;
			}else{
				//se a lista ja contem elementos, insere-se no inicio 
				novoImpar->prox = inicioImpar;
				inicioImpar = novoImpar;
			}
		}
	}
	
	//Imprimindo numeros pares
	cout<<"\nPares: \n";
	auxPar = inicioPar;
	while(auxPar != NULL){
		cout<<auxPar->num<<" - ";
		auxPar = auxPar->prox;
	}
	cout<<" NULL ";
	
	//Imprimindo numeros impares
	cout<<"\nImpares: \n";
	auxImpar = inicioImpar;
	while(auxImpar != NULL){
		cout<<auxImpar->num<<" - ";
		auxImpar = auxImpar->prox;
	}
	cout<<" NULL ";
	
	//estrutura de lista duplamente encadeada ordenada
	typedef LISTA lista;
	
	//ponteiro de inicio, contera o primeiro esdereço da lista
	//inicia com NULL
	lista *inicio = NULL;
	
	//ponteiro fim contera o último endereço da lista
	lista *fim = NULL;
	
	//ponteiro auxiliar 
	lista *aux;
	
	//preenchendo lista duplamente encadeada ordenada 
	//recebendo pares
	auxPar = inicioPar;
	do{
		lista *novo = new lista();
		novo->num = auxPar->num;
			if(inicio == NULL){
				//a lista esta vazia e o elemento sera inserido na primeira posição
				novo->prox = NULL;
				novo->ant = NULL;
				inicio = novo;
				fim = novo;
			}else{
				//a lista contem elementos, sera inserido na ordem crescente 
				aux = inicio;
				while(aux != NULL && novo->num > aux->num){
					aux = aux->prox;
				}
				if(aux == inicio){
					//numero a ser inserido é menosr que todos da lista
					//sera inserido no inicio
					novo->prox = inicio;
					novo->ant = NULL;
					inicio->ant = novo;
					inicio = novo;
				}else if(aux == NULL){
					//numero a ser inserido é maior que todos na lista
					//sera inserido no fim da lista
					fim->prox = novo;
					novo->ant = fim;
					fim = novo;
					fim->prox = NULL;
				}else{
					//o novo número a ser inserido será inserido entre dois 
					//números que já estão na lista
					novo->prox = aux;
					aux->ant->prox = novo;
					novo->ant = aux->ant;
					aux->ant = novo;
				}				
			}
		auxPar = auxPar->prox;
	}while(auxPar != NULL);
	
	//recebendo impares
	auxImpar = inicioImpar;
	do{
		lista *novo = new lista();
		novo->num = auxImpar->num;
			if(inicio == NULL){
				//a lista esta vazia e o elemento sera inserido na primeira posição
				novo->prox = NULL;
				novo->ant = NULL;
				inicio = novo;
				fim = novo;
			}else{
				//a lista contem elementos, sera inserido na ordem crescente 
				aux = inicio;
				while(aux != NULL && novo->num > aux->num){
					aux = aux->prox;
				}
				if(aux == inicio){
					//numero a ser inserido é menosr que todos da lista
					//sera inserido no inicio
					novo->prox = inicio;
					novo->ant = NULL;
					inicio->ant = novo;
					inicio = novo;
				}else if(aux == NULL){
					//numero a ser inserido é maior que todos na lista
					//sera inserido no fim da lista
					fim->prox = novo;
					novo->ant = fim;
					fim = novo;
					fim->prox = NULL;
				}else{
					//o novo número a ser inserido será inserido entre dois 
					//números que já estão na lista
					novo->prox = aux;
					aux->ant->prox = novo;
					novo->ant = aux->ant;
					aux->ant = novo;
				}				
			}
		auxImpar = auxImpar->prox;
	}while(auxImpar != NULL);
	
	//imprimindo formas ordenadas
	cout<<"\n\na) Crescente: ";
	cout<<"NULL - ";
	aux = inicio;
	while(aux != NULL){
		cout<<aux->num<<" - ";
		aux = aux->prox;
	}
	cout<<"NULL";
	
	cout<<"\n\nb) Decrescente: ";
	cout<<"NULL - ";
	aux = fim;
	while(aux != NULL){
		cout<<aux->num<<" - ";
		aux = aux->ant;
	}
	cout<<"NULL";
}


