#include <iostream>
#include <vector>
#include <string>

using namespace std;

//연산하는 함수
int cal(int n) {
	int cnt = 0; // 숫자 카운트
	int num = 666; // 벡터 배열 크기

	while (true) {

		string s = to_string(num); //string으로 변환
		if (s.find("666") == string::npos) { //연속으로 이루어진 666을 찾지 못하면 
			num++; //다음수로 이동
			continue;
		}
		
		cnt++; // 연속으로 이루어진 666을 찾았다면 cnt 1 증가 

		if (cnt == n) { // cnt값이 n과 같아지면 num을 반환
			return num;
		}

		num++; //아직 같아지지 않았다면 다음 수로 이동
		
	}
}

int main()
{
	int n, result;
	//입력

	cin >> n;

	//연산
	result = cal(n);

	//출력
	cout << result;

	return 0;
	
}