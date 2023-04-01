l = [0 for i in range(5)]
s = 0
for i in range(5):
    l[i] = int(input())
    s += l[i]

print(s // 5)
print(sorted(l)[2])
