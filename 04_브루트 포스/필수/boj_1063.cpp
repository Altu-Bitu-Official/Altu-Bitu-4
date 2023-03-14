#include<iostream> //입출력 헤더 선언 
#include<string>   //sting 헤더 선언 
#include<vector>    //vector 헤더 선언 

using namespace std;  //namespace 사용 
typedef pair<char, char>cc;  //좌표평면을 나타내기 위해 char,char로 pair 자료형 선언 

//반복되는 움직임은 함수로 구현하면 좋음 -> 킹과 돌의 위치를 반환하는 move라는 함수 선언 
cc move(string input, char x, char y) {//input -> 어떻게 움직일 것인지, 함수 안에서 x좌표와 y좌표를 각각 사용하기 때문에 한번에 받지 않고 각각 매개변수로 받음 이동 함수 x : 열, y : 행
	
    for (int i = 0; i < input.size(); i++) {  //이동이 두가지가 합쳐진 경우 -> string 형으로 받은 input값의 알파벳 하나 하나마다 움직임이 구현이 되니까 input의 사이즈만큼 이동하는 반복문으로 해결 
		char how = input[i];  //input[i]에는 움직임을 지시하는 알파벳이 들어가 있음 
		if (how == 'R') {    // 오른쪽으로 갈 때 
			x++;             //x 좌표의 값 증가 
		}
		else if (how == 'L') { // 왼쪽으로 갈 때
			x--;               //x좌표의 값 감소 
		}
		else if (how == 'B') { //아래로 이동 
			y--;               //y 좌표의 값 감소 
		}
		else {//T의 경우       //위로 갈 때 
			y++;               //y 좌표 증가 

		}
	}

	return { x, y };  //return 값을 중괄호로 묶어서 반환하면 pair 형으로 바뀌어서 반환이 됨 

}

bool checkRange(cc position) {//범위 체크 하는 함수 -> 조건문에 사용 할 것이니까 반환형을 bool으로 하는게 좋음 -> 위치가 중요하니까 킹과 돌의 위치를 한번에 받을 수 있는 position으로 매개변수를 받음 

	if (position.first < 'A' || position.first > 'H'        // x의 위치는 A ~ H 사이에 있어야 함 -> 그 반대의 경우로 조건문 선언 
		|| position.second < '1' || position.second > '8') {  // y 좌표의 위치는 1 ~8 사이에 있어야 함 -> 반대의 경우로 조건문 선언 
		return false;       // x,y좌표가 범위 밖에 있기 때문에 false 반환 
	}
	
	return true;          //true 반환 
}

bool isSame(cc k, cc s) {  //킹과 돌의 위치가 같은지 판단하는 함수 

	return (k.first == s.first && k.second == s.second);  //이동한 킹의 위치와 돌의 위치가 같을 때 

}

/*
* HINT : 문자형 변수의 연산은 비교적 자유로워요! 또 킹과 돌의 움직임이 모두 판 안에서 이뤄질 때만 다음으로 움직일 수 있는 점을 신경써주세요!
* 1. king 이동 (move)
* 2. king과 stone의 위치 동일 -> stone 이동 (move)
* 3. king과 stone의 위치 점검 (checkRange
*/

int main() {

	cc k, s;//king의 위치 , stone의 위치 
	int n;   //연산이 몇 번 일어나는지에 대한 변수 
	string input;  //이동을 문자열로 받음 

	//입력
	cin >> k.first >> k.second >> s.first >> s.second >> n;  //조건대로 입력 받음 

	//연산
	while (n--) {     //연산이 일어나는 횟수 만큼 
		cin >> input;   //input 입력 

		cc next_k, next_s;//이동 후 위치 저장할 변수

		//king 이동
		next_k = move(input, k.first, k.second);  //킹의 다음 위치 

		//stone 이동 (킹과 돌의 위치가 같을 경우에 돌을 이동시키고 같지 않다면 돌은 그대로 )
		if (isSame(next_k,s)) {  //킹과 돌의 위치가 같을 때
			next_s = move(input, s.first, s.second);   //돌 이동 
		}
		else {             //킹과 돌의 위치가 같지 않을때 -> 돌 이동 X
			next_s = s;    //다음 돌의 위치에 현재 돌의 위치가 그대로 들어감 
		}

		//범위 체크 (움직임이 유효한지 아닌지 체크 ) -> 체스판의 범위를 벗어나지 않아야 함. 
		if (checkRange(next_k) && checkRange(next_s)){//돌과 킹의 범위를 각각 체크 -> 이동한 king과 stone가 유효 범위면 최종적으로 이동 
			k = next_k;        //현재 킹의 위치를 이동한 위치로 변경 
			s = next_s;        //현재 돌의 위치를 이동한 돌의 위치로 변경 
		}

	}

	//출력
	cout << k.first << k.second <<'\n'<< s.first << s.second ;  //현재 킹과 돌의 위치를 x값, y값 차례로 출력
	return 0;   //메인함수 종료 
}