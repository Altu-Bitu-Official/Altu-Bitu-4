#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n, cnt = 0;//n: 숫자, cnt: 666갯수
	//입력
	cin >> n;//n입력받기
	//연산 & 출력
	for (int i = 666; i < 2066666666; i++) {//작은수부터 세면 알아서 그 다음숫자 구해짐
		// 방법 1
		string s = to_string(i);//i를 string으로
		int suc = 0; // 연속하는 6의 개수
		for (int j = 0; j < s.length(); j++) {//그 숫자길이만큼
			if (s[j] == '6') {//6들어가면
				suc++;//1증가
			}
			else {//안들어가면
				suc = 0;//0: 연속이아님
			}
			if (suc == 3) {//연속3개 도출되면
				cnt++;//카운트++: n이 1이면 카운트도 1이어서 나감. 이렇게 n과 같아지게 카운트를 증가시킴
				break;//나가기
			}
		}
		/*
		* 방법 2
		* s.substr(j, 3) == "666"
		* substr 사용법 : https://en.cppreference.com/w/cpp/string/basic_string/substr
		* 방법 3
		* if (s.find("666") != -1)
		* find 사용법 : https://en.cppreference.com/w/cpp/string/basic_string/find
		*/
		if (cnt == n) {//카운트랑 n이랑 같으면(연속666인거 찾을때마다 카운트하니까, n 번째 시리즈를 카운트로 판별가능
			return cout << s, 0;//그게 답안->출력
		}
	}
}