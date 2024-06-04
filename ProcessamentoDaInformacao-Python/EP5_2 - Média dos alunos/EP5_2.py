def calculo_media():
    n_linhas = int(input())
    n_colunas = int(input())
    matriz = [[0 for c in range(n_colunas)] for l in range(n_linhas)]
    matrizMedia = [[0 for c in range(n_colunas + 1)] for l in range(n_linhas)]

    for linha in range(n_linhas):
        itens_linha = input().split(" ")
        for coluna in range(n_colunas):
            matriz[linha][coluna] = float(itens_linha[coluna])

    for i in range(len(matrizMedia)):
        media = 0.00
        for j in range(len(matrizMedia[0])):
            if j <= (n_colunas - 1):
                matrizMedia[i][j] = matriz[i][j]
                media = media + matriz[i][j]
            else:
                matrizMedia[i][j] = media/(j)

    for i in range(len(matrizMedia)):
        for j in range(len(matrizMedia[i])):
            print(f"{matrizMedia[i][j]:.2f} ", end="")
        print()
calculo_media()