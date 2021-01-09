#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Definição de uma imagem.*/
typedef struct _imagem {
  int nlinhas;   /*Número de linhas da imagem.*/
  int ncolunas;   /*Número de colunas da imagem.*/
  int **mat;  /*Matriz para armazenar os pixels.*/
} Imagem;

/*Alocando a estrutura da imagem.*/
Imagem* aloca_imagem (int nlinhas, int ncolunas) {
  int i;
  Imagem *img = (Imagem *)malloc(sizeof(Imagem));
  img->nlinhas = nlinhas;
  img->ncolunas = ncolunas;
  img->mat = (int **)malloc(ncolunas * sizeof(int *));
  for (i = 0; i < ncolunas; i++) {
    img->mat[i] = (int *)malloc(nlinhas * sizeof(int));
  }
  return img;
}

/*Liberando estruturas da imagem.*/
void desaloca_imagem (Imagem *img) {
  int i;
  for (i = 0; i < img->ncolunas; i++) {
    free(img->mat[i]);
  }
  free(img->mat);
  free(img);
}

Imagem* Processamento (Imagem *img, int tamanho_da_janela) {
  /*Terminar!*/
}

int main () {
  /**/
  FILE *fin  = fopen("lena.pgm", "r");
  FILE *fout = fopen("saida.pgm", "w");
  int tamanho_da_janela = 3; /*Teste com tamanhos: 3, 5, 7, 9, ... (sempre ímpar)*/

  /*Lendo a imagem:*/
  int nlinhas, ncolunas, nlevels;
  char *type = (char *)malloc(sizeof(char));
  fscanf(fin, "%s", type);
  fscanf(fin, "%d %d %d", &ncolunas, &nlinhas, &nlevels);
  Imagem *imagem_entrada = aloca_imagem (nlinhas, ncolunas);
  int i, j;
  for (j = 0; j < imagem_entrada->nlinhas; j++) {
    for (i = 0; i < imagem_entrada->ncolunas; i++) {
      fscanf(fin, "%d", &(imagem_entrada->mat[i][j]));
    }
  }
  fclose(fin);

  /*Processando a imagem para remocao de ruido:*/
  Imagem *imagem_saida = Processamento (imagem_entrada, tamanho_da_janela);

  /*Gravando a imagem com o resultado do processamento:*/
  fprintf(fout, "%s\n%d %d\n%d\n", type, imagem_saida->ncolunas, imagem_saida->nlinhas, nlevels);
  for (j = 0; j < imagem_saida->nlinhas; j++) {
    for (i = 0; i < imagem_saida->ncolunas; i++) {
      fprintf(fout, "%d ", imagem_saida->mat[i][j]);
      if ( (j != 0) && ((j % 12) == 0) ) {
        fprintf(fout, "\n");
      }
    }
  }
  fclose(fout);
  desaloca_imagem (imagem_entrada);
  //desaloca_imagem (imagem_saida);
  return 0;
}


