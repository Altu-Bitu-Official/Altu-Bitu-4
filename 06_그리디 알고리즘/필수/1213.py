hansu = input()
cnt = [0 for _ in range(ord('Z') - ord('A')+1)] # 알파벳 개수 저장 배열
palindrome = []
flag = True # 팰린드롬 가능 여부
for a in hansu:
    cnt[ord(a) - ord('A')] += 1 # 알파벳 개수 저장
for i in range(len(cnt)):
    if cnt[i] == 0:
        pass
    elif len(palindrome) == 0: # 첫번째 알파벳이면 모두 저장
        palindrome.extend(chr(i + 65) for _ in range(cnt[i]))
    elif len(palindrome) % 2 == 0: # 현재까지 저장된 팰린드롬 리스트 길이가 짝수면
        mid = len(palindrome) // 2
        left = palindrome[:mid]
        right = palindrome[mid:]
        palindrome = left + [chr(i + 65) for _ in range(cnt[i])] + right # palindrome[:mid] + 새로운 알파벳(개수만큼) + palindrome[:mid]
    else: # 현재까지 저장된 팰린드롬 리스트 길이가 홀수면
        mid = len(palindrome) // 2
        if cnt[i] % 2 == 0: # 새로운 알파벳 개수가 짝수면
            left = palindrome[:mid]
            right = palindrome[mid + 1:]
            # palindrome[:mid] + 새로운 알파벳(개수//2만큼) + palindrome[mid] + 새로운 알파벳(개수//2만큼) + palindrome[mid+1]
            palindrome = left + [chr(i + 65) for _ in range(cnt[i] // 2)] + palindrome[mid:mid + 1] + [chr(i + 65) for _ in range(cnt[i] // 2)] + right
        else: # 새로운 알파벳 개수가 홀수면
            print("I'm Sorry Hansoo")
            flag = False
            break
# 팰린드롬 문자열 출력
if flag:
    ans = ""
    for a in palindrome:
        ans += a
    print(ans)
else:
    print("I'm Sorry Hansoo")
