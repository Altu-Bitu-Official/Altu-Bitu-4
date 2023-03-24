
#include <iostream>
#include <string>

using namespace std;

int arithmetic(int n)
{
  int num = 100; // 100부터 차례로 탐색
  string judge;  // 문자열
  int cnt;       // 한수 개수

  if (n < 100)
  {
    cnt += n; // 99보다 작은 수는 모두 한 수
    return cnt;
  }
  else
  {
    cnt = 99; // 99개에서부터 시작

    while (1)
    {
      judge = to_string(num); // 문자열로 변환
      if (judge[1] - judge[0] == judge[2] - judge[1])
      {        // 등차수열 계산
        cnt++; // 한수 개수 증가
      }

      if (num == n)
      {
        break;
      }
      num++; // 하나씩 증가 시키며 탐색
    }
    return cnt;
  }
}

int main()
{
  int n;
  cin >> n;

  cout << arithmetic(n);

  return 0;
}
