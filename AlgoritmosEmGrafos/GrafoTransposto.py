n, m = map(int, input().split())

grafo_transposto = [[] for _ in range(n)]

for _ in range(m):
    u, v = map(int, input().split())
    grafo_transposto[v].append(u) 

for i in range(n):
    print(f"{i}: {' '.join(map(str, grafo_transposto[i]))}")