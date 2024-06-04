#include <stdio.h>

int main(){
    FILE * in;
    FILE * out;

    in = fopen("monalisa.pgm", "rt");
    if (in == NULL){
       printf("Erro ao abrir o arquivo");
       return 1;
    }

    out=fopen("teste.pgm", "wt");
    if (out == NULL){
       printf("Erro ao abrir o arquivo");
       return 1;
    }

    char line[3024];
    fscanf(in, "%[^\n]\n", line);
    fprintf(out, "%s\n", line);

    int coluna, linha, intensidade_maxima;
    
    fscanf(in, "%d %d", &coluna, &linha);
    fprintf(out, "%d %d\n", coluna, linha);

    fscanf(in, "%d", &intensidade_maxima);
    fprintf(out, "%d\n", intensidade_maxima);

    int imagem[linha][coluna];     

// Copiar o conteúdo do arquivo para a matriz imagem[][]
    int i=0, j=0;
    for(i=0; i<linha; i++) {
       for(j=0; j<coluna; j++) {
          int pixel;
          fscanf(in, "%d", &pixel);
          //fprintf(out, "%d\n", pixel);
          imagem[i][j] = pixel;
       }
    }

/*
AS ALTERAÇÕES DEVEM SER REALIZADAS A PARTIR DESTE PONTO
*/

// Gerar novo arquivo rotacionado na vertical
    i=0, j=0;
    for(i=0; i<linha; i++) {
       for(j=coluna-1; j>=0; j--) {
          fprintf(out, "%d\n", imagem[i][j]);
       }
    }
}
