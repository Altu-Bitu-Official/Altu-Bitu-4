#include<iostream>
#include<vector>
#include<string>

using namespace std;

/*
* A부터 순서대로 이용하면 알파벳순으로 가장 빠른 팰린드롬을 만들 수 있다 -> 그리디 알고리즘
* 모든 알파벳이 짝수 개씩 존재하거나, 홀수 개 알파벳이 한 종류만 있는 경우에만 팰린드롬이 존재한다.
*/
const int NUM_CHAR = 26; // 알파벳 총 개수: 26개

void pushString(string &str, int times, char ch) {
	// str이라는 문자열의 뒤에 ch 문자를 times 횟수만큼 추가
	while (times--) {
		str += ch;
	}
}

string isPalindrom(vector<int> freq){
	string answer = "";
	int odd_index = -1; // 홀수 개수인 알파벳의 인덱스 체크
	// 팰린드롬 앞부분 만들기 & 가능한지 여부 체크
	for (int i = 0; i < NUM_CHAR; i++) {
		if (freq[i] % 2 == 1) {
			if (odd_index!=-1) { // 이미 홀수 개수인 알파벳이 존재한다면 팰린드롬 불가능
				return("I'm Sorry Hansoo");
			}
			odd_index = i; // 홀수 개수인 알파벳이 처음이라면 인덱스 체크
		}
		pushString(answer, freq[i] / 2, 'A' + i);
	}

	// 홀수 개수 알파벳 존재한다면 가운데 문자 추가
	if (odd_index != -1) {
		answer += 'A' + odd_index;
	}

	// 팰린드롬 뒷부분 체크
	for (int i = NUM_CHAR-1; i >= 0; i--) {
		pushString(answer, freq[i] / 2, 'A' + i);
	}
	
	return answer;
}
int main() {
	
	// 입력
	string name;
	cin >> name;
	
	vector<int> freq(NUM_CHAR, 0); // 알파벳 26개마다 빈도수를 센다. 인덱스 0:'A', 1:'B', ...
	
	// 연산
	for (int i = 0; i < name.length(); i++) {
		freq[name[i] - 'A']++; // 각 알파벳의 개수 세기
	}
	
	// 연산 & 출력
	cout << isPalindrom(freq);
    return 0;
}