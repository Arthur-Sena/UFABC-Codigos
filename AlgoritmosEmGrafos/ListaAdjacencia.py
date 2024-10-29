entrada = input().split(" ")

n = int(entrada[0])
m = int(entrada[1])

listaAdjacencia = []

for k in range(m):
  i, j = (int(tmp) for tmp in input().split(" "))
  listaAdjacencia.append((i, j))


for i in range(n):
  texto = "%d: " % i

  listConexao = [n[1] for n in listaAdjacencia if n[0] == i]
  for j in range(len(listConexao)):
    texto += "%d " % listConexao[j]
  print(texto)