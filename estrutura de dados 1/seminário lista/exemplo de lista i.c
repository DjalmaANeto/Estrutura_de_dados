#include <stdio.h>
#include <stdlib.h>

struct Node{
 int num;
 struct Node *prox;
}; 
typedef struct Node node;

int tam;

void inicia(node *LISTA);
int menu(void);
void opcao(node *LISTA, int op);
node *criaNo();
void insereFim(node *LISTA);
void insereInicio(node *LISTA);
void exibe(node *LISTA);
void libera(node *LISTA);
void insere (node *LISTA);
node *retiraInicio(node *LISTA);
node *retiraFim(node *LISTA);
node *retira(node *LISTA);


int main(void)
{
 node *LISTA = (node *) malloc(sizeof(node));
 if(!LISTA){
  printf("Sem memoria disponivel!\n");
  exit(1);
 }else{
 inicia(LISTA);
 int opt;
 
 do{
  opt=menu();
  opcao(LISTA,opt);
 }while(opt);

 free(LISTA);
 return 0;
 }
}

void inicia(node *LISTA)//Esta fun��o inicia a lista 
{
 LISTA->prox = NULL;//observe que ao iniciar a "head" da nossa llista aponta para NULL
 tam=0;
}

int menu(void)//Esta fun��o exibe as opcoes de uso da lista criada para o usu�rio 
{
 int opt;
 
 printf("Escolha a opcao\n");
 printf("0. Sair\n");
 printf("1. Zerar lista\n");
 printf("2. Exibir lista\n");
 printf("3. Adicionar node no inicio\n");
 printf("4. Adicionar node no final\n");
 printf("5. Escolher onde inserir\n");
 printf("6. Retirar do inicio\n");
 printf("7. Retirar do fim\n");
 printf("8. Escolher de onde tirar\n");
 printf("Opcao: "); 
 scanf("%d", &opt);
 
 return opt;
}

void opcao(node *LISTA, int op)//Esta fun��o executa um switch das opcoes possiveis de manipula��o da ista criada
{
 node *tmp;
 switch(op){
  case 0:
   libera(LISTA);
   break;
   
  case 1:
   libera(LISTA);
   inicia(LISTA);
   break;
  
  case 2:
   exibe(LISTA);
   break;
  
  case 3:
   insereInicio(LISTA);
   break;  
   
  case 4:
   insereFim(LISTA);
   break;
   
  case 5:
   insere(LISTA);
   break;
  
  case 6:
   tmp= retiraInicio(LISTA);
   printf("Retirado: %3d\n\n", tmp->num);
   break;
   
  case 7:
   tmp= retiraFim(LISTA);
   printf("Retirado: %3d\n\n", tmp->num);
   break;
  
  case 8:
   tmp= retira(LISTA);
   printf("Retirado: %3d\n\n", tmp->num);
   break;
  
  default:
   printf("Comando invalido\n\n");
 }
}

int vazia(node *LISTA)//Esta fu��o verifica "pela cabe�a" se a lista est� vazia (1-sim e 0-n�o)
{
 if(LISTA->prox == NULL)
  return 1;
 else
  return 0;
}

node *aloca() //Esta fun��o aloca espa�o para uma estrutura n� ser usada
{
 node *novo=(node *) malloc(sizeof(node));
 if(!novo){
  printf("Sem memoria disponivel!\n");
  exit(1);
 }else{
  printf("Novo elemento: "); 
  scanf("%d", &novo->num);
  return novo;
 }
}


void insereFim(node *LISTA)//Fun��o que insere um novo n� ao fim da lista
{
 node *novo=aloca();//O ponteiro tipo n� � o novo elemento
 novo->prox = NULL;//Como ele ser� incluido ao fim da lista seu ponteiro aponta para NULL representando o fim da lista 
 
 if(vazia(LISTA))//se a lista for vazia sua "head" aponte o n� "novo"
  LISTA->prox=novo;
 else{//se n�o o ponteiro pr�ximo � passado para um n� temporario 
  node *tmp = LISTA->prox;
  
  while(tmp->prox != NULL)//esse n� tempor�rio aponta para todas as posi��es sucessoras em um la�o de repeti��o at� encontrar o fim da lista 
   tmp = tmp->prox;//avan�a "tmp" apontando o valor pr�ximo dentro da lista
	tmp->prox = novo;//encontrado o final da lista o n� tempor�rio passa sua posi��o e valor para o n� "novo".
 }
 tam++;
}

void insereInicio(node *LISTA)
{
 node *novo=aloca();//O ponteiro tipo n� � o novo elemento
 node *oldHead = LISTA->prox;//"oldHead" � criado para preservar a cabe�a da lista, ou seja n�o perder a referencia do local apontado como pr�ximo elementoda lista.
 
 LISTA->prox = novo;//Agora podemos apontar a cabe�a da lista para o n� "novo" com seguran�a
 novo->prox = oldHead;//Por fim apontamos o n� novo para o local de aloca��o da "antiga cabe�a" da lista "ligando" o elemenento ao in�co da mesma. 
 
 tam++;
}

void exibe(node *LISTA)//A fun��o exibe � respons�vel pela impress�o da lista 
{
 if(vazia(LISTA))//verificando se a lista esta vazia
 {
  printf("Lista vazia!\n\n");
  return ;
 }
 
 node *tmp; //Criando um n� tempor�rio "tmp"  
 
 tmp = LISTA->prox; // tmp aponta no inicio para a cabe�a da lista 
 
 printf("Lista:");
 
 while( tmp != NULL)
 { //Neste la�o de repeti��o � impresso o valor interio do n� "tmp->num" e tmp avan�a apontando para o proximo valor at� chegar no final. 
  printf("%5d", tmp->num);
  tmp = tmp->prox;
 }
 
 
 printf("\n        ");
 int count;
 for(count=0 ; count < tam ; count++)
  printf("  ^  ");
 printf("\nOrdem:");
 for(count=0 ; count < tam ; count++)
  printf("%5d", count+1);
 printf("\n\n");
}

void libera(node *LISTA) //Esta fun��o libera todos os n�s, ela "apaga" nossa lista.
{
 if(!vazia(LISTA)){ //Verifica se a lista n�o esta vazia.
  node *proxNode, *atual; //Aqui s�o criados o n� "atual" respons�vel por inicalmente apontar para a cabe�a e "proxNode" que "caminhara" na lista junto a  
  //atual, "proxNode" apontara para o atual pr�ximo para que com a libera��o do n� atual n�o se perca o local de pr�ximo.
  atual = LISTA->prox;
  while(atual != NULL){
   proxNode = atual->prox;
   free(atual);
   atual = proxNode;
  }
 }
}

void insere(node *LISTA)
{
 int pos,
  count;
 printf("Em que posicao, [de 1 ate %d] voce deseja inserir: ", tam);
 scanf("%d", &pos);
 
 if(pos>0 && pos <= tam){
  if(pos==1)
   insereInicio(LISTA);
  else{
   node *atual = LISTA->prox, *anterior=LISTA; 
   node *novo=aloca();
     
   for(count=1 ; count < pos ; count++){
     anterior=atual;
     atual=atual->prox;
   }
   anterior->prox=novo;
   novo->prox = atual;
   tam++;
  }
   
 }else
  printf("Elemento invalido\n\n");  
}

node *retiraInicio(node *LISTA)//Est� fun��o retira um n� do in�cio da lista
{
 if(LISTA->prox == NULL){ //Testa se a pilha est� vazia.
  printf("Lista ja esta vazia\n");
  return NULL;
 }else{ //Se n�o vazia, � criado um n� tempor�rio "tmp" que apontara para a posi��o do primeiro elemento
  node *tmp = LISTA->prox; //"tmp" agora possui o endere�o do primeiro elemento
  LISTA->prox = tmp->prox; //No in�cio "LISTA->prox" aponta para o primeiro elemento, como "tmp" agora tem endere�o de primeiro elemento 
  //� feito com que "LISTA->prox" receba o endere�o de segundo (que agora � o primeiro na lista). Portanto aponta o proximo do primeiro "tmp->prox".  
  tam--;
  return tmp; //Atente-se que este antigo primeiro n�, apenas foi "solto" da lista, ele ainda existe na mem�ria da maquina e est� sendo apontado por "tmp".
 }
    
}

node *retiraFim(node *LISTA)//Fun��o para retirar o �ltimo n� da lista 
{
 if(LISTA->prox == NULL){//Verifica se a lista j� est� vazia
  printf("Lista ja vazia\n\n");
  return NULL;
 }else{
  node *ultimo = LISTA->prox, *penultimo = LISTA; //Para retirar o �ltimo � necessario que o pen�ltimo n� aonte para NULL, s�o criados dois n�s para percorrer a lista
    //"ultimo" inicialmente recebe o primeiro n� para percorrer a lista
  while(ultimo->prox != NULL){
   penultimo = ultimo; //Antes do "ultimo" avan�ar at� o �ltimo elemento que aponta NULL, "penultimo" deve apontar para o endere�o de "ultimo"
   ultimo = ultimo->prox; //"ultimo" segue avan�ando at� apontar NULL
  }
    //assim que "ultimo" apontar para NULL, "penultimo" j� aponta para "ultimo"
  penultimo->prox = NULL; //Ent�o basta fazer "penultimo" apontar para NULL, "soltando" �ltimo e sendo reconhecido a partir de agora como �ltimo elemento da lista. 
  tam--;
  return ultimo;  //Atente-se que este antigo �ltimo n�, apenas foi "solto" da lista, ele ainda existe na mem�ria da maquina e est� sendo apontado por "ultimo".
 }
}

node *retira(node *LISTA)
{
 int opt,
  count;
 printf("Que posicao, [de 1 ate %d] voce deseja retirar: ", tam);
 scanf("%d", &opt);
 
 if(opt>0 && opt <= tam){
  if(opt==1)
   return retiraInicio(LISTA);
  else{
   node *atual = LISTA->prox, *anterior=LISTA; 
     
   for(count=1 ; count < opt ; count++){
    anterior=atual;
    atual=atual->prox;
   }
   
  anterior->prox=atual->prox;
  tam--;
  return atual;
  }
   
 }else{
  printf("Elemento invalido\n\n");
  return NULL;
 }
}
