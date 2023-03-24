#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int ALPHA = 64;

//말의 위치를 이동하는 함수
vector<int> moveKing(string s) {
	vector<int> result(2, 0);

	if (s == "R") {
		result[0]++;
		return result;
	}
	else if (s == "L") {
		result[0]--;
		return result;
	}
	else if (s == "B") {
		result[1]--;
		return result;
	}
	else if (s == "T") {
		result[1]++;
		return result;
	}
	else if (s == "RT") {
		result[0]++;
		result[1]++;
		return result;
	}
	else if (s == "LT") {
		result[0]--;
		result[1]++;
		return result;
	}
	else if (s == "RB") {
		result[0]++;
		result[1]--;
		return result;
	}
	else if (s == "LB") {
		result[0]--;
		result[1]--;
		return result;
	}
	return result;
}

//말이 이동 가능한지 (체스판 밖을 벗어나지 않는지)의 여부 반환 함수
bool available(vector<int>& king, vector<int>& result) {
	if (king[0] + result[0] < 1 || king[0] + result[0] > 8) {
		return false;
	}
	if (king[1] + result[1] < 1 || king[1] + result[1] > 8) {
		return false;
	}
	return true;
}

//킹이 이동할 때, 돌과 같은 곳으로 이동하는지의 여부 반환 함수
bool sameStone(vector<int>& king, vector<int>& stone, vector<int>& result) {
	if (king[0] + result[0] == stone[0] && king[1] + result[1] == stone[1]) {
		return true;
	}
	return false;
}

//N동안 킹과 돌을 이동하는 함수
void solution(vector<int>& king, vector<int>& stone, vector<string>& move) {
	for (int i = 0; i < move.size(); i++) {
		vector<int> result = moveKing(move[i]);

		//1. 돌과 같은 곳으로 이동하는 경우
		if (sameStone(king, stone, result)) {
			//1) 돌이 체스판 밖에 나가지 않는 경우 -> 킹과 돌을 같은 방향으로 이동
			if (available(stone, result)) {
				stone[0] += result[0];
				stone[1] += result[1];
				king[0] += result[0];
				king[1] += result[1];
			}

			//2) 돌이 체스판 밖에 나가는 경우 -> 해당 이동 건너뛰기
			else {
				continue;
			}
		}

		//2. 돌과 다른 곳으로 이동하는 경우
		else {
			//1) 킹이 체스판 밖에 나가지 않는 경우 -> 킹만 이동
			if (available(king, result)) {
				king[0] += result[0];
				king[1] += result[1];
			}

			//2) 킹이 체스판 밖에 나가는 경우 -> 해당 이동 건너뛰기
			else {
				continue;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	string p1, p2;
	int n;
	cin >> p1 >> p2 >> n;

	vector<int> king(2);
	vector<int> stone(2);
	king[0] = p1[0] - ALPHA; king[1] = p1[1] - '0';
	stone[0] = p2[0] - ALPHA; stone[1] = p2[1] - '0';

	vector<string> move(n);
	for (int i = 0; i < n; i++) {
		cin >> move[i];
	}

	//연산
	solution(king, stone, move);

	//출력
	cout << (char)(king[0] + ALPHA) << king[1] << "\n";
	cout << (char)(stone[0] + ALPHA) << stone[1] << "\n";

	return 0;
}