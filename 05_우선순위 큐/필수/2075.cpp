#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, tmp;
    cin >> n;

    //우선순위 큐 제일 작은 수가 위에 오도록 정렬
    priority_queue<int, vector<int>, greater<int> > pq;

    for(int i=0; i<n*n; i++) {
        cin >> tmp;

        //큐에 넣고
        pq.push(tmp);

        //큐 사이즈 n보다 크면 하나 pop
        //작은 수부터 빠지니까 마지막에는 큰 수 n개만 남음
        if(pq.size()>n){
            pq.pop();
        }
    }

    cout << pq.top();

    return 0;
}