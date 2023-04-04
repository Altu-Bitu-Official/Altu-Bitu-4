T = int(input())
stack = []
for _ in range(T):
    stack.clear()
    str = input()
    Flag = True
    for s in str:
        if s == '(':
            stack.append('(')
        else:
            if len(stack) == 0:
                Flag = False
                break
            elif stack.pop() == ')':
                Flag = False
                break
    if len(stack) == 0 and Flag:
        print("YES")
    else:
        print("NO")

