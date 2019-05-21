import queue
queue = queue.Queue(maxsize=1001)

def input_vertex() :
    str = input()
    return list(map(int, str.split()))


def dfs_traversal(arr, start_point, max_point, result, visited):
    visited[start_point] = True
    result.append(start_point)
    for i in range(max_point):
        if not visited[i] and arr[start_point][i]:
            dfs_traversal(arr, i, max_point, result, visited)


def bfs_traversal(arr, start_point, max_point, result, visited):
    visited[start_point] = True
    queue.put(start_point)
    visited[start_point]
    while not queue.empty():
        n = queue.get()
        result.append(n)
        for i in range(max_point):
            if not visited[i] and arr[n][i]:
                queue.put(i)
                visited[i] = True


str = input()
vertex, line, startPoint = list(map(int, str.split()))
arr = []
for i in range(vertex+1) :
    arr.append([None]*(vertex+1))

for i in range(line):
    start, end = input_vertex()
    arr[start][end] = True
    arr[end][start] = True

dfs_result = []
bfs_result = []

visited = []
for i in range(vertex + 1):
    visited.append(False)
dfs_traversal(arr, startPoint, vertex+1, dfs_result, visited)

visited = []
for i in range(vertex + 1):
    visited.append(False)
bfs_traversal(arr, startPoint, vertex+1, bfs_result, visited)

print(*dfs_result)
print(*bfs_result)





