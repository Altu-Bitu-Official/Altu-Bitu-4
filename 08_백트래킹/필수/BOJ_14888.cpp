#include <iostream> 
#include <vector> 
#include <algorithm>
using namespace std;

int N; // 숫자 개수
vector <int>num(11,0); // 계산할 숫자들
vector <int> calc(4,0); // 연산자
vector <int> ans; // 결과 값 

void  backtrack(int n, int idx) {
	
	for (int i = 0; i < 4; i++) {
		if (calc[i] != 0) { // 연산자 존재하면
			calc[i]--; // 사용 
			
			if (i == 0)  backtrack(n + num[idx], idx + 1); //더하기
			if (i == 1)  backtrack(n - num[idx], idx + 1); // 빼기
			if (i == 2)  backtrack(n * num[idx], idx + 1); // 곱하기
			if (i == 3)  backtrack(n / num[idx], idx + 1); // 나누기

			calc[i]++; // 반납
		}
	}
	// N-1 인덱스의 숫자까지 연산한 경우 재귀 호출 종료
	if (idx == N) { 
		ans.push_back(n); // 결과 값 저장
		return; 
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 입력
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> calc[i];
	}
	backtrack(num[0], 1);
	// 결과 값 저장한 벡터 내에서 최소, 최대 출력
	cout << *max_element(ans.begin(), ans.end()) << "\n";
	cout << *min_element(ans.begin(), ans.end());

	return 0;
}