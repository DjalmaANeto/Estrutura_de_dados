#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define count 100

void merge(int item[], int n, int *trocas);
void mergeSort(int v[], int n, int *trocas);

int main(void)
{
    int item[count * 100];

    //incrementanod array
    int i;
    int trocas = 0;
    time_t tempo = 0;
    srand(time(NULL));
    for (i = 0; i < count; i++)
    {
        item[i] = rand() % 100;
    }
    printf("\n-Teste com 100 elementos");
    // printf("\nForma desordenada: ");
    // for (i = 0; i < count; i++)
    // {
    //     printf("%i, ", item[i]);
    // }

    //ordenando elementos
    tempo = clock();
    mergeSort(item, count, &trocas);
    tempo = clock() - tempo;
    //  printf("\n");
    // printf("\nForma ordenada: ");
    // for (i = 0; i < count; i++)
    // {
    //     printf("%i, ", item[i]);
    // }
    free(item);
    printf("\n\nTrocas: %i", trocas);
    printf("\nTempo: %lf", ((double)tempo/(CLOCKS_PER_SEC)));
    trocas = 0;
    tempo = 0;

    //teste com 1000 elementos
    for (i = 0; i < (count * 10); i++)
    {
        item[i] = rand() % 1000;
    }
    printf("\n\n-Teste com 1000 elementos");
    printf("\nForma desordenada: ");
    //  for ( i = 0; i < (count*10); i++)
    //  {
    //      printf("%i, ",item[i]);
    //  }

    //ordenando elementos
    tempo = clock();
    mergeSort(item, (count * 10), &trocas);
    tempo = clock() - tempo;
    //  printf("\n");
    //  printf("\nForma ordenada: ");
    //  for ( i = 0; i < (count*10); i++)
    //  {
    //      printf("%i, ",item[i]);
    //  }
    free(item);
    printf("\n\nTrocas: %i", trocas);
    printf("\nTempo: %lf", ((double)tempo/(CLOCKS_PER_SEC)));
    trocas = 0;
    tempo = 0;

    //teste com 10000 elementos
    for (i = 0; i < (count * 100); i++)
    {
        item[i] = rand() % 10000;
    }
    printf("\n\n-Teste com 10000 elementos");
    //  printf("\nForma desordenada: ");
    //  for ( i = 0; i < (count*100); i++)
    //  {
    //      printf("%i, ",item[i]);
    //  }

    //ordenando elementos
    tempo = clock();
    mergeSort(item, (count * 100), &trocas);
    tempo = clock() - tempo;
    //  printf("\n");
    //  printf("\nForma ordenada: ");
    //  for ( i = 0; i < (count*100); i++)
    //  {
    //      printf("%i, ",item[i]);
    //  }
    free(item);
    printf("\n\nTrocas: %i", trocas);
    printf("\nTempo: %lf", ((double)tempo/(CLOCKS_PER_SEC)));
    trocas = 0;
    tempo = 0;
}

void merge(int v[], int n, int *trocas)
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
            *trocas = *trocas + 1;
        }
        else
        {
            auxiliar[k] = v[j++];
            *trocas = *trocas + 1;
        }
        ++k;
    }
    if (i == meio)
    {
        while (j < n)
        {
            auxiliar[k++] = v[j++];
            *trocas = *trocas + 1;
        }
    }
    else
    {
        while (i < meio)
        {
            auxiliar[k++] = v[i++];
            *trocas = *trocas + 1;
        }
    }
    for (i = 0; i < n; ++i)
    {
        v[i] = auxiliar[i];
    }
    free(auxiliar);
}

void mergeSort(int v[], int n, int *trocas)
{
    int meio;
    if (n > 1)
    {
        meio = n / 2;
        mergeSort(v, meio, trocas);
        mergeSort(v + meio, n - meio, trocas);
        merge(v, n, trocas);
    }
}
