#include<iostream>
#include<vector>
#include<algorithm>
#include<string>


using namespace std;

int extNum(const string& str) {
	int num = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] < 47 && str[i] < 58) num += atoi(str[i]);
	}
	return  num;
	
}

bool cmp(const string& s1, const string& s2) {
	if (s1.length() != s2.length()) {
		return s1.length() < s2.length();
	}
	if (extNum(s1) != extNum(s2)) {
		return extNum(s1) < extNum(s2);
	}
	return s1 < s2;
}

int main() {
	int n;
	vector<string> arr;
	cin >> n;
	arr.assign(n, "");

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end(), cmp);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << '\n';
	}
	return 0;
	

}