#include <stdio.h>
#define M 5
#define N 3

int main(){

    int matriz[M][M];
    int matriz2[M][M];
    int vetor[N*N];
    int cont = 0;
    int *v = (int *)malloc(tamanho * sizeof(int));
   int *vaux = (int *)malloc(tamanho * sizeof(int));

    matriz[0][0] = 10;
    matriz[0][1] = 18;
    matriz[0][2] = 21;
    matriz[0][3] = 0;
    matriz[0][4] = 8;
    matriz[1][0] = 1;
    matriz[1][1] = 7;
    matriz[1][2] = 2;
    matriz[1][3] = 7;
    matriz[1][4] = 1;
    matriz[2][0] = 0;
    matriz[2][1] = 9;
    matriz[2][2] = 34;
    matriz[2][3] = 23;
    matriz[2][4] = 12;
    matriz[3][0] = 16;
    matriz[3][1] = 18;
    matriz[3][2] = 6;
    matriz[3][3] = 15;
    matriz[3][4] = 19;
    matriz[4][0] = 1;
    matriz[4][1] = 18;
    matriz[4][2] = 3;
    matriz[4][3] = 23;
    matriz[4][4] = 4;
    

    for(int i = 0; i < M; i++){

        for(int j = 0; j < M; j++){

            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    //tratamento da matriz

    for(int i = 0; i < M; i++){

        for(int j = 0; j < M; j++){

            if((i == 0) || (i == M-1) || (j == 0) || (j == M-1)){

                matriz2[i][j] = 0;
            }

            else{

                cont = 0;
                for(int k = i; k < (i+N); k++){

                    for(int l = j; l < (j+N); l++){

                        v[cont] = matriz[k][l];
                        cont++;
                    }

                }                

                int mediana = mergeSortEdit(v, 0, tamanho-1, vaux);
                matriz2[i][j] = mediana;
            }

        }
        
    }

    return 0;
}