#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define count 100

void merge(int item[], int n);
void mergeSort(int v[], int n);

int main(void)
{
    int item[count * 100];

    //incrementanod array
    int i;
    srand(time(NULL));
    for (i = 0; i < count; i++)
    {
        item[i] = rand() % 100;
    }
    printf("\n-Teste com 100 elementos");
    printf("\nForma desordenada: ");
    for (i = 0; i < count; i++)
    {
        printf("%i, ", item[i]);
    }

    //ordenando elementos
    mergeSort(item, count);
    printf("\n");
    printf("\nForma ordenada: ");
    for (i = 0; i < count; i++)
    {
        printf("%i, ", item[i]);
    }
    free(item);

    //teste com 1000 elementos
     for ( i = 0; i < (count*10); i++)
     {
         item[i] = rand()%1000;
     }
     printf("\n\n-Teste com 1000 elementos");
     printf("\nForma desordenada: ");
     for ( i = 0; i < (count*10); i++)
     {
         printf("%i, ",item[i]);
     }

     //ordenando elementos
     mergeSort(item, (count*10));
     printf("\n");
     printf("\nForma ordenada: ");
     for ( i = 0; i < (count*10); i++)
     {
         printf("%i, ",item[i]);
     }
     free(item);

     //teste com 10000 elementos
     for ( i = 0; i < (count*100); i++)
     {
         item[i] = rand()%10000;
     }
     printf("\n\n-Teste com 10000 elementos");
     printf("\nForma desordenada: ");
     for ( i = 0; i < (count*100); i++)
     {
         printf("%i, ",item[i]);
     }

     //ordenando elementos
     mergeSort(item, (count*100));
     printf("\n");
     printf("\nForma ordenada: ");
     for ( i = 0; i < (count*100); i++)
     {
         printf("%i, ",item[i]);
     }
     free(item);
}

void merge(int v[], int n)
{
    int meio, i, j, k;
    int *auxiliar;
    auxiliar = (int *)malloc(n * sizeof(int));
    if (auxiliar == NULL)
    {
        return;
    }
    meio = n / 2;
    i = 0;
    k = 0;
    j = meio;
    while (i < meio && j < n)
    {
        if (v[i] <= v[j])
        {
            auxiliar[k] = v[i++];
        }
        else
        {
            auxiliar[k] = v[j++];
        }
        ++k;
    }
    if (i == meio)
    {
        while (j < n)
        {
            auxiliar[k++] = v[j++];
        }
    }
    else
    {
        while (i < meio)
        {
            auxiliar[k++] = v[i++];
        }
    }
    for (i = 0; i < n; ++i)
    {
        v[i] = auxiliar[i];
    }
    free(auxiliar);
}

void mergeSort(int v[], int n)
{
    int meio;
    if (n > 1)
    {
        meio = n / 2;
        mergeSort(v, meio);
        mergeSort(v + meio, n - meio);
        merge(v, n);
    }
}
