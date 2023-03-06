#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
//최대공약수 구하기
int getGcdIter(int a, int b) 
{
	if (b == 0) return a;
	return getGcdIter(b, a % b);
}

//배열의 값의 차의 집합의 최대공약수 == m
int findGcd(vector<int> v, int n)
{
  sort(v.begin(), v.end());
	int gcd = v[1] - v[0];
	for (int i = 2; i < n; i++) 
  {
    gcd = getGcdIter(gcd, v[i] - v[i - 1]);
  }
  return gcd;
}

//최대공약수의 약수 벡터 저장
vector<int> find_res(int gcd)
{
  vector<int> res;

  for (int i = 1; i <= sqrt(gcd); i++)
	if (gcd % i == 0)
	{
		res.push_back(i);
		if (i != gcd / i) res.push_back(gcd / i);
	}
	sort(res.begin(), res.end());
  res.erase(res.begin()); //1 지우기
  return res;
}

int main() 
{
  int n, num;
	cin >> n;
  vector<int> v;
	for (int i = 0; i < n; i++) 
	{	
		cin >> num;
		v.push_back(num);
	}
  int gcd = findGcd(v, n);
  vector<int> res = find_res(gcd);
  //약수가 들어있는 배열 출력
  for (auto iter = res.begin(); iter != res.end(); iter++)
  {
    cout << *iter;
    if(iter + 1 != res.end())
    {
		  cout << " ";
    }
  }
}