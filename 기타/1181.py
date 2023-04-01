N = int(input())
word_list = [set() for _ in range(50)]

for _ in range(N):
    word = input()
    word_list[len(word)-1].add(word)

for sub_list in word_list:
    for w in sorted(sub_list):
        print(w)