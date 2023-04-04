#include <iostream>
#include <vector>

using namespace std;

//펠린드롬 문자열인지 확인하는 함수
bool isPerline(vector<int>& alp, vector<char>& result, char& center) {
	for (int i = 0; i < alp.size(); i++) {
		//기준 문자인지부터 확인
		//만약 문자의 개수가 홀수일 경우 이 알파벳이 기준이 되어야 함
		if (alp[i] % 2 == 1) {
			if (center == ' ') {
				center = char(i + 'A');
				alp[i] --;
			}
			else { //이미 기준이 존재한다면 펠린드롬이 될 수 없음
				return false;
			}
		}
		
		// 문자의 개수가 짝수이면 result에 알파벳을 넣고 앞 뒤에 넣을 개수인 2를 빼주는 과정을 0이 될 때까지 반복
		if(alp[i] % 2 == 0){
			while (alp[i]) {
				result.push_back(char(i + 'A'));
				alp[i] -= 2;
			}
		}
	}
	return true;
}

int main()
{
	vector<int> alp(26,0); //알파벳의 개수를 저장할 벡터
	vector<char>result;
	char center = ' ';
	string s;

	//입력 
	cin >> s;

	//연산
	for (int i = 0; i < s.size(); i++) {
		alp[s[i] - 'A']++;
	}

	//출력
	if (!isPerline(alp, result, center)) { //만약 펠린드롬이 안만들어진다면
		cout << "I'm Sorry Hansoo";
	}
	else {
		for (int i = 0; i < result.size(); i++) { // 순서대로 먼저 출력
			cout << result[i];
		}

		if (center != ' ') { //center가 있다면  center 출력
			cout << center;
		}

		for (int i = result.size() - 1; i >= 0; i--) { //이후 다시 거꾸로 출력
			cout << result[i];
		}

	}

	return 0;
}