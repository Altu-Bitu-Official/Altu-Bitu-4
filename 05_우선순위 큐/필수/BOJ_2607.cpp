#include <iostream>
#include <string>
using namespace std;

//비슷한 단어 여부 계산 함수
bool cmpSim(string a, string b) {
	int aArr[26] = { 0 };
	int bArr[26] = { 0 };

	//word에 맞춰 알파벳 배열을 올려줌
	for (int i = 0; i < a.length(); i++) {
		aArr[a[i] - 'A'] += 1;
	}
	for (int i = 0; i < b.length(); i++) {
		bArr[b[i] - 'A'] += 1;
	}

	int diff = 0, acnt = 0, bcnt = 0;
	for (int i = 0; i < 26; i++) {
		diff += abs(aArr[i] - bArr[i]); //diff: 글자 차이
	}
	if (abs(int(a.length() - b.length())) <= 1 && diff <= 2) { //글자 수 차이가 1 이하이고, 글자 차이가 2 이하일때
		return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, cnt = 0;
	string word;

	//입력
	cin >> n;
	cin >> word;

	//연산
	while (--n) {
		string input;
		cin >> input;
		if (cmpSim(word, input)) {
			cnt++;
		}
	}

	//출력
	cout << cnt;
	return 0;
}