#include <iostream>
#include <conio.h>

int main(void){
	using namespace std;
	
	//estrutura lista
	struct LISTA{
		int num;
		LISTA *prox;
	};
	
	//ponteiro que guarda inicio da lista, recebe null para iniciar a lista vazia
	LISTA *inicio = NULL;
	
	//ponteiro que contera o ultimo item da lista 
	LISTA *fim = NULL;
	
	//ponteiro auxiliar
	LISTA *aux;
	
	//ponteiro da posção anterior 
	LISTA *anterior;
	
	//apresentando o menu de opções
	int op, numero, achou, elemento, quantidade;
	do{
		cout<<"\n\nMenu:\n";
		cout<<"\n1 - Inserir no inicio da lista";
		cout<<"\n2 - Inserir no fim da lista";
		cout<<"\n3 - Consultar lista";
		cout<<"\n4 - Remover da lista";
		cout<<"\n5 - Esvaziar a lista";
		cout<<"\n6 - Sair\n";
		cin>>op;
		
		if(op < 1 || op > 6){
			cout<<"\nOpcao invalida.";
		}
		
		if(op == 1){
			cout<<"Digite o número a ser inserido no inicio: ";
			LISTA *novo = new LISTA();
			cin>>novo->num;
			
			if(inicio == NULL){
				//lista vazia o elemento será inserido no iníncio
				inicio = novo;
				fim = novo;
				fim->prox = inicio;
			}else{
				//lista ja contem item, novo elemento sera inserido no inicio
				novo->prox = inicio;
				inicio = novo;
				fim->prox = inicio;
			}
			cout<<"\nNumero inserido na lista.";	
		}
		
		if(op == 2){
			cout<<"\nDigite o numero a ser inserdo no fim da lista: ";
			LISTA *novo = new LISTA();
			cin>>novo->num;
			
			if(inicio == NULL){
				//lista esta vazia o elemento inserido sera o primeiro
				inicio = novo;
				fim = novo;
				fim->prox = inicio;
			}else{
				//a lista ja contem elementos e o novo sera inserido no fim
				fim->prox = novo; 
				fim = novo;
				fim->prox = inicio;
			}
			cout<<"\nNumero inserido no fim da lista.";
		}
		
		//imprimindo toda a lista do inicio ao fim
		if(op == 3){
			if(inicio == NULL){
				//a lista está vazia 
				cout<<"\nLista vazia.";
			}else{
				//lista contem itens para a impressao
				cout<<"\nConsultando toda a lista: ";
				aux = inicio;
				do{
					cout<<aux->num<<" - ";
					aux = aux->prox;
				}while(aux != inicio);
			}
		}
		
		//removendo item da lista
		if(op == 4){
			if(inicio == NULL){
				//lista esta vazia 
				cout<<"\nLista esta vazia";
			}else{
				//lista contem elementos 
				cout<<"\nDigite o elemento a ser removido: ";
				cin>>numero;
				//todas as ocorrencias de numero na lista serao apagadas
				aux = inicio;
				anterior = NULL;
				achou = 0;
				//contando a quantidade de elementos
				quantidade = 0;
				aux = inicio;
				do{
					quantidade++;
					aux = aux->prox;
				}while(aux != inicio);
				elemento = 1;
				do{
					//se alista possuir apenas um elemento
					if(inicio == fim && inicio->num == numero){
						delete(inicio);
						inicio = NULL;
						achou++;
					}else{
						if(aux->num == numero){
							//numero digitado encontrado na lista
							achou++;
							if(aux == inicio){
								//O número a ser removido é o primeiro da lista
								inicio = aux->prox;
								fim->prox = inicio;
								delete(aux);
								aux = inicio;
							}else if(aux == fim){
								//o numero foi encontrado na última posição
								fim = anterior;
								fim->prox = inicio;
								delete(aux);
								aux = NULL;
							}else{
								//o número a ser removido está no meio da lista
								anterior->prox = aux->prox;
								delete(aux);
								aux = anterior->prox;
							}
						}else{
							anterior = aux;
							aux = aux->prox;
						}
					}
					elemento++;
				}while(elemento <= quantidade);//cuasuando erro	
				
				if(achou == 0){
				cout<<"\nNumero nao encontrado";
				}else if(achou == 1){
					cout<<"\nNumero removido 1 vez";
				}else{
					cout<<"\nNumero removido "<<achou<<" vezes";
				}
			}
		}
		
		//apagando toda a lista
		if(op == 5){
			if(inicio == NULL){
				//lista esta vazia 
				cout<<"\nLista esta vazia";
			}else{
				//lista sera esvaziada 
				aux = inicio;
				do{
					inicio = inicio->prox;
					delete(aux);
					aux = inicio;
				}while(aux != fim);
				delete(fim);
				inicio = NULL;
				cout<<"\nLista esvaziada.";
			}
		}
	}while(op != 6);
}















