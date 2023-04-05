#include <iostream>
#include <vector>

#include <string>
#include <math.h>
using namespace std;

vector<string> s;
int similarWord(vector<string>& s) {
	string strdef = s[0]; // 첫단어를 기준으로 
	int words = 0;
	for (int i = 1; i < s.size(); i++) {
		int cnt = 0;
		string strvar = s[i];
		int l = strvar.length() - strdef.length();
		// 길이 차이 2 이상이면 버리기
		if (abs(l) > 1) {
			continue;
		}
		// 길이차이 0이면
		else if (l == 0) {
			// find로 검사
			for (int i = 0; i < strdef.length(); i++) {
				if (strvar.find(strdef[i]) == string::npos) { // find 해서 찾는 것이 없으면 string::npos 를 반환한다.
					cnt++;
				}
			}
			if (cnt <= 1) { // 하나가 다른 건 괜찮다
				words++;
			}
		}
		// 길이차이 1이면
		else if (l == 1) {
			// find로 검사
			for (int i = 0; i < strdef.length(); i++) {
				if (strvar.find(strdef[i]) == string::npos) {
					cnt++;
				}
			}
			if (cnt == 0) { // 길이 차이가 1이면 하나를 빼야 같은 구성이 된다. 모든 문자가 있어야함. 
				words++;
			}
		}
		else if (l == -1) {
			// find로 검사
			for (int i = 0; i < strdef.length(); i++) {
				if (strvar.find(strdef[i]) == string::npos) {
					cnt++;
				}
			}
			if (cnt <= 1) { // 길이 차이가 -1이면 하나를 더해야 같은 구성이 됨. 따라서 더할 문자 하나 빼고는 모두 있어야한다.
				words++;
			}
		}
	}
	return words;
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		s.push_back(str);
	}
	cout << similarWord(s);
	return 0;
}