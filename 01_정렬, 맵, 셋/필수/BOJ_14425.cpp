#include <iostream>
#include <map>
using namespace std;
map<string, bool> m;
int num=0;
int N, M;
string str;

int main(void)
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		m.insert(pair<string, bool>(str, true));
	}

	for (int i = 0; i < M; i++)
	{
		cin >> str;
		if (m[str]==true)
			num++;
	}
	cout << num;

}