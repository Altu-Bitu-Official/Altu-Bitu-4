def merge_sort(arr):
    if len(arr) <= 1:
        return arr
    """    
    Divide: 문제 분할
    arr을 arr[:mid]와 arr[mid:]로 분할
    """
    mid = len(arr) // 2  # //는 몫을 구하는 연산자

    # Conquer: 쪼개진 작은 문제 해결
    # left와 right에는 각각 정렬된 리스트가 담김
    left = merge_sort(arr[:mid])
    right = merge_sort(arr[mid:])

    i, j = 0, 0  # i는 left, j는 right의 cursor
    temp = []

    # Combine: 해결된 작은 문제들을 다시 합침
    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            temp.append(left[i])
            i += 1
        else:
            temp.append(right[j])
            j += 1

    # left 혹은 right에 남은 요소들 넣기
    temp += left[i:]
    temp += right[j:]

    return temp


N = int(input())
sorted_arr = []  # 정렬된 수를 담을 리스트

for _ in range(N):
    sorted_arr.append(int(input()))
# 합병 정렬
sorted_arr = merge_sort(sorted_arr)
# 정렬된 수 출력
for n in sorted_arr:
    print(n)
