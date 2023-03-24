#include<iostream>
#include<string>
#include<vector>

using namespace std;

typedef pair<char, char> cc; // 킹과 돌의 위치 좌표를 저장할 pair cc 선언

cc move(string input, char x, char y) {// 이동 함수 x : 열, y : 행
	for (int i = 0; i < input.size(); i++) {    // input 길이만큼 반복
		char how = input[i];	// 전달받은 input으로부터 이동 방법 저장
		if (how == 'R') {	// 오른쪽으로 한 칸 이동
			x++;
		}
		else if (how == 'L') {	// 왼쪽으로 한 칸 이동
			x--;
		}
		else if (how == 'B') {	// 아래로 한 칸 이동
			y--;
		}
		else {	// 위로 한 칸 이동
			y++;
		}
	}

	return { x, y };    // 이동 후 위치 리턴

}

bool checkRange(cc position) {  // 범위 체크하는 함수

	if (position.first < 'A' || position.first > 'H'	// 만약 말의 위치가 A~H, 1~8 안에 있지 않다면 (체스판 밖에 있다면)
		|| position.second < '1' || position.second > '8') {
		return false;	// false 리턴
	}
	
	return true;	// 체스판 안에 있다면 true 리턴
}

bool isSame(cc k, cc s) {	// 킹과 돌의 위치가 겹치는지 확인하는 함수

	return (k.first == s.first && k.second == s.second);	// 킹과 돌의 x(열), y(행) 좌표가 모두 일치하면 true 리턴

}

/*
* HINT : 문자형 변수의 연산은 비교적 자유로워요! 또 킹과 돌의 움직임이 모두 판 안에서 이뤄질 때만 다음으로 움직일 수 있는 점을 신경써주세요!
* 1. king 이동 (move)
* 2. king과 stone의 위치 동일 -> stone 이동 (move)
* 3. king과 stone의 위치 점검 (checkRange)
*/

int main() {

	cc k, s;    // king, stone
	int n;  // 움직이는 횟수 저장할 변수 n 선언
	string input;   // 이동 방법 입력받아서 저장할 변수 input 선언

	// 입력
	cin >> k.first >> k.second >> s.first >> s.second >> n; // 킹의 위치, 돌의 위치, 이동 횟수 입력받아서 저장

	// 연산
	while (n--) {	// n번 반복
		cin >> input;	// 이동 방법 입력받아서 저장

		cc next_k, next_s;	// 이동 후 위치 저장할 변수

		// king 이동
		next_k = move(input, k.first, k.second);	// move 함수에 input, 킹의 위치 좌표 전달하고 리턴 결과를 next_k에 저장

		// stone 이동
		if (isSame(next_k,s)) {	// 킹의 이동된 위치와 돌의 위치가 같은지 검사
			next_s = move(input, s.first, s.second);	// 킹과 돌의 위치가 같으면 똑같은 이동 방법(input)으로 돌의 위치도 이동시킨 후 next_s에 저장
		}
		else {	// 킹의 이동된 위치와 돌의 위치가 다르면 기존 돌의 위치를 next_s에 저장
			next_s = s;
		}

		// 범위 체크
		if (checkRange(next_k) && checkRange(next_s)){	// 이동한 king과 stone가 유효 범위면 최종적으로 이동
			k = next_k;	// next_k를 최종적으로 k에 저장
			s = next_s;	// next_s를 최종적으로 s에 저장
		}

	}

	// 출력
	cout << k.first << k.second <<'\n'<< s.first << s.second ;	// 킹과 돌의 위치 출력
	return 0;
}