#include <iostream>
#include <queue>
#include <string>
using namespace std;
int main() {
	priority_queue<int> pq; //큰 숫자에 우선순위.
	
	int n;
	cin >> n;//반복횟수 
	string answer="";
	
	//계산
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		if (input == 0) {//아이들을 만남-> 선물을 준다.
			//선물 주머니가 비어있으면-> -1
			if (pq.empty()) {
				answer+= "-1\n";
			}
			else {//선물 주머니에 뭐가 들어있으면-> 우선순위 높은 것 팝&출력
				answer+=to_string(pq.top())+"\n";
				pq.pop();
			}
		}
		else {//나머지 경우 : 거점
			for (int j = 0; j < input; j++) {//선물채우기
				int gift;
				cin >> gift;
				pq.push(gift);
			}
		}
	}

	//출력
	cout << answer;
	
	return 0;
}