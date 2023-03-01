#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  string n1, n2;
  int num1[10001], num2[10001], plus;
  vector<int> sum;
  cin >> n1 >> n2;

  
  int len1 = n1.length(), len2 = n2.length();
  int long_len = len1 > len2 ? len1: len2;

  reverse(n1.begin(), n1.end());
  reverse(n2.begin(), n2.end());

  if (n1.length() < n2.length())
	   swap(n1, n2);
  
  for (int i = 0; i < n1.length(); i++)
		num1[i] = n1[i] - '0';
	for (int i = 0; i < n2.length(); i++)
		num2[i] = n2[i] - '0';
  for (int i = n2.length(); i < n1.length(); i++)
		num2[i] = 0;
  for (int i = 0; i < long_len ; i++)
	{
		plus = num1[i] + num2[i];
		if (plus >= 10)
		{
			num1[i + 1]++;
			plus -= 10;
		}
		sum.push_back(plus);
	}
  if (num1[sum.size()] != 0) cout << 1;
  for (int i = sum.size() - 1; i >= 0; i--)
	{
		cout << sum[i];
	}
	return 0;
}
