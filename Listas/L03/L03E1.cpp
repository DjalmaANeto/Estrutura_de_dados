#include <iostream>
#include <conio.h>

#define N 15

int main(void){
	using namespace std;
	
	//definindo a struct lista 
	struct LISTA{
		int codigo;
		float preco;
		int estoque;
		struct LISTA *prox;//ponteiro de encadeamento 
	};
	
	//lista inicia vazia
	//ponteiro inicio contera sempre o primeiro elemento da lista
	LISTA *inicio = NULL;
	
	//ponteiro fim contera o final da lista 
	LISTA *fim = NULL;
	
	//criando um ponteiro auxiliar
	LISTA *aux = NULL;
	
	//ponteiro auxiliar da versao anterior
	LISTA *anterior;
	
	//ponteiro novo lista 
	
	int i;
	
	//preenchendo a lista de produtos
	for(i=0; i<=N; i++){
		LISTA *novo = new LISTA();
		cout<<"\nInforme o codigo do produto "<<i<<" :";
		cin>>novo->codigo;
		cout<<"Informe o preco do produto "<<i<<" :";
		cin>>novo->preco;
		cout<<"Informe a quantidade em estoque do produto maior "<<i<<" :";
		cin>>novo->estoque;
		if(novo->estoque < 500){
			do{
				cout<<"Informe uma quantidade maior que 500: ";
				cin>>novo->estoque;
			}while(novo->estoque < 500);
		}
		
		if(inicio == NULL){
			//lista vazia, insere-se no primeiro
			inicio = novo;
			fim = novo;
			fim->prox == NULL;
		}else{
			//se a lista ja contem elementos, insere-se no inicio 
			novo->prox = inicio;
			inicio = novo;
		}
	}
	
	//inserindo desconto
	float desconto;
	cout<<"\nInforme uma porcentagem de desconto: ";
	cin>>desconto;
		
	aux = inicio;
	while(aux != NULL){
		aux->preco = aux->preco - (aux->preco * (desconto/100));
		aux = aux->prox;
	}
	
	//imprimindo relatorio
	cout<<"\nRelatorio\n";
	aux = inicio;
	i = 0;
	while(aux != NULL){
		cout<<"\nProduto "<<i<<" Codigo:"<<aux->codigo<<"\tPreco:"<<aux->preco<<"\tEstoque:"<<aux->estoque;
		aux = aux->prox;
		i++;
	}
		
}
	
