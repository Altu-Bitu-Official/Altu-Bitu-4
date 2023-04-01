#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

/*방법 1 : 정렬로 풀기
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int input[2250000];
    int n;
    cin >> n;

    for (int i = 0; i < n * n; i++)
    {
        cin >> input[i];
    }
    sort(input, input + n * n);

    cout << input[n * n - n];
}*/

/* 방법 2 : 우선순위큐 greater -> 오름차순 정렬되면서 pop할때는 가장 작은 수가 pop됨*/
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int input[2250000];
    int n;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    cin >> n;

    for (int i = 0; i < n * n; i++)
    {
        cin >> input[i];
        min_heap.push(input[i]);

        if (min_heap.size() > n)
        {
            min_heap.pop(); // 제일 작은것 pop하기
        }
    }
    cout << min_heap.top();
}