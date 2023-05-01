#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
string luckyWheel(vector<int> rolling, vector<string>point, int n, int k) {
	//계산
	vector<string> wheel(n, "?");
	int start = 0;
	int index = 0;
	for (int i = 0; i < k; i++) {
		index = (start + rolling[i]) % n;
		//써도 되면 쓰기
		if (wheel[index] == "?" || wheel[index] == point[i])
		{
			wheel[index] = point[i];
			//같은 알파벳 2개이상 있으면 !출력
			int ind = index;
			for (int j = 0; j < n; j++) {
				string alphabet = point[i];	
				ind++;
				if (ind % n == index)
				{
					continue;
				}
				if (alphabet == wheel[(ind) % n]) {
					return "!";
				}
			}
		}
		//쓰면 안 되는 상황-> ! 리턴
		else {
			
			return "!";
		}
		start = index;//start point 업데이트
	}
	string answer = "";
	for (int i = 0; i < n; i++) {
		if (index < 0) {
			index = n - 1;
		}
		answer += wheel[(index--) % n];
	}
	return answer;
}
int main() {
	//입력
	int n, k;//룰렛 칸 수, 룰렛 돌리는 횟수
	cin >> n >> k;
	vector<int> rolling(k);//돌리는횟수
	vector<string> point(k);//멈춘 알파벳
	for (int i = 0; i < k; i++) {
		cin >> rolling[i] >> point[i];
	}

	//계산&출력
	cout << luckyWheel(rolling, point, n, k);
	return 0;
}