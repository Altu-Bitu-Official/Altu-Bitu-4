#include<iostream>
#include <vector>
#include<queue>

using namespace std;//std 선언

/*
* HINT : 가운데를 찾기 위해 현재까지 입력된 숫자중 비교적 작은 값과 큰 값을 따로 저장하면 좋을 것 같네요!
*/

void balance(priority_queue<int>& max_pq,//최대힙의 모든 노드가 최소힙의 루트노드보다 작거나 같도록 균형을 맞춘다.
	priority_queue<int, vector<int>, greater<>>& min_pq) {
	int M, m;
	
	if (max_pq.top() > min_pq.top()) { // max_pq의 가장 큰 값이 min_pq의 가장 작은 값보다 크다면 저장 위치가 잘못 된 것!
		// 각각의 top값을 바꿔서 저장
		M = max_pq.top();//최대힙의 top값을 임시변수에 저장
		m = min_pq.top();//최소힙의 top값을 임시변수에 저장

		max_pq.pop();//최대힙과
		min_pq.pop();//최소힙의 우선순위 1순위값(루트노드) 버림

		max_pq.push(m);//최대힙의 루트노드를 최소힙의 루트노드였던것으로
		min_pq.push(M);//최소힙의 루트노드를 최대힙의 루트노드였던 것으로 바꿈
	}

	return;
}

/*
* 입력된 수들 중 비교적 작은 값은 최대힙에 저장하고 큰 값은 최소힙에 저장하자
* 가운데를 찾기 위해서는 최대힙과 최소힙 개수 차이가 0이나 1이어야 한다
* 최대힙의 top값이 가운데이도록 하기 위해 최대힙의 사이즈가 최소힙의 사이즈와 같거나 1 더 크게 저장하자
* 개수를 기준으로 저장했기에 저장 위치가 잘못됐을 수도 있다. -> 균형을 맞춰주자 (balance)
*/


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);//속도향상 코드

	int n, input;
	priority_queue<int> max_pq; // 비교적 작은 값을 저장해둔 최대힙
	priority_queue<int, vector<int>, greater<>> min_pq; // 비교적 큰 값을 저장해둔 최소힙

	// 입력
	cin >> n;

	// 연산 + 출력
	for (int i = 0; i < n; i++) {
		cin >> input;

		// max_pq의 사이즈가 min_pq의 사이즈와 같거나 하나 더 많도록 저장 
		if (max_pq.size() > min_pq.size()) {//최대힙의 노드개수가 최소힙보다 크면
			min_pq.push(input);//최소힙에 값 저장
		}
		else {//최대힙의 노드개수가 최소힙과 같거나 작으면
			max_pq.push(input);//최대힙에 값 저장
		}

		// 두 개의 pq모두 원소가 존재할 때 균형을 맞춰주자
		if (!max_pq.empty() && !min_pq.empty()) {//최대힙과 최소힙 모두 비지 않았을 때
			balance(max_pq, min_pq);//최대힙의 모든 노드가 최소힙의 루트노드보다 작거나 같도록 균형을 맞춘다.
		}

		// 출력
		cout << max_pq.top() << "\n";

	}
	return 0;
}

//본인 코드
#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;

    priority_queue<int, vector<int>> max_h;
    priority_queue<int, vector<int>, greater<int>> min_h;
    int input;
    while(n--){
        cin >> input;
        if(max_h.empty()==1){
            max_h.push(input);
        }
        
        else{
            
        if(max_h.size()-min_h.size()==0){
            max_h.push(input);
        }
        else {
            min_h.push(input);
        }
        if(max_h.top()>min_h.top()){
            int maxTop=max_h.top();
            int minTop=min_h.top();

            max_h.pop();
            min_h.pop();
            max_h.push(minTop);
            min_h.push(maxTop);
        }
        }
        

        
         cout <<max_h.top() << '\n';
    }
   
    
}