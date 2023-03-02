#include <iostream>
#include <queue>

using namespace std;

int n, k;
queue<int> q1; // 입력 큐
queue<int> q2; // 결과 큐

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

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
    int tmp;
    for (int i = 0; i < k - 1; i++)
    {
      q1.push(q1.front());
      q1.pop(); // 앞으로 빼서 다시 뒤로 넣기
    }

    // k번째이면 결과 큐에 삽입
    q2.push(q1.front());
    q1.pop();
  }

  // 결과 큐 출력
  for (int i = 0; i <= q2.size(); i++)
  {
    cout << q2.front() << ", ";
    q2.pop();
    cout << "큐사이즈" << q1.size() << q2.size();
  }

  // // 입력 큐에 남은 수 출력. ex) k=3 일 때 1, 4는 q1에 그대로 남아 있으나 q1의 남은 개수가 k보다 작아 출력되지 않음
  // for (int i = 0; i < q1.size() - 1; i++)
  // {
  //   cout << q1.front();
  //   q1.pop();
  // }
  cout << ">";

  return 0;
}
