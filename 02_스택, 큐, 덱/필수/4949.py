ans = ""
while True:
    sen = input()
    if sen == '.':
        break

    flag = "yes" # yes로 초기화
    stack = [] # 괄호만 저장하는 스택

    for s in sen:
        if s == '(' or s == '[': # 여는 괄호면 스택에 push
            stack.append(s)
        elif s == ')':
            if len(stack) == 0: # 빈 스택이면 no
                flag = "no"
                break
            else:
                if stack.pop() == '(':
                    pass
                else: # top이 ( 가 아니면 no
                    flag = "no"
                    break
        elif s == ']':
            if len(stack) == 0: # 빈 스택이면 no
                flag = "no"
                break
            else:
                if stack.pop() == '[':
                    pass
                else: # top이 [ 가 아니면 no
                    flag = "no"
                    break
        else: # 괄호가 아니면 pass
            pass
    if len(stack) != 0: # 스택에 괄호가 남아있으면
        flag = 'no'
    ans += flag + '\n'

print(ans)