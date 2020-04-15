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

void inicia(node *LISTA)//Esta função inicia a lista 
{
 LISTA->prox = NULL;//observe que ao iniciar a "head" da nossa llista aponta para NULL
 tam=0;
}

int menu(void)//Esta função exibe as opcoes de uso da lista criada para o usuário 
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

void opcao(node *LISTA, int op)//Esta função executa um switch das opcoes possiveis de manipulação da ista criada
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

int vazia(node *LISTA)//Esta fução verifica "pela cabeça" se a lista está vazia (1-sim e 0-não)
{
 if(LISTA->prox == NULL)
  return 1;
 else
  return 0;
}

node *aloca() //Esta função aloca espaço para uma estrutura nó ser usada
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


void insereFim(node *LISTA)//Função que insere um novo nó ao fim da lista
{
 node *novo=aloca();//O ponteiro tipo nó é o novo elemento
 novo->prox = NULL;//Como ele será incluido ao fim da lista seu ponteiro aponta para NULL representando o fim da lista 
 
 if(vazia(LISTA))//se a lista for vazia sua "head" aponte o nó "novo"
  LISTA->prox=novo;
 else{//se não o ponteiro próximo é passado para um nó temporario 
  node *tmp = LISTA->prox;
  
  while(tmp->prox != NULL)//esse nó temporário aponta para todas as posições sucessoras em um laço de repetição até encontrar o fim da lista 
   tmp = tmp->prox;//avança "tmp" apontando o valor próximo dentro da lista
	tmp->prox = novo;//encontrado o final da lista o nó temporário passa sua posição e valor para o nó "novo".
 }
 tam++;
}

void insereInicio(node *LISTA)
{
 node *novo=aloca();//O ponteiro tipo nó é o novo elemento
 node *oldHead = LISTA->prox;//"oldHead" é criado para preservar a cabeça da lista, ou seja não perder a referencia do local apontado como próximo elementoda lista.
 
 LISTA->prox = novo;//Agora podemos apontar a cabeça da lista para o nó "novo" com segurança
 novo->prox = oldHead;//Por fim apontamos o nó novo para o local de alocação da "antiga cabeça" da lista "ligando" o elemenento ao iníco da mesma. 
 
 tam++;
}

void exibe(node *LISTA)//A função exibe é responsável pela impressão da lista 
{
 if(vazia(LISTA))//verificando se a lista esta vazia
 {
  printf("Lista vazia!\n\n");
  return ;
 }
 
 node *tmp; //Criando um nó temporário "tmp"  
 
 tmp = LISTA->prox; // tmp aponta no inicio para a cabeça da lista 
 
 printf("Lista:");
 
 while( tmp != NULL)
 { //Neste laço de repetição é impresso o valor interio do nó "tmp->num" e tmp avança apontando para o proximo valor até chegar no final. 
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

void libera(node *LISTA) //Esta função libera todos os nós, ela "apaga" nossa lista.
{
 if(!vazia(LISTA)){ //Verifica se a lista não esta vazia.
  node *proxNode, *atual; //Aqui são criados o nó "atual" responsável por inicalmente apontar para a cabeça e "proxNode" que "caminhara" na lista junto a  
  //atual, "proxNode" apontara para o atual próximo para que com a liberação do nó atual não se perca o local de próximo.
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

node *retiraInicio(node *LISTA)//Está função retira um nó do início da lista
{
 if(LISTA->prox == NULL){ //Testa se a pilha está vazia.
  printf("Lista ja esta vazia\n");
  return NULL;
 }else{ //Se não vazia, é criado um nó temporário "tmp" que apontara para a posição do primeiro elemento
  node *tmp = LISTA->prox; //"tmp" agora possui o endereço do primeiro elemento
  LISTA->prox = tmp->prox; //No início "LISTA->prox" aponta para o primeiro elemento, como "tmp" agora tem endereço de primeiro elemento 
  //é feito com que "LISTA->prox" receba o endereço de segundo (que agora é o primeiro na lista). Portanto aponta o proximo do primeiro "tmp->prox".  
  tam--;
  return tmp; //Atente-se que este antigo primeiro nó, apenas foi "solto" da lista, ele ainda existe na memória da maquina e está sendo apontado por "tmp".
 }
    
}

node *retiraFim(node *LISTA)//Função para retirar o último nó da lista 
{
 if(LISTA->prox == NULL){//Verifica se a lista já está vazia
  printf("Lista ja vazia\n\n");
  return NULL;
 }else{
  node *ultimo = LISTA->prox, *penultimo = LISTA; //Para retirar o último é necessario que o penúltimo nó aonte para NULL, são criados dois nós para percorrer a lista
    //"ultimo" inicialmente recebe o primeiro nó para percorrer a lista
  while(ultimo->prox != NULL){
   penultimo = ultimo; //Antes do "ultimo" avançar até o último elemento que aponta NULL, "penultimo" deve apontar para o endereço de "ultimo"
   ultimo = ultimo->prox; //"ultimo" segue avançando até apontar NULL
  }
    //assim que "ultimo" apontar para NULL, "penultimo" já aponta para "ultimo"
  penultimo->prox = NULL; //Então basta fazer "penultimo" apontar para NULL, "soltando" último e sendo reconhecido a partir de agora como último elemento da lista. 
  tam--;
  return ultimo;  //Atente-se que este antigo último nó, apenas foi "solto" da lista, ele ainda existe na memória da maquina e está sendo apontado por "ultimo".
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
