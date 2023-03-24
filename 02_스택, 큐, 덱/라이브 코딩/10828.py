N = int(input())
stack = []
ans = ""
for _ in range(N):
    input_list = input().split()
    command = input_list[0]

    if command == 'push':
        stack.append(int(input_list[1]))
    elif command == 'pop':
        if len(stack) == 0:
            ans += str(-1) + '\n'
        else:
            ans += str(stack.pop()) + '\n'
    elif command == 'size':
        ans += str(len(stack)) + '\n'
    elif command == 'empty':
        if len(stack) == 0:
            ans += str(1) + '\n'
        else:
            ans += str(0) + '\n'
    else:
        if len(stack) == 0:
            ans += str(-1) + '\n'
        else:
            ans += str(stack[-1]) + '\n'

print(ans)