#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

bool cmp(string s1, string s2) {
	int sum1 = 0;
	int sum2 = 0;

	// 문자열 길이가 다를 경우
	if (s1.size() < s2.size()) return true;
	else if (s1.size() > s2.size()) return false;

	// 문자열 길이가 같을 경우
	else {
		// 숫자의 합 작은 순
		for (int i = 0; i < s1.size(); i++) {
			if (s1[i] > 47 && s1[i] < 58) sum1= sum1 + s1[i] - 48;
		}
		for (int i = 0; i < s2.size(); i++) {
			if (s2[i] > 47 && s2[i] < 58) sum2 = sum2 + s2[i] - 48;
		}
		if (sum1 > sum2) return false;
		else if (sum1 < sum2) return true;

		// 사전 순
		for (int i = 0; i < s1.size(); i++) {
			if (s1[i] < s2[i]) return true;
			else if (s1[i] > s2[i]) return false;
		}
		return true;
	}
}

 int main()
 {
	int n;
	cin >> n ;
	vector<string> arr(n);
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end(), cmp);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << '\n';
	}
	return 0;
}