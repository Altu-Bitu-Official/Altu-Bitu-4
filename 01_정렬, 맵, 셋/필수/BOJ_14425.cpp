#include<iostream>
#include<set>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	string input;
	cin >> n >> m;

	set<string> my_set;

	while (n--) {
		cin >> input;
		my_set.insert(input);
	}

	int count = 0;
	string target;
	
	while (m--) {
		cin >> target;
		for (auto iter = my_set.begin(); iter != my_set.end(); iter++) {
			
			if (target.compare(*iter) == 0) count++;
		}
	}
	cout << count;
	
}