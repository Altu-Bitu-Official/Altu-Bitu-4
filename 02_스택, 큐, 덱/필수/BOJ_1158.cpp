#include <iostream>
#include <queue>

using namespace std;

vector<int> josephus(int n, int k) // 요세푸스 순열 반환
{
    vector<int> result; // 요세푸스 순열
    queue<int> q;       // 큐

    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }
    while (q.size())
    {
        for (int i = 1; i < k; i++)
        {
            q.push(q.front());
            q.pop();
        }
        result.push_back(q.front());
        q.pop();
    }
    return result;
}

int main()
{
    int n, k;

    cin >> n >> k;

    vector<int> result = josephus(n, k);

    cout << '<';
    cout << result[0]; // 맨처음 값만 따로 빼서 먼저 출력
    for (int i = 1; i < n; i++)
    {
        cout << ", " << result[i];
    }

    cout << '>';
    return 0;
}
/*수정 전 풀이*/
/*
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    queue<int> q;
    cin >> n >> k; // n: 7 k: 3

    for (int i = 1; i <= n; i++)
    {
        q.push(i); // 1234567 넣기
    }
    cout << '<';
    while (q.size() >= 2) // 큐에 있는 정수 개수가 2개 이상일때까지 while문 돌린다. 정수가 1개 존재하면 ,를 출력할 필요가 없기 때문에
    {
        for (int i = 1; i < k; i++) // k-1번 반복
        {
            q.push(q.front());
            q.pop();
        }
        cout << q.front() << ", ";
        q.pop();
    }
    cout << q.front() << '>'; // 마지막 정수는 ,가 필요하지않으므로 따로 빼주어 출력한다.
    return 0;
}
*/
/*int temp = q.front(); // temp에 큐의 가장 앞에 있는, 먼저 들어온 정수를 넣고
q.pop();              // 큐에서 가장 앞에 있는, 먼저 들어온 정수를 빼고
q.push(temp);         // 아까 temp 변수값을 큐에 넣는다.*/