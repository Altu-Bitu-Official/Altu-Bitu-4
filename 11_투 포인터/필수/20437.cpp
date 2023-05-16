
#include <iostream>
#include <vector>
#include <string>
using namespace std;

pair<int, int> countString(string& w, int k) {
	//둘 다 끝 문자가 같아야함
	//r: 오른쪽 끝, l: 왼쪽 끝
	//r은 바깥 for, 하나씩줄임
	// l은 이너뤂, 징 스캔
	// r이 첫번째문자 닿을때까지
	//r이동...
	//어떤 문자 k개
	//->r과 같은 문자 가리킬 때까지
	//l이동
	//
	//->r이동...
	//어떤 문자 k개
	//->r과 같은 문자 가리킬 때까지
	//l 이동
	int r = w.length() - 1, l = 0;
	int max_v = 0, min_v = 10000;
	vector<int> alpha(26, 0);

	while (r != 0) {
		for (l = 0; l != r; l++) {
			alpha.assign(26, 0);//alpha초기화
			//양 끝 문자 같아야하고
			if (!(w[l] == w[r])) {
				continue;
			}
			//k개 이어야 함
			for (int i = l; i <= r; i++) {
				alpha[w[i] - 'a']++;
			}
			if (alpha[w[l] - 'a'] == k) {
				//만족하면 기록
				max_v = max(max_v, r - l + 1);
				min_v = min(min_v, r - l + 1);
			}			
		}
		r--;
	}
	pair<int, int> ans(0, 0);
	ans.first = min_v;
	ans.second = max_v;
	return ans;
}
int main() {
	//입력
	int n, k;//게임횟수, k개 문자
	string w;//문자열
	cin >> n;
	string ans = "";
	for (int i = 0; i < n; i++) {
		cin >> w;
		cin >> k;
		pair<int, int> func_ans;
		//계산
		func_ans = countString(w, k);
		if (func_ans.first == 10000 || func_ans.second == 0) {
			ans += "-1\n";
		}
		else {
			ans += to_string(func_ans.first) + " " + to_string(func_ans.second) + '\n';
		}
	}
	//출력
	cout << ans;
	return 0;
}