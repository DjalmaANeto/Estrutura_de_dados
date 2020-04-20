#include <conio.h>
#include <iostream>
#include <string.h>

using namespace std;

struct LIST
{
    int num;
    LIST *next;
};

void creatList(LIST *head);
void pushBegin(LIST *head, int n);
void pushEnd(LIST *head, int n);
void printL(LIST *head);
int findSmaller(LIST *head);
int compare(LIST *headA, LIST *headB);

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
        cout<<"\n6 - Menor item da lista";
        cout<<"\n7 - Comparar duas lista";
        cout<<"\n8 - Sair\n";
        cin>>op;
        switch (op)
        {
        case 1:
                do
                {
                    cout<<"\nDigite lista a ou b: ";
                    cin>>l;
                } while (strcmp(l,"a") != 0 && strcmp(l,"b") != 0);
                if (strcmp(l,"a") == 0)
                {
                    cout<<"\nDigite um numero para inserir no inicio da lista a: ";
                    cin>>num;
                    pushBegin(headA, num);
                }else if (strcmp(l,"b") == 0)
                {
                    cout<<"\nDigite um numero para inserir no inicio da lisa b: ";
                    cin>>num;
                    pushBegin(headB, num);
                }            
            break;
        
        case 2:
            do
            {
                cout<<"\nDigite lista a ou b: ";
                cin>>l;
            } while (strcmp(l,"a") != 0 && strcmp(l,"b") != 0);
            if (strcmp(l,"a") == 0)
            {
                cout<<"\nDigite um numero para inserir no final da lista a: ";
                cin>>num;
                pushEnd(headA, num);
            }else if (strcmp(l,"b") == 0)
            {
                cout<<"\nDigite um numero para inserir no final da lisa b: ";
                cin>>num;
                pushEnd(headB, num);
            }
            break;
        
        case 3:
            cout<<"\nLista A: ";
            printL(headA);
            cout<<"\nLista B: ";
            printL(headB);
            break;

        case 6:
            cout<<"\nLista A: "<<findSmaller(headA);
            cout<<"\nLista B: "<<findSmaller(headB); 
            break;

        case 7:
            if (compare(headA, headB) == 0)
            {
                cout<<"\nListas vazias";
            }
            else if (compare(headA, headB) == 1)
            {
                cout<<"\nListas diferentes";
            }
            else
            {
                cout<<"\nListas iguais";
            } 
            break;

        default:
            cout<<"\nDigite uma opção válida";
            break;
        }
    } while (op != 8);
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

int findSmaller(LIST *head){
    int smaller = head->num;
    if (head == NULL)
    {
        return 0;
    }else
    {
        while (head != NULL)
        {
            if (head->num < smaller)
            {
                smaller = head->num;
            }
            head = head->next;
        }
        return smaller;
    }   
}

int compare(LIST *headA, LIST *headB){    
    if (headA->next == NULL && headB->next == NULL)
    {
        return 0;
    }
    else if (headA->next == NULL || headB->next == NULL)
    {
        return 1;
    }
    else
    {
        while (headA->next != NULL && headB->next != NULL)
        {
            if (headA->num != headB->num)
            {
                return 1;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return 2;
    }
}