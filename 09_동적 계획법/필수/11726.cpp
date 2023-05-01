#include <iostream>
#include <vector>
using namespace std;

int tileNumber(vector<int>& answer, int n) {
	if (n == 2 || n == 1)
	{
		return answer[n];
	}
	for (int i = 3; i <= n; i++) {
		answer[i] = (answer[i - 1] + answer[i - 2]) % 10007;
	}

	return answer[n];
}

int main() {
	//n이 1일 때: 1
	//n이 2일 때: 2
	//n이 3일 때: 3
	//n이 4일 때: 5
	//규칙: S[n]=S[n-1]+S[n-2]
	//->n이 1일때, n이 2일때 값만 넣어줘도 계산 가능
	//n이 1일때, 2일때는 고정값 리턴.

	//입력
	int n=0;
	cin >> n;

	//계산
	vector<int> answer(n + 1, 0);
	answer[1] = 1;
	answer[2] = 2;
	tileNumber(answer, n);
	
	//출력
	cout << answer[n] ;

	return 0;
}