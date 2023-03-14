#include <iostream>
#include <vector>
#include <string>

using namespace std;

int solution(int n) {
	int cnt = 0; //영화의 개수
	int i = 666; //탐색 시작 숫자
	
	while (cnt < n) {
		//666이 들어간 숫자면 영화 개수 늘림
		if (to_string(i).find("666") != string::npos) {
			cnt++;
		}
		i++;
	}
	//while문을 빠져나오면서 i가 1 증가된채로 나오므로 1만큼 빼주기
	return i - 1; 
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n;
	cin >> n;

	//연산 & 출력
	cout << solution(n);

	return 0;
}