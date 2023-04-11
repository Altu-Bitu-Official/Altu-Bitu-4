from copy import deepcopy

N = int(input())
root = [list(map(int, input().split())) for _ in range(N)] # 초기 상태


def left(graph):
    for r in range(N):
        # graph[r][p]와 graph[r][c]를 비교
        p = 0
        for c in range(1, N):
            # graph[r][c] == 0이면 pass
            if graph[r][c]:
                tmp = graph[r][c]
                # graph[r][c]는 이동할 예정이므로, 0
                graph[r][c] = 0

                if graph[r][p] == 0:
                    graph[r][p] = tmp
                elif graph[r][p] == tmp:
                    graph[r][p] *= 2
                    p += 1
                else:
                    p += 1
                    graph[r][p] = tmp
    return graph


def right(graph):
    for r in range(N):
        p = N - 1
        for c in range(N - 2, -1, -1):
            if graph[r][c]:
                tmp = graph[r][c]
                graph[r][c] = 0
                if graph[r][p] == 0:
                    graph[r][p] = tmp
                elif graph[r][p] == tmp:
                    graph[r][p] *= 2
                    p -= 1
                else:
                    p -= 1
                    graph[r][p] = tmp
    return graph


def up(graph):
    for c in range(N):
        p = 0
        for r in range(1, N):
            if graph[r][c]:
                tmp = graph[r][c]
                graph[r][c] = 0

                if graph[p][c] == 0:
                    graph[p][c] = tmp
                elif graph[p][c] == tmp:
                    graph[p][c] *= 2
                    p += 1
                else:
                    p += 1
                    graph[p][c] = tmp
    return graph


def down(graph):
    for c in range(N):
        p = N - 1
        for r in range(N - 2, -1, -1):
            if graph[r][c]:
                tmp = graph[r][c]
                graph[r][c] = 0
                if graph[p][c] == 0:
                    graph[p][c] = tmp
                elif graph[p][c] == tmp:
                    graph[p][c] *= 2
                    p -= 1
                else:
                    p -= 1
                    graph[p][c] = tmp
    return graph


def dfs(node, depth):
    _max = [0 for _ in range(4)]
    if depth == 5:
        return max(map(max, node))

    _max[0] = dfs(up(deepcopy(node)), depth + 1)
    _max[1] = dfs(down(deepcopy(node)), depth + 1)
    _max[2] = dfs(left(deepcopy(node)), depth + 1)
    _max[3] = dfs(right(deepcopy(node)), depth + 1)
    return max(_max)


print(dfs(root, 0))
