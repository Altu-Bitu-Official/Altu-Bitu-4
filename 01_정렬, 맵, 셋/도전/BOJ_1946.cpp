#include <iostream>
#include <vector>

using namespace std;

int select(const int& n) {
	int score, rank;
	vector<int> order(n);
	vector<int> ranks(n);

	for (int i = 0; i < n; i++) {
		cin >> score >> rank;
		order[score-1] = i;
		ranks[i] = rank;
	}

	int max_rank = ranks[order[0]];
	int result = 1;

	for (int i = 1; i < n; i++) {
		if (ranks[order[i]] < max_rank) {
			max_rank = ranks[order[i]];
			result += 1;
		}
	}

	return result;
}

int main() {
	int t, n;
	
	//입력
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		//연산 & 출력
		cout << select(n) << "\n";
	}

	return 0;
}