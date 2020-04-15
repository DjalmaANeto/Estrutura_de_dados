#include <stdio.h>
#include <stdlib.h>
#define QUANTIDADE_DE_ALUNOS 3
typedef struct {
        char nome[25];
        float nota1;
        float nota2;
        float media;
}Aluno;
int main(){
        Aluno alunos[QUANTIDADE_DE_ALUNOS];
  		int i,j;
        Aluno aux;
        for( i=0;i < QUANTIDADE_DE_ALUNOS; i++)
		{
                printf("\nInforme os dados do aluno(%i): ",i+1);
                printf("\nNome: ");
                scanf("%s",alunos[i].nome);
               
                printf("\nNota 1: ");
                scanf("%f",&alunos[i].nota1);
                printf("\nNota 2: ");
                scanf("%f",&alunos[i].nota2);
                
                alunos[i].media=((alunos[i].nota1*2)+(alunos[i].nota2*3))/5;
                        
        }
        for(j=1; j<QUANTIDADE_DE_ALUNOS; j++)
			{
				for(i=0; i<(QUANTIDADE_DE_ALUNOS-1); i++)
				{
					if(alunos[i].media > alunos[i+1].media)
					{
						aux = alunos[i];
						alunos[i] = alunos[i+1];
						alunos[i+1] = aux;
						
					}
				}
			
			}
        printf("\n\t\t Medias ordenadas \n ");
        printf("\nNome ----------  Media\n ");
        for(i=0;i <QUANTIDADE_DE_ALUNOS; i++)
		{
                printf("%s ---------- %1.2f\n",alunos[i].nome,alunos[i].media);
        }
        for(i=0;i<QUANTIDADE_DE_ALUNOS;i++) 
		{
		  if (strcmp (alunos[i].nome,alunos[i+1].nome) < 0)
		  {
		  				aux = alunos[i];
						alunos[i] = alunos[i+1];
						alunos[i+1] = aux;		  
		  }
		}
		printf("\n Situacao\n ");
        for(i=0;i < QUANTIDADE_DE_ALUNOS; i++)
		{
                if(alunos[i].media > 7)
                {
                	printf("%s ---------- %1.2f ------ Aprovado \n",alunos[i].nome,alunos[i].media);
				}
				else
				{
					printf("%s ---------- %1.2f ------ Reprovado \n",alunos[i].nome,alunos[i].media);
				}
			
        }
		   


        getchar();
        return 0;
}
