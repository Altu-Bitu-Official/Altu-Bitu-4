#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

//펠린드롬 문자열=거꾸로 읽어도 같은 문자열
//펠린드롬 문자열이기 위해서는 단 하나의 예외 문자 빼고 모든 문자열이 짝수개만큼 존재해야함


//문자열을 입력 받아 벡터에 그 개수를 저장하는 함수
vector<int> your_name(string &str) {
	vector<int>name(26, 0);
	for (int i = 0; i < str.size(); i++) {
		name[str[i] - 'A']++;
	}
	return name;
}

//펠린드롬인지 검사하고 맞는 문자열을 출력하는 함수: 펠린드롬은 앞뒤가 대칭이므로 앞의 절반만 입력받아 reverse를 이용할 예정
void is_palindrome(vector<int> &name) {
	string p = ""; //펠린드롬 문자열
	for (int i = 0; i < name.size(); i++) {
		while (name[i] >= 2) {
			p += char(i + 'A');
			name[i] -= 2; //문자열이 2개 이상일 경우 문자열에 알파벳 추가
		}
	}
	
	int cnt = 0;
	string odd="";//홀수개인 문자를 저장할 문자열
	for (int i = 0; i < name.size(); i++) {
		if (name[i] > 0) {
			cnt++;
			odd=char(i+'A');//홀수개인 문자가 있다면 odd에 저장
		}
	}

	if (cnt > 1) {//홀수개인 문자열이 2개 이상이면 펠린드롬이 될 수 없으므로
		cout << "I'm Sorry Hansoo";
	}
	else {
		cout << p << odd; //앞의 절반부분 출력, 홀수개인 문자가 (공백이 아니라면)출력
		reverse(p.begin(), p.end()); //원래 문자열을 뒤집음
		cout << p; //뒤집은 문자열을 출력해 앞뒤 대칭이 되게함
	}
}

int main() {
	string str;
	cin >> str;

	vector<int>name(26, 0);
	name= your_name(str);
	is_palindrome(name);

	return 0;
	
}