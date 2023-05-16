
#include <iostream>
#include <vector>
#include <string>
using namespace std;

pair<int, int> countString(string& w, int k) {
	//둘 다 끝 문자가 같아야함
	//r이동...
	//어떤 문자 k개
	//->r과 같은 문자 가리킬 때까지
	//l이동
	//
	//->r이동...
	//어떤 문자 k개
	//->r과 같은 문자 가리킬 때까지
	//l 이동
	int r=0, l=0;
	int max_v=0, min_v= 10000;
	vector<int> alpha(26, 0);
	while (r!=(w.length())) {
		alpha[w[r] - 'a']++;
		if (alpha[w[r] - 'a'] < k) {
			r++;
			continue;
		}
		while (w[r] != w[l]||alpha[w[r]-'a']>k) {
			alpha[w[l] - 'a']--;
			l++;
		}
		max_v = max(max_v, r - l + 1);
		min_v = min(min_v, r - l + 1);
		r++;
	}
	pair<int, int> ans(0,0);
	ans.first = min_v;
	ans.second = max_v;
	return ans;
}
int main() {
	//입력
	int n, k;//게임횟수, k개 문자
	string w;//문자열
	cin >> n;
	string ans="";
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