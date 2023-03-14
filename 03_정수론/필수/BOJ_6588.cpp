#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;
#define MAX 1000000
vector<int> primes(MAX + 1, 0);

vector<int> makePrime()
{
  for(int i = 2; i * i <= MAX; i++) {
    if(primes[i] == 0) {
      for(int j = i * i; j <= MAX; j += i)
      {
        if (primes[j] == 0) 
        {
            primes[j] = 1;
        }
      }
    }
  }
  return primes;
}

// 3부터 중간값까지 소수 검사
void checkNum(int n)
{
  int flag = 0;
  for (int i = 3; i <= n / 2; i+=2)
  {
    if (primes[i] == 0 && primes[n - i] == 0)
    {
      cout << n << " = " << i << " + " << n-i << "\n";
      flag = 1;
      break;
    }
  }
  if(!flag)
  {
    cout << "Goldbach's conjecture is wrong.\n";
  }
}

int main() {
    //입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //입력
    int n;
    makePrime();
    while(1)
    {
      cin >> n;
      if (n == 0)
      {
        break;
      }
      checkNum(n);
    }
    return 0;
}