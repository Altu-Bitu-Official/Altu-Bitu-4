n = int(input())
s = set()

for _ in range(n):
    name, isAttend = input().split()
    if isAttend == "enter":
        s.add(name)
    else:
        if name in s:
            s.remove(name)

for person in sorted(s, reverse = True):
    print(person)