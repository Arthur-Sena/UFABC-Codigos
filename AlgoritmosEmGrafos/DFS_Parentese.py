#Arthur Sena
#RA: 11202231725

def dfs(v, adj, visitado, resultado):
    visitado[v] = True  
    resultado.append('(' + str(v)) 
    
    for vizinho in adj[v]:
        if not visitado[vizinho]: 
            dfs(vizinho, adj, visitado, resultado)
    
    resultado.append(str(v) + ')') 

n, m = map(int, input().split()) 
adj = [[] for _ in range(n)]  

for _ in range(m):
    u, v = map(int, input().split())
    adj[u].append(v)  

visitado = [False] * n
resultado = []

for i in range(n):
    if not visitado[i]: 
        dfs(i, adj, visitado, resultado)

print(' '.join(resultado))