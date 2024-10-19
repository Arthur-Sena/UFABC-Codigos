from collections import deque

def bfs(grafo, s):
    n = len(grafo)
    distancias = [-1] * n  # Inicializa as distâncias com -1 (não visitado)
    distancias[s] = 0
    fila = deque([s])

    while fila:
        u = fila.popleft()
        for v in grafo[u]:
            if distancias[v] == -1:
                distancias[v] = distancias[u] + 1
                fila.append(v)

    return distancias

# Lendo a entrada
n, m, s = map(int, input().split())
grafo = [[] for _ in range(n)]
for _ in range(m):
    u, v = map(int, input().split())
    grafo[u].append(v)
    grafo[v].append(u)  # Se o grafo for não direcionado

# Realizando a BFS e imprimindo as distâncias
distancias = bfs(grafo, s)
print(" ".join(map(str, distancias)))