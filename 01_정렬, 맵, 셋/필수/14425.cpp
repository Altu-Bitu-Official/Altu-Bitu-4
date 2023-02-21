#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
	int n, m, t = 0;
	string temp;
	set<string> s;

	cin >> n >> m;

	// 집합 s구성
	while (n--)
	{
		cin >> temp;
		s.insert(temp);
	}

	// 집합s에 존재한다면 t값 증가
	while (m--)
	{
		cin >> temp;
		if (s.find(temp) != s.end())
			t++;
	}
	cout << t;
}
