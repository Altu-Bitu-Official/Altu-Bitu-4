#include <iostream>
#include <vector>

using namespace std;

vector<int> cmpChar(vector<int> alp, string& s) { //문자 하나씩 비교
	vector<int> alp_t = alp;
	for (int i = 0; i < s.size(); i++) {
		alp_t[s[i] - 'A'] -= 1;
	}
	return alp_t;
}

//비슷한 문자인지 계산하는 함수
bool sameWord(vector<int>& alp, string& s, string& word) {
	int num = 0;
	vector<int> test = cmpChar(alp, s);
	for (int i = 0; i < 26; i++) {
		num += abs(test[i]);
	}

	//문자 길이가 같을 경우 -> 같은 구성 or 한 단어 바꾸었을 때
	if (word.size() == s.size()) {
		return (num == 2 || num == 0); //num이 2이면 바꾼 경우, 그 이상이면 같은 구성이므로
	}
	else if ((word.size() + 1 == s.size())|| (word.size() - 1 == s.size())) { // 문자 길이가 +1인경우 -> 한 단어 추가했을 때 , 문자 길이가 -1인경우 -> 한 단어 뺏을 때
		return (num == 1);
	}


	return false; //위의 경우에 모두 해당이 되지 않으면 false
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, ans = 0;
	vector<int> alp(26, 0);
	string word;

	//입력
	cin >> n;
	cin >> word;
	n--;

	//연산
	for (int i = 0; i < word.size(); i++) { // 알파벳 수만큼 증가
		alp[word[i] - 'A'] += 1;
	}

	while (n--) {
		string s;
		cin >> s;

		if (sameWord(alp, s, word)) {
			ans++;
		}
	}

	//출력
	cout << ans;

	return 0;
}