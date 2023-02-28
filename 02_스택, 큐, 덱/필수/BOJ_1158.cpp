
#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b;
    queue<int> q;
    cin >> a >> b; // a가 7 b가 3 일때

    for (int i = 1; i <= a; i++)
    {
        q.push(i); // 1234567 넣기
    }
    cout << '<';
    while (q.size() >= 2) // 큐에 있는 정수 개수가 2개 이상일때까지 while문 돌린다. 정수가 1개 존재하면 ,를 출력할 필요가 없기 때문에
    {
        for (int i = 1; i < b; i++) // b-1번 반복
        {
            int temp = q.front(); // temp에 큐의 가장 앞에 있는, 먼저 들어온 정수를 넣고
            q.pop();              // 큐에서 가장 앞에 있는, 먼저 들어온 정수를 빼고
            q.push(temp);         // 아까 temp 변수값을 큐에 넣는다.
        }
        cout << q.front() << ", ";
        q.pop();
    }
    cout << q.front() << '>'; // 마지막 정수는 ,가 필요하지않으므로 따로 빼주어 출력한다.
    return 0;
}