#include<iostream>
#include<string>
#include<vector>

using namespace std;
typedef pair<char, char>cc;

cc move(string input, char x, char y) {//이동 함수 x : 열, y : 행
	for (int i = 0; i < input.size(); i++) {
		char how = input[i];
		if (how == 'R') {
			x++;
		}
		else if (how == 'L') {
			x--;
		}
		else if (how == 'B') {
			y--;
		}
		else {//T
			y++;

		}
	}

	return { x, y };

}

bool checkRange(cc position) {//범위 체크 하는 함수

	if (position.first < 'A' || position.first > 'H'
		|| position.second < '1' || position.second > '8') {
		return false;
	}
	
	return true;
}

bool isSame(cc k, cc s) {

	return (k.first == s.first && k.second == s.second);

}

/*
* HINT : 문자형 변수의 연산은 비교적 자유로워요! 또 킹과 돌의 움직임이 모두 판 안에서 이뤄질 때만 다음으로 움직일 수 있는 점을 신경써주세요!
* 1. king 이동 (move)
* 2. king과 stone의 위치 동일 -> stone 이동 (move)
* 3. king과 stone의 위치 점검 (checkRange
*/

int main() {

	cc k, s;//king, stone
	int n;
	string input;

	//입력
	cin >> k.first >> k.second >> s.first >> s.second >> n;

	//연산
	while (n--) {
		cin >> input;

		cc next_k, next_s;//이동 후 위치 저장할 변수

		//king 이동
		next_k = move(input, k.first, k.second);

		//stone 이동
		if (isSame(next_k,s)) {
			next_s = move(input, s.first, s.second);
		}
		else {
			next_s = s;
		}

		//범위 체크
		if (checkRange(next_k) && checkRange(next_s)){//이동한 king과 stone가 유효 범위면 최종적으로 이동
			k = next_k;
			s = next_s;
		}

	}

	//출력
	cout << k.first << k.second <<'\n'<< s.first << s.second ;
	return 0;
}