N = int(input())
l = [[] for _ in range(200)]

for i in range(N):
    age, name = input().split()
    l[int(age)-1].append((age, name))
for sub in l:
    for t in sub:
        print(t[0], t[1])