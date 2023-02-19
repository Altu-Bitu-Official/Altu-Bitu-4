#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

//스트링원소의 숫자 합 구하는 함수 
int sumString(string str)
{
  int sum = 0;
  for (int i = 0; i < str.length(); i++)
  {
     if (str[i] >= '0' && str[i] <= '9')
       sum += str[i] - '0';
  }
  return sum;
}

// 비교 함수
bool cmp(string s1, string s2) {
	if (s1.length() != s2.length()) 
  {
		return s1.length() < s2.length();
	}
	if (sumString(s1) != sumString(s2)) 
  {
		return sumString(s1) < sumString(s2);
	}
	return s1.compare(s2) < 0;
}

int main()
{
	int n;
  
	cin >> n;
  vector<string> serial(n);
	for (int i = 0; i < n; i++) {
		cin >> serial[i];
	}
	sort(serial.begin(), serial.end(), cmp);
	for (int i = 0; i < n; i++) {
		cout << serial[i] << '\n';
	}
	return 0;
}
