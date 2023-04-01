from collections import deque
N = int(input())
deq = deque()
ans = ""

for _ in range(N):
    inp = input().split()
    command = inp[0]

    if command == 'push_front':
        deq.appendleft(int(inp[1]))
    elif command == 'push_back':
        deq.append(int(inp[1]))
    elif command == 'pop_front':
        if len(deq) == 0:
            ans += str(-1) + '\n'
        else:
            ans += str(deq.popleft()) + '\n'
    elif command == 'pop_back':
        if len(deq) == 0:
            ans += str(-1) + '\n'
        else:
            ans += str(deq.pop()) + '\n'
    elif command == 'size':
        ans += str(len(deq)) + '\n'
    elif command == 'empty':
        if len(deq) == 0:
            ans += str(1) + '\n'
        else:
            ans += str(0) + '\n'
    elif command == 'front':
        if len(deq) == 0:
            ans += str(-1) + '\n'
        else:
            ans += str(deq[0]) + '\n'
    else:
        if len(deq) == 0:
            ans += str(-1) + '\n'
        else:
            ans += str(deq[-1]) + '\n'

print(ans)