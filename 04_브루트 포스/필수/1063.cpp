//입력으로 킹이 어떻게 움직여야 하는지 주어진다.
//입력으로 주어진 대로 움직여서 킹이나 돌이 체스판 밖으로 
//나갈 경우에는 그 이동은 건너 뛰고 다음 이동을 한다.
//킹과 돌의 마지막 위치를 구하는 프로그램을 작성하시오.


#include <iostream>
#include <string>

using namespace std;

bool isOutOfBoard(char col, int row) {
	if (!((col >= 'A' && col <= 'H') && (row >= 1 && row <= 8)))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void duplicateProcessing(string &stone, string dir) {
	int s_row = stone[1] - '0';
	char s_col = stone[0];

	if (dir == "R") {
		s_col = s_col + 1;
	}
	else if (dir == "L") {
		s_col = s_col + -1;
	}
	else if (dir == "B") {
		s_row = s_row + -1;
	}
	else if (dir == "T") {
		s_row = s_row + 1;
	}
	else if (dir == "RT") {
		s_col = s_col + 1;
		s_row = s_row + 1;
	}
	else if (dir == "LT") {
		s_col = s_col + -1;
		s_row = s_row + 1;
	}
	else if (dir == "RB") {
		s_col = s_col + 1;
		s_row = s_row + -1;
	}
	else if (dir == "LB") {
		s_col = s_col + -1;
		s_row = s_row + -1;
	}

	if (!isOutOfBoard(s_col, s_row )) {
		stone = s_col + to_string(s_row);
	}
	
}

void moveChess(string dir, string& stone, string& king) {

	int k_row = king[1] - '0';
	char k_col = king[0];
	string k_temp=king;
	string s_temp=stone;
	if (dir == "R") {
		k_col = k_col + 1;
	}
	else if (dir == "L") {
		k_col = k_col + -1;
	}
	else if (dir == "B") {
		k_row = k_row + -1;
	}
	else if (dir == "T") {
		k_row = k_row + 1;
	}
	else if (dir == "RT") {
		k_col = k_col + 1;
		k_row = k_row + 1;
	}
	else if (dir == "LT") {
		k_col = k_col + -1;
		k_row = k_row + 1;
	}
	else if (dir == "RB") {
		k_col = k_col + 1;
		k_row = k_row + -1;
	}
	else if (dir == "LB") {
		k_col = k_col + -1;
		k_row = k_row + -1;
	}
	//조건 검사
	//1. 보드 밖에 나갔는가? 
	if (!isOutOfBoard(k_col, k_row)) {
		k_temp = k_col + to_string(k_row);
	}
	//2. 스톤이랑 킹이랑 겹치는가?
	if (stone == k_temp) {
		s_temp = stone;
		duplicateProcessing(stone, dir);
		//만약 duplicate인데 스톤이 바뀌었으면
		if (stone != s_temp)
			king = k_temp;
	}
	else//안 겹치면 고려없이 그대로 넣음
	{
		king = k_temp;
	}
}

int main() {
	
	//돌 위치, 킹 위치, 반복횟수, 지시문
	string stone;
	string king;
	int num;
	string direction;

	//입력받기
	cin >> king >> stone >> num;
	for (int i = 0; i < num; i++) {
		cin >> direction;
		moveChess(direction, stone, king);
	}

	//출력
	//첫째 줄에 킹의 마지막 위치, 
	//둘째 줄에 돌의 마지막 위치를 출력한다.
	cout << king << "\n" << stone;


	return 0;
}