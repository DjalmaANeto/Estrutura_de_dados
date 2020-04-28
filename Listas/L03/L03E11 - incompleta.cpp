#include <iostream>
#include <conio.h>
using namespace std;

struct LIST
{
    int num;
    LIST *next;
};

int size;

void creatList(LIST *head);
void pushBegin(LIST *head, int n);
void pushEnd(LIST *head, int n);
void pull(LIST *head, int n);
void printL(LIST *head);


int main(void){
    int n, op, n1;
    LIST *head = new LIST();
    creatList(head);

     do
    {
        cout<<"\n1 - Inserir no inicio";
        cout<<"\n2 - Inserir no fim";
        cout<<"\n3 - Imprimir";
        cout<<"\n4 - Excluir da lista";
        cout<<"\n5 - copiar para vetor";
        cout<<"\n0 - Sair\n";
        cin>>op;
        switch (op)
        {
        case 1:                
            cout<<"\nDigite um numero para inserir no inicio da lista: ";
            cin>>n;
            pushBegin(head, n);
            break;
        
        case 2:
            cout<<"\nDigite um numero para inserir no final da lista: ";
            cin>>n;
            pushEnd(head, n);
            break;
        
        case 3:
            cout<<"\nLista A: ";
            printL(head); 
            break;

        case 4:
            cout<<"\nDigite um numero para excluir da lista: ";
            cin>>n;
            pull(head, n);
            break;
                
        case 5:
            
            break;

        case 6:
            
            break;

        case 0:
            cout<<"\nSaindo.";
            break;

        default:
            cout<<"\nDigite uma opção válida";
            break;
        }
    } while (op != 0);

}

void creatList(LIST *head){
    head->next = NULL;
}

void pushBegin(LIST *head, int n){
    size++;
    LIST *newNode = new LIST();
    newNode->num = n;

    LIST *oldHead;
    oldHead = head->next;
    head->next = newNode;
    newNode->next = oldHead;
}

void pushEnd(LIST *head, int n){
    size++;
    LIST *newNode = new LIST();
    newNode->num = n;
    newNode->next = NULL;

    if (head->next == NULL)
    {
        head->next = newNode;
    }else
    {
        LIST *aux;
        aux = head->next;
        while (aux->next != NULL)
        {
            aux = aux->next;
        }
        aux->next = newNode;
    }
}

void pull(LIST *head, int n){
    LIST *aux = new LIST();
    LIST *back = new LIST();

    if (head == NULL)
    {
        cout<<"\nLista vazia";
    }
    else
    {
        aux = head;
        while (aux != NULL)
        {
            if (aux->num == n){
                if(aux == head)
                {
                    head = aux->next;
                    delete(aux);
                    aux = head;
                }
                else if (aux->next == NULL)
                {
                    back->next = NULL;
                    delete(aux);
                    aux = NULL;
                }else
                {
                    back->next = aux->next;
                    delete(aux);
                    aux = back->next;
                }
                
            }else
            {
                back = aux;
                aux = aux->next;
            }
        }   
    }
}

void printL(LIST *head){
   LIST *aux;
   aux = head->next;

    if(head == NULL){
        cout<<"\nLista vazia.";
        return;
    }else
    {
        while (aux != NULL)
        {
            cout<<aux->num<<" - ";
            aux = aux->next;
        }
    }
    cout<<"NULL";
}


