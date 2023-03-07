#include <iostream>

using namespace std;

int main()
{
  // 입출력 속도 향상
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // 입력
  int n, k, s; // 바퀴 칸 수 n, 횟수 k, 글자 바뀜 횟수 s
  char alphabet;
  cin >> n >> k;
  char arr[25];
  int idx = 0;

  // 일단 ?로 세팅
  for (int i = 0; i < n; i++)
  {
    arr[i] = '?';
  }

  // k개의 케이스 입력
  while (k--)
  {
    cin >> s >> alphabet;

    // 판에 숫자 적기

    s %= n; // 여러 바퀴 돌았어도 나머지(reaminder)만 알면 됨.
    // 판이 시계방향으로 도니깐 숫자는 시계 반대 방향으로 적힘
    if (idx - s < 0) // 인덱스가 음수가 되면 안 됨
    {
      idx = (idx - s) + n;
    }

    else
    {
      idx -= s;
    }

    // 예외
    //  이미 글자가 차 있고, 그 글자가 새로 입력된 글자가 아니면 하나의 영역에 겹치게 됨
    if (arr[idx] != '?' && arr[idx] != alphabet)
    {
      cout << "!";

      return 0;
    }

    else
    {
      arr[idx] = alphabet;
    }
  }

  // 중복 값 확인

  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      if (arr[i] != '?' && arr[i] == arr[j])
      {
        cout << "!";
        return 0;
      }

  // 출력
  for (int i = 0; i < n; i++)
  {
    cout << arr[(i + idx) % n];
  }

  cout << "\n";
  return 0;
}