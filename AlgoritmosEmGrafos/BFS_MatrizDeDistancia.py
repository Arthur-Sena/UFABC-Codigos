def bfs(v, n, adj):
    dist = [-1] * n  
    dist[v] = 0  
    fila = [v]  
    
    inicio = 0  
    
    while inicio < len(fila):
        u = fila[inicio]  
        inicio += 1  
        
        for vizinho in adj[u]:
            if dist[vizinho] == -1:  
                dist[vizinho] = dist[u] + 1
                fila.append(vizinho) 
    return dist

n, m = map(int, input().split())
adj = [[] for _ in range(n)]  

for _ in range(m):
    u, v = map(int, input().split())
    adj[u].append(v)

matrizDistancias = []

for i in range(n):
    distancias = bfs(i, n, adj)
    matrizDistancias.append(distancias)

for i in range(n):
    print(f"{i}: {' '.join(map(str, matrizDistancias[i]))}")
