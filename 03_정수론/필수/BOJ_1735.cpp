#include <iostream>
#include <algorithm> 

using namespace std;

int getGcd(int a, int b)  {
  int tmp = 1;
  while (b != 0)
  {
    tmp = a % b;
    a = b;
    b = tmp;
  }
  return a;
}

void findFrac(int nume, int deno)
{
  int gcd = getGcd(max(nume, deno), min(nume, deno));
  cout << nume / gcd << " " << deno / gcd << "\n"; 
}

int main() {
  int a1, a2, b1, b2;
  cin >> a1 >> b1 >> a2 >> b2;
  int nume = a1 * b2 + a2 * b1;
  int deno = b1 * b2;
  findFrac(nume, deno);
  return 0;
}