#include <conio.h>
#include <iostream>

using namespace std;

struct LIST
{
    int num;
    LIST *next;
};

void creatList(LIST *head);
void pushBegin(LIST *head, int n);
void pushEnd(LIST *head, int n);
void pull(LIST *head, int n);
void printL(LIST *head);
void copy(LIST *headA, LIST *headB);
void concatenate(LIST *headA,LIST *headB);

int main(void){
    int op, num;
    char l[1];
    
    LIST *headA = new LIST();
    creatList(headA);
    LIST *headB = new LIST();
    creatList(headB);

    do
    {
        cout<<"\n1 - Inserir no inicio";
        cout<<"\n2 - Inserir no fim";
        cout<<"\n3 - Imprimir";
        cout<<"\n4 - Excluir da lista";
        cout<<"\n5 - Copiar lista";
        cout<<"\n6 - Concatenar lista";
        cout<<"\n0 - Sair\n";
        cin>>op;
        switch (op)
        {
        case 1:                
            cout<<"\nDigite um numero para inserir no inicio da lista: ";
            cin>>num;
            pushBegin(headA, num);
            break;
        
        case 2:
            cout<<"\nDigite um numero para inserir no final da lista: ";
            cin>>num;
            pushEnd(headA, num);
            break;
        
        case 3:
            cout<<"\nLista A: ";
            printL(headA);
            if (headB != NULL)
            {
                cout<<"\nLista B: ";
                printL(headB);
            }
            
            break;

        case 4:
            cout<<"\nDigite um numero para excluir da lista: ";
            cin>>num;
            pull(headA, num);
            break;
                
        case 5:
            cout<<"\nCopiando a lista";
            copy(headA, headB);             
            break;

        case 6:
            cout<<"Concatenando A em B";
            concatenate(headA, headB);        
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
    LIST *newNode = new LIST();
    newNode->num = n;

    LIST *oldHead;
    oldHead = head->next;
    head->next = newNode;
    newNode->next = oldHead;
}

void pushEnd(LIST *head, int n){
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

void copy(LIST *headA, LIST *headB){
    LIST *aux = headA->next;
    if(headA == NULL){
        cout<<"\nLista vazia.";
        return;
    }else
    {
        while (aux != NULL)
        {
            pushEnd(headB, aux->num);
            aux = aux->next;
        }
    }

}

void concatenate(LIST *headA, LIST *headB){
    LIST *aux = headB->next;
    while (aux != NULL)
    {
        pushEnd(headA, aux->num);
        aux = aux->next;
    }
}