#include <iostream>

using namespace std;

int main() {
	int n;
	int tile[1000] = { 0, };

	// 입력
	cin >> n;
	
	// 연산
	tile[1] = 1;
	tile[2] = 2;
	for (int i = 3; i <= n; i++) {
		tile[i] = (tile[i - 1] + tile[i - 2]) % 10007;	// 질문 게시판 참고해서 수정한 부분
	}

	// 출력
	cout << tile[n];
	return 0;
}

/*
문제에 주어진 예제는 통과하나 채점 결과는 틀리다고 나와서 반례를 찾기 위해 질문 게시판을 참고하였습니다.
https://www.acmicpc.net/board/view/112565
기존에 작성했던 코드에서도 n의 값이 커지면 음수가 나왔고, 위의 글을 참고하여 음수가 나오는 이유를 파악한 후에 코드를 수정하였습니다.
*/