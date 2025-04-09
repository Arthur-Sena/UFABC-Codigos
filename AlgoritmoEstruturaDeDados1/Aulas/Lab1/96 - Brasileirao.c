#include <stdio.h>
#include <string.h>

int N; // quantidade de times

typedef struct
{
    char nome[100];
    int pontos;
    int vitorias;
    int empates;
    int derrotas;
    int saldoDeGols;
    int golsPro;
    int golsContra;
} Time;

void nomeiaTimes(Time times[])
{
    for (int i = 0; i < N; i++)
    {
        scanf("%s", times[i].nome);
        times[i].pontos = 0;
        times[i].vitorias = 0;
        times[i].empates = 0;
        times[i].derrotas = 0;
        times[i].saldoDeGols = 0;
        times[i].golsPro = 0;
        times[i].golsContra = 0;
    }
}

int obterIndiceDoTime(Time times[], char *nome)
{
    for (int i = 0; i < N; i++)
        if (strcmp(times[i].nome, nome) == 0)
            return i;
    return -1;
}

void atualizaTabela(Time times[], char *timeM, int golsM, char *timeV, int golsV)
{
    int iTimeM = obterIndiceDoTime(times, timeM);
    int iTimeV = obterIndiceDoTime(times, timeV);

    if (golsM > golsV)
    {
        times[iTimeM].pontos += 3;
        times[iTimeM].vitorias++;
        times[iTimeV].derrotas++;
    }
    if (golsM < golsV)
    {
        times[iTimeV].pontos += 3;
        times[iTimeV].vitorias++;
        times[iTimeM].derrotas++;
    }
    if (golsM == golsV)
    {
        times[iTimeM].pontos++;
        times[iTimeV].pontos++;
        times[iTimeM].empates++;
        times[iTimeV].empates++;
    }

    times[iTimeM].saldoDeGols += golsM - golsV;
    times[iTimeV].saldoDeGols += golsV - golsM;

    times[iTimeM].golsPro += golsM;
    times[iTimeV].golsPro += golsV;

    times[iTimeM].golsContra += golsV;
    times[iTimeV].golsContra += golsM;
}

void imprimirClassificacao(Time times[])
{
    printf("CAMPEAO: %s\n", times[0].nome);
    printf("VICE-CAMPEAO: %s\n", times[1].nome);
    printf("REBAIXADOS:");
    printf(" %s,", times[N - 1].nome);
    printf(" %s,", times[N - 2].nome);
    printf(" %s e", times[N - 3].nome);
    printf(" %s\n", times[N - 4].nome);
}

void imprimirTabelaFinal(Time times[])
{
    printf("TABELA FINAL:\n");
    for (int i = 0; i < N; i++)
    {
        printf("%s", times[i].nome);
        printf(" %d", times[i].pontos);
        printf(" %d", times[i].vitorias);
        printf(" %d", times[i].empates);
        printf(" %d", times[i].derrotas);
        printf(" %d", times[i].saldoDeGols);
        printf(" %d", times[i].golsPro);
        printf(" %d", times[i].golsContra);
        printf("\n");
    }
}

void trocarTimes(Time *a, Time *b)
{
    Time temp = *a;
    *a = *b;
    *b = temp;
}

void classificarTabela(Time times[])
{
    // Ordena por Gols pro
    for (int i = 0; i < N - 1; i++)
        for (int j = 0; j < N - i - 1; j++)
            if (times[j].golsPro < times[j + 1].golsPro)
                trocarTimes(&times[j], &times[j + 1]);

    // Ordena por Saldo de Gols
    for (int i = 0; i < N - 1; i++)
        for (int j = 0; j < N - i - 1; j++)
            if (times[j].saldoDeGols < times[j + 1].saldoDeGols)
                trocarTimes(&times[j], &times[j + 1]);

    // Ordena por Vitorias
    for (int i = 0; i < N - 1; i++)
        for (int j = 0; j < N - i - 1; j++)
            if (times[j].vitorias < times[j + 1].vitorias)
                trocarTimes(&times[j], &times[j + 1]);

    // Ordena por Pontos
    for (int i = 0; i < N - 1; i++)
        for (int j = 0; j < N - i - 1; j++)
            if (times[j].pontos < times[j + 1].pontos)
                trocarTimes(&times[j], &times[j + 1]);
}

int main()
{
    scanf("%d", &N);

    Time times[N];
    nomeiaTimes(times);

    int qtdPartidas = N * (N - 1);

    char timeM[100], timeV[100];
    int golsM, golsV;

    for (int i = 0; i < qtdPartidas; i++)
    {
        scanf("%s %d x %d %s", timeM, &golsM, &golsV, timeV);

        atualizaTabela(times, timeM, golsM, timeV, golsV);
    }

    classificarTabela(times);

    imprimirClassificacao(times);

    imprimirTabelaFinal(times);

    return 0;
}
