#include <iostream>
#include <vector>
using namespace std;
void initialize(vector<char> &roullete, int N) {
	for(int i =0; i < N; i++) {
		roullete[i]='?'; //초기에는 다 '?'로 셋팅되어있다.
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int N, K, idx;
	cin >> N >> K; //바퀴의 칸수 N, 바퀴를 돌리는 횟수 K
	vector<char> roullete(N);
	initialize(roullete, N);
	bool flag= true; //예외처리:= true면 ok, false면 예외인 경우
	int res=0;
	for(int i = 0; i < K; i++) {
		int NUM; char ch;
		cin >> NUM >> ch; //NUM:=글자 바뀐 갯수, ch:=문자
		
		idx = (idx + NUM) % N;
		
		// 예외처리 먼저 해주기.
		// 구한 idx칸에는 한 개의 알파벳만 들어가 있어야 함 --> 예외처리
		// 해당 idx에 '?'가 아니라는 말은 이미 다른 알파벳으로 차 있다는 뜻
		// 해당 idx가 'ch'가 아니라는 말은 알파벳이 두개 들어가있음
		if(roullete[idx] != '?' && roullete[idx]!= ch) {
			cout << "!\n"; 
			flag = false;
		} 
		roullete[idx]= ch; //아니면 해당 idx에는 ch값
	}
	for(int i =0; i < N; i++) {
		for(int j= i+1; j < N; j++) {
			if(roullete[i] != '?' && roullete[i]==roullete[j]){
				cout << "!\n"; 
				flag = false;
		 	}
		}
	}
	// 예외처리 조건에 다 걸리지 않는 경우라면 이전 인덱스값
	if(flag) {
		for(int i = idx; i < N; i++) {
			cout << roullete[i];
		}
		for(int i =0; i < idx; i++) {
			cout << roullete[i];
		}
		cout << "\n";
		return 0;
	}
}