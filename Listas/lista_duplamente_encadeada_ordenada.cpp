#include <iostream>
#include <conio.h>

int main(void){
	using namespace std;
	
	//definindo o registrlista
	struct LISTA{
		int num;
		LISTA *prox;
		LISTA *ant;
	};
	
	//ponteiro de inicio, contera o primeiro esdere�o da lista
	//inicia com NULL
	LISTA *inicio = NULL;
	
	//ponteiro fim contera o �ltimo endere�o da lista
	LISTA *fim = NULL;
	
	//ponteiro auxiliar 
	LISTA *aux;
	
	//menu de op��es 
	int op, numero, achou;
	do{
		cout<<"\n\nMenu:\n";
		cout<<"\n1 - Inserir na lista";
		cout<<"\n2 - Consultar lista do inicio ao fim";
		cout<<"\n3 - Consultar lista do fim ao inicio";
		cout<<"\n4 - Remover da lista";
		cout<<"\n5 - Esvaziar a lista";
		cout<<"\n6 - Sair\n";
		cin>>op;
		
		if(op < 1 || op > 6){
			cout<<"\nOpcao invalida.";
		}
		
		//inserindo numero na lista
		if(op == 1){
			cout<<"\nDigite o n�mero a ser inserido: ";
			//ponteiro novo elemento na lista
			LISTA *novo = new LISTA();
			cin>>novo->num;
			
			if(inicio == NULL){
				//a lista esta vazia e o elemento sera inserido na primeira posi��o
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
					//numero a ser inserido � menosr que todos da lista
					//sera inserido no inicio
					novo->prox = inicio;
					novo->ant = NULL;
					inicio->ant = novo;
					inicio = novo;
				}else if(aux == NULL){
					//numero a ser inserido � maior que todos na lista
					//sera inserido no fim da lista
					fim->prox = novo;
					novo->ant = fim;
					fim = novo;
					fim->prox = NULL;
				}else{
					//o novo n�mero a ser inserido ser� inserido entre dois 
					//n�meros que j� est�o na lista
					novo->prox = aux;
					aux->ant->prox = novo;
					novo->ant = aux->ant;
					aux->ant = novo;
				}				
			}
			cout<<"\nNumero inserido na lista.";
		}
		
		//imprimindo lista do inicio ao fim
		if(op == 2){
			if(inicio == NULL){
				//lista esta vazia 
				cout<<"\nLista vazia.";
			}else{
				//lista contem elementos sera imprimida do inicio ao fim
				cout<<"\nConsultando a lista do inicio ao fim: \n";
				cout<<"NULL - ";
				aux = inicio;
				while(aux != NULL){
					cout<<aux->num<<" - ";
					aux = aux->prox;
				}
				cout<<"NULL";
			}
		}
		
		//imprimindo lista do fim ao inicio
		if(op == 3){
			if(inicio == NULL){
				//lista esta vazia 
				cout<<"\nLista vazia.";
			}else{
				//lista contem elementos sera imprimida do fim ao inicio 
				cout<<"\nConsultando a lista do fim ao inicio: \n";
				cout<<"NULL - ";
				aux = fim;
				while(aux != NULL){
					cout<<aux->num<<" - ";
					aux = aux->ant;
				}
				cout<<"NULL";
			}
		}
		
		//removendo elemento da lista
		if(op == 4){
			if(inicio == NULL){
				//lista est� vazia 
				cout<<"\nLista vazia.";
			}else{
				//lista contem elemeentos
				cout<<"\nDigite o elemento a ser removido: ";
				cin>>numero;
				//todas as ocorrencias da lista igual a numero serao exclidas
				aux = inicio;
				achou = 0;
				while(aux != NULL){
					if(aux->num == numero){
						//numero digitado foi encontrado e sera excluido
						achou++;
						if(aux == inicio){
							//numero a ser removido � o primeriro
							inicio = aux->prox;
							if(inicio != NULL){
								inicio->ant = NULL;
								delete(aux);
								aux = inicio;
							}	
						}else if( aux == fim){
							//numero a ser removido � o �ltimo da lista
							fim = fim->ant;
							fim->prox = NULL;
							delete(aux);
							aux = NULL;
						}else{
							//numero a ser removido est� no meio da lista
							aux->ant->prox = aux->prox;
							aux->prox->ant = aux->ant;
							//auxiliar 2
							LISTA *aux2;
							aux2 = aux->prox;
							delete(aux);
							aux = aux2;
						}
					}else{
						aux = aux->prox;
					} 
				}
				if(achou == 0){
					cout<<"\nNumero n�o encontrado.";
				}else if(achou == 1){
					cout<<"\nNumero removido 1 vez.";
				}else{
					cout<<"\nNumero removido "<<achou<<" vezes";
				}
			}
		}
		
		//apagando a lista
		if(op == 5){
			if(inicio == NULL){
				//lista esta vazia
				cout<<"\nLista vazia.";
			}else{
				//esvaziando lista
				aux = inicio;
				while(aux != NULL){
					inicio = inicio->prox;
					delete(aux);
					aux = inicio;
				}
				cout<<"\nLista esvaziada.";
			}
		}	
		
	}while(op != 6);
}


