#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Time {
    char nome[101];
    int golsPro;
    int golsContra;
    int numVitorias;
    int numEmpates;
    int numDerrotas;
    int saldoGols;
    int pontos;
} Time;

void preencheVetor(Time* vetorTime, int qntTimes);
void preenchePartidas(Time* vetorTime, int qntTimes);
int buscaTime(Time* vetorTime, char* nomeTime, int qntTimes);
void ordenaVetor(Time* vetorTime, int qntTime);
void imprimeCasosEspeciais(Time* time, int qntTime);

int main() {
    int qntTimes;
    scanf("%d", &qntTimes);

    Time* vetorTime = (Time*) malloc(qntTimes * sizeof(Time));
    preencheVetor(vetorTime, qntTimes);

    preenchePartidas(vetorTime, qntTimes);
    ordenaVetor(vetorTime, qntTimes); // Ordena os times
    imprimeCasosEspeciais(vetorTime, qntTimes);

    free(vetorTime); // Libera a memória alocada
    return 0;
}

void preencheVetor(Time* vetorTime, int qntTimes) {
    for (int i = 0; i < qntTimes; i++) {
        scanf("%s", vetorTime[i].nome);
        vetorTime[i].golsPro = 0;
        vetorTime[i].golsContra = 0;
        vetorTime[i].numVitorias = 0;
        vetorTime[i].numEmpates = 0;
        vetorTime[i].numDerrotas = 0;
        vetorTime[i].saldoGols = 0;
        vetorTime[i].pontos = 0;
    }
}

void preenchePartidas(Time* vetorTime, int qntTimes) {
    for (int i = 0; i < qntTimes * (qntTimes - 1); i++) {
        char timeA[101], timeB[101];
        int golA = 0, golB = 0;
        scanf("%s %d x %d %s", timeA, &golA, &golB, timeB);

        int indexA = buscaTime(vetorTime, timeA, qntTimes);
        vetorTime[indexA].golsPro += golA;
        vetorTime[indexA].golsContra += golB;
        vetorTime[indexA].saldoGols = vetorTime[indexA].golsPro - vetorTime[indexA].golsContra;

        int indexB = buscaTime(vetorTime, timeB, qntTimes);
        vetorTime[indexB].golsPro += golB;
        vetorTime[indexB].golsContra += golA;
        vetorTime[indexB].saldoGols = vetorTime[indexB].golsPro - vetorTime[indexB].golsContra;

        if (golA > golB) {
            vetorTime[indexA].numVitorias++;
            vetorTime[indexA].pontos += 3;
            vetorTime[indexB].numDerrotas++;
        } else if (golA == golB) {
            vetorTime[indexA].pontos++;
            vetorTime[indexB].pontos++;
            vetorTime[indexA].numEmpates++;
            vetorTime[indexB].numEmpates++;
        } else {
            vetorTime[indexB].numVitorias++;
            vetorTime[indexB].pontos += 3;
            vetorTime[indexA].numDerrotas++;
        }
    }
}

int buscaTime(Time* vetorTime, char* nomeTime, int qntTimes) {
    for (int i = 0; i < qntTimes; i++)
        if (strcmp(vetorTime[i].nome, nomeTime) == 0)
            return i;
    return -1;
}

void ordenaVetor(Time* vetorTime, int qntTime) {
    for (int i = 0; i < qntTime - 1; i++) {
        for (int j = 0; j < qntTime - i - 1; j++) {
            bool trocar = false;

            if (vetorTime[j].pontos < vetorTime[j + 1].pontos) {
                trocar = true;
            }
            else if (vetorTime[j].pontos == vetorTime[j + 1].pontos) {
                if (vetorTime[j].numVitorias < vetorTime[j + 1].numVitorias) {
                    trocar = true;
                }
                else if (vetorTime[j].numVitorias == vetorTime[j + 1].numVitorias) {
                    if (vetorTime[j].saldoGols < vetorTime[j + 1].saldoGols) {
                        trocar = true;
                    }
                    else if (vetorTime[j].saldoGols == vetorTime[j + 1].saldoGols) {
                        if (vetorTime[j].golsPro < vetorTime[j + 1].golsPro) {
                            trocar = true;
                        }
                    }
                }
            }

            if (trocar) {
                Time temp = vetorTime[j];
                vetorTime[j] = vetorTime[j + 1];
                vetorTime[j + 1] = temp;
            }
        }
    }
}

void imprimeCasosEspeciais(Time* time, int qntTime) {
    printf("CAMPEAO: %s\n", time[0].nome);
    printf("VICE-CAMPEAO: %s\n", time[1].nome);
    printf("REBAIXADOS: %s, %s, %s e %s\n", time[qntTime - 1].nome, time[qntTime - 2].nome, time[qntTime - 3].nome, time[qntTime - 4].nome);

    printf("TABELA FINAL:\n");
    for (int i = 0; i < qntTime; i++)
        printf("%s %d %d %d %d %d %d %d\n", time[i].nome, time[i].pontos, time[i].numVitorias, time[i].numEmpates, time[i].numDerrotas, time[i].saldoGols, time[i].golsPro, time[i].golsContra);
}