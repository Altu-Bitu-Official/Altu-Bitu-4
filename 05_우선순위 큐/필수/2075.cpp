#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

//n번째로 큰 수 = 커다란 순대로 n개 중에서 가장 작은 수
void push(priority_queue <int, vector<int>, greater<int>> &h, int num, int n){
    h.push(num);
    //힙 사이즈가 n 이상일때
    if(h.size() > n){
        h.pop();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n;
    int num;
    //오름차순 우선순위 큐
    priority_queue <int, vector<int>, greater<int>> h;

    //입력
    cin >> n;

    for(int i=0; i<n*n; i++){
        cin >> num;
        //heap에 비교 후 추가
        push(h, num, n);
    }

    //힙에는 n개의 수가 존재하는 상태
    //출력
    cout << h.top();
}