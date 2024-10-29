n, m = (int(tmp) for tmp in input().split(" "))

matrizAdj = [[0 for col in range(n)] for row in range(n)]
for i in range (0, m):
  i, j, peso = (int(tmp) for tmp in input().split(" "))
  matrizAdj[i][j] = peso

for i in range (0, n):
  saida = "%d: " % i
  for j in range (0, n):
    if matrizAdj[i][j] > 0:
      saida += "%d(%d) " % (j, matrizAdj[i][j])
  print (saida)