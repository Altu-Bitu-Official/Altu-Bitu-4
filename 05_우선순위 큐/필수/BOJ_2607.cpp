#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//같은 구성인지의 여부 반환 함수
bool isSame(string s1, string s2) {
	//문자열의 길이가 다르다면 같은 구성이 아님
	if (s1.length() != s2.length()) {
		return false;
	}

	//두 문자열을 sort한 후 비교
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	if (s1 == s2) {
		return true;
	}
	return false;
}

//비슷한 구성인지의 여부 반환 함수
bool isSimilar(string s1, string s2) {
	//1. 문자열 길이가 2 이상 차이나면 비슷한 구성이 될 수 없음
	if (abs((int)(s1.length() - s2.length())) > 1) {
		return false;
	}

	//2. 같은 구성인 경우
	if (isSame(s1, s2)) {
		return true;
	}

	//3. 다른 구성인 경우
	vector<int> s1_count(26);
	vector<int> s2_count(26);
	int cnt = 0; //다른 문자의 개수

	//A부터 Z까지 개수 검사
	for (int i = 0; i < 26; i++) {
		s1_count[i] = count(s1.begin(), s1.end(), (char)(i + 65));
		s2_count[i] = count(s2.begin(), s2.end(), (char)(i + 65));
		int count_diff = abs(s1_count[i] - s2_count[i]);

		//하나의 알파벳 개수 차이가 2개 이상이라면 비슷한 구성이 될 수 없음
		if (count_diff > 1) {
			return false;
		}

		cnt += count_diff;
	}

	//cnt가 2 이하라면 하나를 더하거나 빼거나 바꾸어서 같은 구성이 되므로 true
	if (cnt <= 2) {
		return true;
	}

	return false;
}

int solution(vector<string>& word) {
	int result = 0;
	string s = word[0];
	for (int i = 1; i < word.size(); i++) {
		if (isSimilar(s, word[i])) {
			result += 1;
		}
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n;
	cin >> n;

	vector<string> word(n);
	for (int i = 0; i < n; i++) {
		cin >> word[i];
	}

	//연산 & 출력
	cout << solution(word);

	return 0;
}