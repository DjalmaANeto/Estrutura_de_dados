#include <iostream>
#include <conio.h>

int main(void){
	using namespace std;
	//registro que representará a lista
	struct LISTA{
		int num;
		LISTA *prox;
	};
	
	//ponteiro inicio apontando para null, lista começa fazia
	LISTA *inicio = NULL;
	//ponteiro fim apontara para o ultimo elemento da lista
	LISTA *fim = NULL;
	//ponteiro auxiliar 
	LISTA *aux;
	//ponteiro auxiliar para a posiçao anterior
	LISTA *anterior;
	
	int op, numero, achou;
	
	do{
		cout<<"\nMenu\n";
		cout<<"\n1 - inserir na lista";
		cout<<"\n2 - consultar a lista";
		cout<<"\n3 - remover da lista";
		cout<<"\n4 - apagar a lista";
		cout<<"\n5 - sair\n";
		cin>>op;
		
		if( op < 1 || op > 5){
			cout<<"\nOpcao invalida.";
		}
		
		if(op == 1){
			cout<<"\nDigite o numero a ser incluido: ";
			LISTA *novo = new LISTA();
			cin>>novo->num;
			
			if(inicio == NULL){
				//lista esta vazia, inserindo no primiro elemento
				inicio = novo;
				fim = novo;
				novo->prox = NULL;
			}else{
				//lista nao esta vazia, novo elemento sera inserido de forma crescente
				anterior = NULL;
				aux = inicio;
				
				while(aux != NULL && novo->num > aux->num){
					anterior = aux;
					aux = aux->prox;
				}
				if(anterior == 	NULL){
					//o novo número a ser inserido é menor que todos da lista
					novo->prox = inicio;
					inicio = novo;
				}else if(aux == NULL){
					//novo numero é maior que todos da lista
					fim->prox = novo;
					fim = novo;
					fim->prox = NULL;
				}else{
					//numero sera inserido entre dois numeros que ja existem
					anterior->prox = novo;
					novo->prox = aux;
				}
			}
			cout<<"\nNumero inserido na lista!";
		}
		
		if(op == 2){
			if(inicio == NULL){
				cout<<"\nLista esta vazia.";
			}else{
				//a lista contem elementos
				cout<<"\nImprimindo lista: ";
				aux = inicio;
				while(aux != NULL){
					cout<<aux->num<<"->";
					aux = aux->prox;
				}
			}
		}
		
		if(op == 3){
			if(inicio == NULL){
				//lista não contem elementos
				cout<<"\nLista vazia.";
			}else{
				//lista contem elementos, excluira o escolhido
				cout<<"\nDigite o elemento a ser removido: ";
				cin>>numero;
				
				//todas as ocorrencias da lista iguias a numero serao excluidas
				aux = inicio;
				anterior = NULL;
				achou = 0;
				while(aux != NULL){
					if(aux->num == numero){
						//numero encontrado, sera removido
						achou++;
						if(aux == inicio){
							//o numero é o primeiro da lista
							inicio = aux->prox;
							delete(aux);
							aux = inicio;
						}else if(aux == fim){
							//o numero a ser removido é o último
							anterior->prox = NULL;
							fim = anterior;
							delete(aux);
							aux = NULL;
						}else{
							//numero esta no meio da lista
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
					cout<<"\nNumero nao encontrado.";
				}else if(achou == 1){
					cout<<"\nNumero removido 1 vez";
				}else{
					cout<<"\nNumero removido "<<achou<<" vezes";
				}
			}
		}
		
		if(op == 4){
			if(inicio == NULL){
				//a lista estávazia
				cout<<"\nLista vazia.";
			}else{
				//esvaziando lista
				aux = inicio; 
				while(aux != NULL){
					inicio = inicio->prox;
					delete(aux);
					aux = inicio;
				}
				cout<<"\nLista está vazia.";
			}
		}
	
	}while(op!=5);
	
}
