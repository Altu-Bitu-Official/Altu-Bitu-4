n1, n2, n3 = map(int, input().split())

if n1 == n2 and n2 == n3:
    ans = 10000 + n1*1000
elif n1 != n2 and n1 != n3 and n2 != n3:
    ans = max(n1, n2, n3) * 100
else:
    if n1 == n2 or n1 == n3:
        ans = 1000 + n1 * 100
    else:
        ans = 1000 + n2 * 100

print(ans)