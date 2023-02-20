#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cmp(string s1, string s2) {
	int s1_sum = 0, s2_sum = 0;

	for (int i = 0; i < s1.size(); i++) {
		if (isdigit(s1[i])) {
			s1_sum += (s1[i] - '0');
		}
	}

	for (int i = 0; i < s2.size(); i++) {
		if (isdigit(s2[i])) {
			s2_sum += (s2[i] - '0');
		}
	}

	if (s1.size() != s2.size()) {
		return s1.size() < s2.size();
	}

	if (s1_sum != s2_sum) {
		return s1_sum < s2_sum;
	}

	return s1 < s2;
}

int main() {
	int n;
	vector<string> s;
	string input;
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		s.push_back(input);
	}

	sort(s.begin(), s.end(), cmp);

	for (int i = 0; i < s.size(); i++) {
		cout << s[i] << '\n';
	}
	
	return 0;
}