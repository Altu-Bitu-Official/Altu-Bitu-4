#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef pair<char, char> cc; // 두 개의 객체 하나로 묶어줌. 이름이 cc

cc move(string input, char x, char y)
{ // 이동 함수 x : 열, y : 행
  for (int i = 0; i < input.size(); i++)
  {                      // 움직이는 종류가 여러 개 입력 되므로
    char how = input[i]; // 배열에 저장해서 하나씩 탐색
    if (how == 'R')
    {      // 오른쪽 이동
      x++; // x 좌표값 1 증가
    }
    else if (how == 'L')
    {      // 왼쪽 이동
      x--; // x 좌표값 1 감소
    }
    else if (how == 'B')
    {      // 아래로 이동
      y--; // y좌표값 1 감소
    }
    else
    {      // 위로 이동
      y++; // y좌표값 1 증가
    }
  }

  return {x, y}; // 새로운 x, y 좌표값 리턴
}

bool checkRange(cc position)
{ // 범위 체크 하는 함수

  if (position.first < 'A' || position.first > 'H' || position.second < '1' || position.second > '8') // x좌표는 a~h 사이, y좌표는 1~8사이
  {
    return false; // 범위 벗어나면 false 리턴
  }

  return true; // 범위 내면 true 리턴
}

bool isSame(cc k, cc s) // 킹과 돌이 같은 위치에 있는지 확인하는 함수
{

  return (k.first == s.first && k.second == s.second); // 킹과 돌의 x,y좌표 비교
}

/*
 * HINT : 문자형 변수의 연산은 비교적 자유로워요! 또 킹과 돌의 움직임이 모두 판 안에서 이뤄질 때만 다음으로 움직일 수 있는 점을 신경써주세요!
 * 1. king 이동 (move)
 * 2. king과 stone의 위치 동일 -> stone 이동 (move)
 * 3. king과 stone의 위치 점검 (checkRange
 */

int main()
{

  cc k, s;      // king, stone
  int n;        // 움직이는 횟수
  string input; // 위치

  // 입력
  cin >> k.first >> k.second >> s.first >> s.second >> n; // 킹의 위치, 돌의 위치, 움직이는 횟수 n

  // 연산
  while (n--) // n개의 줄 입력
  {
    cin >> input; // 킹이 어떻게 움직여야 하는지

    cc next_k, next_s; // 이동 후 위치 저장할 변수

    // king 이동
    next_k = move(input, k.first, k.second); // input 종류에 따라 이동하는 king

    // stone 이동
    if (isSame(next_k, s)) // 킹이 돌과 같은 곳으로 이동할 때는 돌을 킹이 움직인 방향과 같은 방향으로 한 칸 이동
    {
      next_s = move(input, s.first, s.second); // 돌의 다음 위치는 돌의 처음 위치에서 input으로 들어온 이동방향만큼 move
    }
    else
    {
      next_s = s; // 킹과 같은 위치 아니라면 돌의 위치는 그대로
    }

    // 범위 체크
    if (checkRange(next_k) && checkRange(next_s))
    {             // 이동한 king과 stone가 유효 범위면 최종적으로 이동
      k = next_k; // 임시 변수였던 next_k를 최종 위치인 k에 대입
      s = next_s; // 임시 변수였던 next_s를 최종 위치인 s에 대입
    }
  }

  // 출력
  cout << k.first << k.second << '\n'
       << s.first << s.second; // 킹의 마지막 위치, 돌의 마지막 위치 출력
  return 0;                    // 종료
}