#EP5_1
def busca_elemento():
    linhas = int(input())
    colunas = int(input())

    matriz = [[0 for j in range(colunas)] for i in range(linhas)]
    for i in range(linhas):
        for j in range(colunas):
            matriz[i][j] = int(input())

    nBuscado = int(input())
    ok = []
    for i in range(linhas):
        for j in range(colunas):
            if nBuscado == matriz[i][j]:
                ok.append(f"{i+1} {j+1}")

    if len(ok) > 0:
        print(ok[0])
    else:
        print(-1)
busca_elemento()