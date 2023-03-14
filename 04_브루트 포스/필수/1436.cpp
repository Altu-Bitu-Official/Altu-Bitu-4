
// 3자리 수 일 때 666
// 4자리 수 일 때 x666 혹은 666x
// 5자리 수 일 때 xx666 혹은 x666x 혹은 666xx
#include <iostream>
#include <string>

using namespace std;

int disaster(int n)
{
  int title = 666; // 처음으로 666들어가는 제목
  int cnt = 0;
  int answer = 0; // n번째 제목
  string judge;   // 하나씩 키워가면서 666 들어가는지 확인

  while (1)
  {
    judge = to_string(title); // 한 자리씩 분해 가능하도록
    for (int i = 0; i < judge.length() - 2; i++)
    { // 666이 한 세트라고 했을 때 길이-2 만큼 자리 이동 가능
      if (judge[i] == '6' && judge[i + 1] == '6' && judge[i + 2] == '6')
      { // 3개 연속으로 6
        cnt++;
        if (cnt == n)
        {
          answer = stoi(judge); // 정수로 형변환
          return answer;
        }

        break;
      }
    }
    title++;
  }
}

int main()
{
  int n;
  cin >> n;

  cout << disaster(n);

  return 0;
}
