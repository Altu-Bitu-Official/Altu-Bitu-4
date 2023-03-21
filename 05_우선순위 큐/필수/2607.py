"""
    같은 구성:
        2개의 단어가 같은 종류의 -문자-
        같은 문자는 -같은 개수-만큼
    비슷한 단어:
        같은 구성
        한 문자를 더하거나, 빼거나, 하나의 문자를 다른 문자로 바꾸어 같은 구성이 되는 경우

"""

result = 0
word_num = int(input())
w_first = sorted(input())
len_first = len(w_first)
words = []

for _ in range(word_num - 1):
    words.append(sorted(input()))

for i in words:
    dic = dict()
    flag = False
    ansC = True
    for j in range(26):
        dic[chr(ord("A") + j)] = 0
    for j in w_first:
        dic[j] += 1
    for j in i:
        if dic[j] > 0:
            dic[j] -= 1
        else:
            if not flag:
                flag = True
            else:
                ansC = False
                break
    if ansC:
        sum = 0
        for i in dic:
            sum += dic[i]
        if sum <= 1:
            result += 1

print(result)
