#include <iostream>
#include <set>

using namespace std;

int main()
{
	int n, m, count = 0;
	string input;
	set<string> s;

	cin >> n >> m;
	while (n--) {
		cin >> input;
		s.insert(input);
	}

	while (m--) {
		cin >> input;
		if (s.count(input)) {
			count += 1;
		}
	}

	cout << count << '\n';

	return 0;
}