from collections import deque
N = int(input())
que = deque()
ans = ""

for _ in range(N):
    inp = input().split()
    command = inp[0]

    if command == 'push':
        que.append(int(inp[1]))
    elif command == 'pop':
        if len(que) == 0:
            ans += str(-1) + '\n'
        else:
            ans += str(que.popleft()) + '\n'
    elif command == 'size':
        ans += str(len(que)) + '\n'
    elif command == 'empty':
        if len(que) == 0:
            ans += str(1) + '\n'
        else:
            ans += str(0) + '\n'
    elif command == 'front':
        if len(que) == 0:
            ans += str(-1) + '\n'
        else:
            ans += str(que[0]) + '\n'

    else:
        if len(que) == 0:
            ans += str(-1) + '\n'
        else:
            ans += str(que[-1]) + '\n'

print(ans)


