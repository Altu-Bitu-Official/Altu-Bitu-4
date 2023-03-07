//1158 요세푸스 문제
//덱, 혹은 큐 자료구조를 이용할 수 있는 문제
#include <iostream>
#include <deque>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, k;
	cin >> n >> k;
	deque<int> dq;
	for(int i =1; i<=n; i++) dq.push_back(i); //1234567 저장
     cout << "<";
	while(dq.size()>1) { //한 개 남기고
		for(int i =0; i <k-1; i++) { //k-1번 반복:=k번째가 됐을 때를 제외하고는 앞에서 뽑아내고 뒤로 삽입하는 구조는 똑같음
			int t =dq.front(); //1 //2
			dq.pop_front(); //234567 //345671
			dq.push_back(t); //2345671 //3456712
		}
		//k번째 됐을 때에는 앞에서 뽑아내고 그대로 출력해준다.
		int t= dq.front(); //3
		dq.pop_front(); //456712
		cout << t << ", ";
	}
	if(dq.size()==1) {
		int t =dq.front();
		cout << dq.front() << ">\n";
	}
	return 0;
}