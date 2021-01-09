#include <stdio.h>
#include <stdlib.h>

//mergesort

#include <time.h>
#include <math.h>

/*Troca dois elementos {i,j} de posição.*/
void Swap (int *A, int i, int j) {
  int aux = A[i];
  A[i] = A[j];
  A[j] = aux;
}

/*Imprime o vetor:*/
void Imprimir (int *A, int tamanho) {
  int i;
  printf("Vetor:\n");
  for (i = 0; i < tamanho; i++) {
    printf("%d ", A[i]);
  }
  printf("\n");
}

/*Função que retorna 1 se a ordenação estiver correta e 0 caso contrário.*/
int Verifica_Ordenacao (int *A, int tamanho) {
   int i;
   for (i = 0; i < tamanho-1; i++) {
      if (A[i] > A[i+1]) {
         return 0;
      }
   }
   return 1;
}

void Intercalar (int vetor[], int esq, int meio, int dir, int Vaux[]) {

   int k = esq;
   int i = esq, j = meio+1;

   while(i <= meio && j <= dir){

    if(vetor[i] < vetor[j]){

        Vaux[k] = vetor[i];
        i++;

    }
    else{

      Vaux[k] = vetor[j];
      j++;
    }

    k++;

   }

   while(i <= meio){

     Vaux[k] = vetor[i];
     k++;
     i++;

   }

   while(j <= dir){

     Vaux[k] = vetor[j];
     k++;
     j++;

   }

   for(k = esq; k <= dir; k++){

     vetor[k] = Vaux[k];

   }

}

void MergeSort(int V[], int esq, int dir, int Vaux[]){

    if(esq < dir){

    int mid = (esq + dir)/2;

    MergeSort(V, esq, mid, Vaux);
    MergeSort(V, mid+1, dir, Vaux);
    Intercalar(V, esq, mid, dir, Vaux);
  }

}


int main()
{
    int i, tamanho = 10;
   clock_t start, end;
   double elapsed_time;
   srand(time(NULL));
   int *v = (int *)malloc(tamanho * sizeof(int));
   int *vaux = (int *)malloc(tamanho * sizeof(int));
   for (i = 0; i < tamanho; i++) {
      v[i] = rand() % (tamanho+1); /*aleatório*/
      //v[i] = i; /*crescente*/
      //v[i] = tamanho - i; /*decrescente*/
   }
   Imprimir (v, tamanho);
   start = clock();
   MergeSort (v, 0, tamanho-1, vaux);
   end = clock();
   elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
   printf("Tempo de execução (Quick-Sort): %.2f\n", elapsed_time);
   if (!Verifica_Ordenacao(v, tamanho)) {
      printf("Erro: a ordenação não está correta!\n");
   }
   Imprimir (v, tamanho);
   free (v);
   free (vaux);
    return 0;
}
