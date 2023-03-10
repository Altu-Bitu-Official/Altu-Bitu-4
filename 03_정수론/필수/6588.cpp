#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int MAX = 1000000;

vector<bool> findPrime()
{
  vector<bool> is_prime(MAX + 1, true);
  // 0과 1은 제거
  is_prime[0] = is_prime[1] = false;

  // i가 소수면 i의 배수 제거
  for (int i = 2; i * i <= MAX; i++)
  {
    if (is_prime[i] == true)
    {
      continue;
    }
    for (int j = i * i; j <= MAX; j += i)
    {
      is_prime[j] = false;
    }
  }
  return is_prime;
}

int goldbach(int n, vector<bool> &is_prime)
{

  for (int i = 3; i <= (n / 2); i += 2)
  { // 중복되므로 반만 검사
    if (is_prime[i] && is_prime[n - i])
    {
      return i;
    }
    return 0; // 골드바흐의 추측이 틀림
  }
}

int main()
{

  // 입출력 속도 향상
  cin.tie(NULL);
  ios_base::sync_with_stdio(0);

  int n;

  vector<bool> is_prime = findPrime();

  while (1)
  {
    bool flag = false;
    // 입력
    cin >> n;
    if (n == 0)
    { // 0이면 종료
      break;
    }
    int prime = goldbach(n, is_prime);
    if (prime)
    {
      cout << n << " = " << prime << " + " << n - prime << '\n';
      flag = true;
      break;
    }
    if (!flag)
    {
      cout << "Goldbach's conjecture is wrong.";
    }
  }
  return 0;
}
