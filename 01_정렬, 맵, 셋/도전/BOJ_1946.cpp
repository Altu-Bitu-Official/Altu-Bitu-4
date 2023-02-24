#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int select(vector<pair<int, int>>& score) {
	int max_rank = score[0].second;
	int result = 1;

	for (int i = 1; i < score.size(); i++) {
		if (score[i].second < max_rank) {
			max_rank = score[i].second;
			result += 1;
		}
	}

	return result;
}

int main() {
	int t, n;

	//�Է�
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		vector<pair<int, int>> score(n);
		for (int i = 0; i < n; i++) {
			cin >> score[i].first >> score[i].second;
		}
		//����
		sort(score.begin(), score.end());

		//���
		cout << select(score) << "\n";
	}
	

	return 0;
}