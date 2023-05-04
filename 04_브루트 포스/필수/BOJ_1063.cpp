#include<iostream> // 입출력을 위한 헤더
#include<string> // 문자열 클래스를 사용하기 위한 헤더 
#include<vector> // 벡터 객체를 사용하기 위한 헤더

using namespace std;
typedef pair<char, char>cc; // 킹과 돌의 위치를 (x, y) 좌표 형식으로 구현하기 위한 pair 자료형

// 이동 함수 (8가지의 이동을 char로 나누어 B,L,T,R의 4가지 이동으로 구현)
cc move(string input, char x, char y) {//input: 입력받은 이동 방향, x : 열, y : 행

	for (int i = 0; i < input.size(); i++) { // 입력 받은 이동의 문자열 길이만큼 반복문 실행
		char how = input[i]; // 문자열 안의 각각 개별 문자를 how로 받음
		if (how == 'R') { // R이면 
			x++; // 오른쪽으로 이동 (열에서 1칸 오른쪽으로 이동)
		}
		else if (how == 'L') { // L이면 
			x--; // 왼쪽으로 이동 (열에서 1칸 왼쪽으로 이동)
		}
		else if (how == 'B') { // B이면 
			y--; // 아래로 이동 (행에서 1칸 아래로 이동)
		}
		else {// T이면 
			y++; // 위로 이동 (행에서 1칸 위로 이동)
		}
	}
	return { x, y }; // 이동 후의 위치 반환
}

bool checkRange(cc position) {//범위 체크 하는 함수

	if (position.first < 'A' || position.first > 'H' // 열에서 범위 벗어나거나
		|| position.second < '1' || position.second > '8') { // 행에서 범위 벗어나면
		return false; // false 값 반환
	}
	// 범위 안에 있으면 
	return true; // true 값 반환
}

bool isSame(cc k, cc s) { // 킹과 돌의 위치가 같은 지 확인하는 함수
	return (k.first == s.first && k.second == s.second);
	// 킹의 열,행과 돌의 열,행이 모두 같다면 true값 반환
}

/*
* HINT : 문자형 변수의 연산은 비교적 자유로워요! 또 킹과 돌의 움직임이 모두 판 안에서 이뤄질 때만 다음으로 움직일 수 있는 점을 신경써주세요!
* 1. king 이동 (move)
* 2. king과 stone의 위치 동일 -> stone 이동 (move)
* 3. king과 stone의 위치 점검 (checkRange)
*/

int main() { // 가장 먼저 실행되는 main 함수 

	cc k, s; // king과 stone의 위치
	int n; // 연산의 횟수
	string input; // 이동을 입력받는 문자열 

	//입력
	cin >> k.first >> k.second >> s.first >> s.second >> n;
	// 킹과 돌의 현재 위치와 연산 횟수 입력 받음

	//연산
	while (n--) { // n번동안 반복문 실행
		cin >> input; // 이동 방향 입력 받음

		cc next_k, next_s;// 이동 후 킹과 돌의 위치 저장할 변수

		//king 이동
		// 킹의 다음 위치
		next_k = move(input, k.first, k.second); // move 함수에 이동방향, 킹의 현재 위치 입력

		//stone 이동
		if (isSame(next_k, s)) {// 킹과 돌의 위치가 같다면 돌을 이동시킴
			// 돌의 다음 위치
			next_s = move(input, s.first, s.second); // move 함수에 이동방향, 돌의 현재 위치 입력
		}
		else { // 킹과 돌의 위치가 다르다면  
			next_s = s; // 돌은 그대로 (다음 돌의 위치는 현재 돌의 위치와 같음)
		}

		//범위 체크
		if (checkRange(next_k) && checkRange(next_s)) {//이동한 킹과 돌이 유효 범위면 최종적으로 이동
			k = next_k; // 킹의 위치는 이동 후의 위치
			s = next_s; // 돌의 위치는 이동 후의 위치
		}

	}
	//출력
	cout << k.first << k.second << '\n' << s.first << s.second;
	// 첫째 줄에 킹의 마지막 위치, 둘째 줄에 돌의 마지막 위치 출력
	return 0; // 메인 함수 종료
}