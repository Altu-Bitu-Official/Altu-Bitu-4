#include <iostream>
#include <queue>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, k;
  queue<int> q1; // 입력 큐
  queue<int> q2; // 결과 큐
  // 숫자 입력 받아서 큐에 집어 넣기
  cin >> n >> k;

  for (int i = 1; i <= n; i++)
  {
    q1.push(i);
  }

  cout << "<";

  // 결과 큐에 입력
  while (!q1.empty())
  {
    for (int i = 0; i < k - 1; i++)
    {
      q1.push(q1.front());
      q1.pop(); // 앞으로 빼서 다시 뒤로 넣기
    }

    // k번째이면 결과 큐에 삽입
    q2.push(q1.front());
    q1.pop();
  }
  int last = q1.back();

  // 결과 큐 출력
  for (int i = 1; i < n; i++)
  {
    cout << q2.front() << ", ";
    q2.pop();
  }

  cout << last << ">";

  return 0;
}
