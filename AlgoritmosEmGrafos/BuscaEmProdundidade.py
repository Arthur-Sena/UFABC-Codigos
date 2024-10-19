def dfs_visit(graph, vertex, visited, discovery_time, finish_time, time):
    visited[vertex] = True
    time[0] += 1
    discovery_time[vertex] = time[0]
    
    for neighbor in graph[vertex]:
        if not visited[neighbor]:
            dfs_visit(graph, neighbor, visited, discovery_time, finish_time, time)
    
    time[0] += 1
    finish_time[vertex] = time[0]

def dfs(graph, n):
    visited = [False] * n
    discovery_time = [0] * n
    finish_time = [0] * n
    time = [0]
    
    dfs_visit(graph, 0, visited, discovery_time, finish_time, time)
    
    print(discovery_time)
    print(finish_time)


n, m = map(int, input().split())

graph = [[] for _ in range(n)]

for _ in range(m):
    u, v = map(int, input().split())
    graph[u].append(v)

dfs(graph, n)