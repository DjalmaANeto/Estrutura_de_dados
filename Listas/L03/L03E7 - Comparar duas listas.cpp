#include <iostream>
#include <conio.h>

//definindo a struct lista 
	struct LISTA{
		int num;
		struct LISTA *prox;//ponteiro de encadeamento 
	};

int menorValor(LISTA *inicio);

int main(void){
	
	//lista inicia vazia
	//ponteiro inicio contera sempre o primeiro elemento da lista
	LISTA *inicio = NULL;
	
	//ponteiro fim contera o final da lista 
	LISTA *fim = NULL;
	
	//criando um ponteiro auxiliar
	LISTA *aux = NULL;
	
	//ponteiro auxiliar da versao anterior
	LISTA *anterior;
	
	int op, numero, achou;
	using namespace std;
	
	do{
//		clrscr();
		cout<<"\nMENU";
		cout<<"\n1 - Inserir numero no inicio da lista";
		cout<<"\n2 - Inserir numero no fim da lista";
		cout<<"\n3 - Consutar toda a lista";
		cout<<"\n4 - Remover da lista";
		cout<<"\n5 - Esvaziar a lista";
		cout<<"\n6 - Encontra o menor valor";
		cout<<"\n7 - Sair";
		cout<<"\nDigite a opcao: ";
		cin>>op;
			
		if(op < 1 || op > 7){
			cout<<"\nOpcao invalida";
		}
		
		if(op == 1){//inserindo no inicio da lista			
			cout<<"\nDigite o numero a ser inserido na lista: ";
			LISTA *novo = new LISTA();
			cin>>novo->num;
			
			//verificando se a lista esta vazia
			if(inicio == NULL){
				//lista vazia, insere-se no primeiro
				inicio = novo;
				fim = novo;
				fim->prox = NULL;
			}else{
				//se a lista ja contem elementos, insere-se no inicio 
				novo->prox = inicio;
				inicio = novo;
			}
			cout<<"\nNumero "<< novo->num <<" inserido no inicio da lista!" ;
		}
		
		if(op == 2){//inserindo no fim da lista
			
			cout<<"\nDigite o numero a ser inserido na lista: ";
			LISTA *novo = new LISTA();
			cin>>novo->num;
			
			//verificando se a lista esta vazia
			if(inicio == NULL){
				//lista vazia, insere-se no primeiro
				inicio = novo;
				fim = novo;
				fim->prox = NULL;
			}else{
				//se a lista ja contem elementos, insere-se no inicio 
				fim->prox = novo;
				fim = novo;
				fim->prox = NULL;
			}
			cout<<"\nNumero "<< novo->num <<" inserido no inicio da lista!" ;
		}
		
		if(op == 3){//consulta toda a lista
			//verifica se lista esta vazia 
			if(inicio == NULL){
				//lista esta vazia
				cout<<"Lista vazia!";
			}else{
				//lista contem elementos a serem mostrados 
				cout<<"\nConsultando toda a lista: \n";
				aux = inicio;
				while(aux != NULL){
					cout<<aux->num<<" - ";
					aux = aux->prox;
				}
			}
		}
		
		if(op == 4){//Remove item da lista 
			//verifica se lista esta vazia 
			if(inicio == NULL){
				//lista esta vazia
				cout<<"Lista vazia!";
			}else{
				//removendo elemento da lista
				cout<<"\nDigite o elemeto a ser removido: ";
				cin>>numero;
				//todos os itens da lista igual a numero sera removido
				aux = inicio;
				anterior = NULL;
				achou = 0;
				while(aux != NULL){
					if(aux->num == numero){
						//numero encontrado na lista, sera removido removido
						achou++;
						if(aux == inicio){
							//numero encontrado na primeira posicao
							inicio = aux->prox;
							delete(aux);
							aux = inicio;
						}else if(aux == fim){
							//o numero a ser removido � o �ltimo da lista
							anterior->prox = NULL;
							fim = anterior;
							delete(aux);
							aux = NULL;
						}else{
							//numero a ser removido esta no meio da lista
							anterior->prox = aux->prox;
							delete(aux);
							aux = anterior->prox;
						}	
					}else{
						anterior = aux;
						aux = aux->prox;
					}
				}
				if(achou == 0){
					cout<<"Numero nao encontrado!";
				}else if(achou == 1){
					cout<<"Numero "<<numero<<" removido 1 vez";
				}else{
					cout<<"Numero "<<numero<<" removido "<<achou<<" vezes"; 
				}
			}
		}
		
		if(op == 5){//esvaziar toda a lista 
			//verificando se a lista esta vazia 
			if(inicio == NULL){
				cout<<"Lista esta vazia!";
			}else{
				//lista sera esvaziada
				aux = inicio;
				while(aux != NULL){
					inicio = inicio->prox;
					delete(aux);
					aux = inicio;
				}
				cout<<"lista esvaziada";
			}
		}
		
		if(op == 6){
			cout<<"\nMenor valor: "<<menorValor(inicio)<<"\n";
		}
		
	}while(op != 7);
}

int menorValor(LISTA *inicio){
	int menor = inicio->num;	
	while(inicio != NULL){
		if(inicio->num < menor){
			menor = inicio->num;
		}
		inicio = inicio->prox;
	}
	return menor;
}















