#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int n;
	int num = 0; // 비슷한 단어의 개수
	cin >> n;
	string w1, w;

	cin >> w1; // 첫째줄에 입력한 단어 
	vector <int> w1_a(30, 0); // A~Z 모두 0으로 초기화 
	for (int i = 0; i < w1.size(); i++) { w1_a[w1[i] - 65] += 1; }

	for (int i = 0; i < n - 1; i++) {
		int cmp = 0;
		cin >> w;
		vector <int> tmp;
		vector <int> w_a(30, 0); // A~Z 모두 0으로 초기화 

		for (int j = 0; j < w.size(); j++) { w_a[w[j] - 65] += 1; }

		for (int k = 0; k < 26; k++) {
			if (w_a[k] != w1_a[k]) { cmp = cmp + 1; }
			int a = w_a[k] - w1_a[k];
			if (a >= 2 || a<=-2) tmp.push_back(a);
		}
		// 문자열 길이가 같을 때 (같은 구성이거나 한 문자 바뀐 경우)
		if (w.size() == w1.size() && cmp <= 2) {
			if (tmp.empty()) num = num + 1;
		}
		// 길이 1 차이날 때
		else if (w.size() - w1.size() == -1 || w.size() - w1.size() == 1) {
			if (cmp == 1) 	num = num + 1;}
	}
	cout << num;
	return 0;
}
