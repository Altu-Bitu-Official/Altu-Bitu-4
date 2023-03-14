#include <iostream>

using namespace std;

// 최대공약수(GCD) 계산 함수: 유클리드 호제법 이용
int getGCD(int a, int b)
{
  if (b == 0)              // 0과의
    return a;              // 최대공약수는 a 자기 자신
  return getGCD(b, a % b); // a와 b의 최대 공약수는 a%b 와 b의 최대공약수와 같음. 왼쪽 값이 더 커야 하므로 둘의 위치 바꿈. 재귀 호출
  // 예시: gcd(28,8)=gcd(20,8)=gcd(12,8)=gcd(4,8)
}

/* [백준 1735: 분수 합]
 * a/b + c/d = (a*d)/(b*d) + (b*c)/(b*d) = (a*d + b*c)/(b*d)
 * 위 분수를 기약분수로 나타낸 것을 x/y라 하고,
 * gcd를 (a*d + b*c)와 (b*d)의 최대공약수라 하면
 * x = (a*d + b*c) / gcd
 * y = (b*d) / gcd
 */

int main()
{
  // 입력
  int a, b, c, d;          // 2/7 + 3/5 = 31/35
  cin >> a >> b >> c >> d; // 모두 공백 문자로 나누어져 있으므로 한 번에 입력 받기

  // 연산
  int x = (a * d) + (b * c); // 분자계산. 분자분모에 같은 수를 곱해주어야 하므로 엑스자로 곱함
  int y = b * d;             // 분모계산. 분모끼리 곱함
  int gcd = getGCD(x, y);    // 최대공약수 계산
  x = x / gcd;               // 기약분수의 분자. 단순히 x,y만 구하면 기약분수가 아님. 예를 들어, 분모가 2와 4인 경우 분모는 두 수의 곱인 8이 아닌 4임.
  y = y / gcd;               // 기약분수의 분모

  // 출력
  cout << x << " " << y; // 분자, 분모 순으로 출력

  return 0;
}