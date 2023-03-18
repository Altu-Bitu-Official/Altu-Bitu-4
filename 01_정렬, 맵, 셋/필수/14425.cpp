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
		//  2. count 함수 사용
		// cnt += s.count(input); // set에 해당 원소의 존재 여부를 int형으로 리턴
	}
	// 출력
	cout << cnt << '\n';
	return 0;
}
