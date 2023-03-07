#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> kill(const int n, const int k)
{
    queue<int> q;
    // queue 채우기
    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }
    vector<int> v;

    while (!q.empty())
    {
        // kill 대상이 아닌 사람을 큐의 마지막에 다시 추가
        for (int i = 0; i < k - 1; i++)
        {
            q.push(q.front());
            q.pop();
        }
        v.push_back(q.front());
        // kill
        q.pop();
    }
    
    return v;
}

int main()
{
    int n, k;
    vector<int> v;
    // 입력
    cin >> n >> k;
    
    // 요세푸스 순열
    v = kill(n, k);

    //출력
    cout << "<";

    for (int i=0; i<v.size()-1; i++)
    {
        cout << v[i] << ", ";
    }

    cout << v[n-1];
    cout << ">";
}