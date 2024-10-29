def dfs(v, adj, visitado, entrada, saida, tempo):
    visitado[v] = True
    tempo[0] += 1
    entrada[v] = tempo[0]

    # Visitar todos os vizinhos não visitados
    for vizinho in adj[v]:
        if not visitado[vizinho]:
            dfs(vizinho, adj, visitado, entrada, saida, tempo)

    tempo[0] += 1
    saida[v] = tempo[0]

n, m = map(int, input().split())
adj = [[] for _ in range(n)] 

for _ in range(m):
    u, v = map(int, input().split())
    adj[u].append(v)

visitado = [False] * n
entrada = [-1] * n
saida = [-1] * n
tempo = [0]  

dfs(0, adj, visitado, entrada, saida, tempo)

if (-1 in entrada):
  dfs(entrada.index(-1), adj, visitado, entrada, saida, tempo)

print(entrada)
print(saida)
