#include <stdio.h>

int main(){
    FILE * in;
    FILE * out;

    in = fopen("C:\Users\arthu\Downloads\NI\monalisa.pgm", "rt");
    if (in == NULL){
       printf("Erro ao abrir o arquivo");
       return 1;
    }

    out=fopen("C:\Users\arthu\Downloads\NI\emotions-g967044596_640.pgm", "wt");
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

// Gerar novo imagem em preto e branco (cores limitadas entre 70 e 190)
    i=0, j=0;
    for(j=0; j<coluna; j++) {    
         if(150<imagem[i][j]){
       	    imagem[i][j] = 190;//255-imagem[i][j];
            fprintf(out, "%d\n", imagem[i][j]);
         }else if(140>imagem[i][j]){
       	    imagem[i][j]=70;//255-imagem[i][j];
            fprintf(out, "%d\n", imagem[i][j]);
         } else {
            fprintf(out, "%d\n", imagem[i][j]);
         }
       }
    }
}