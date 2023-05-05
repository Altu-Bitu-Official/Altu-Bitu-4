// 효율적인 해킹
// 테스트케이스 o, 제출하면 틀림. 반례?
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 10000;
vector<int> adj[MAX];   //벡터 adj[b]에 a가 있다 = b를 해킹하면 a도 해킹 가능하다.

void bfs(int n){
    queue<int> q;   //컴퓨터별로 bfs할 때 사용할 큐
    vector<int> answ;   //최고 가성비의 해킹 컴퓨터 저장함
    int biggest = 0;    //한 컴퓨터를 통해 해킹할 수 있는 컴퓨터의 개수 최댓값

    for(int j=1; j<n+1; j++){   //컴퓨터 1부터 n까지 확인한다다
        int cnt = 0;    //해킹 가능한 컴퓨터 개수
        q.push(j);
        vector<bool> visited(n+1,false);

        while(!q.empty()){
            int now = q.front();
            q.pop();
            for (int i=0; i<adj[now].size(); i++){
                int temp = adj[now][i];
                if (!visited[temp]){
                    visited[temp] = true;
                    q.push(temp);
                }
            }
            cnt++;
        }
        //cnt가 biggest보다 작으면
        //cnt가 biggest보다 크면, biggest 값을 갱신하고, answ의 기존원소 모두 지우고 해당 컴퓨터(j) 넣는다
        //cnt가 biggest와 같으면, answ에 해당 컴퓨터(j) 넣는다.
        if (cnt < biggest){
            break;
        }
        else if (cnt > biggest){
            biggest = cnt;
            answ.clear();
            answ.push_back(j);
        }
        else if (cnt = biggest){
            answ.push_back(j);
        }
    }
    
    //answ 출력
    for (auto i:answ){
        cout << i << ' ';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;   // 컴퓨터 개수 n, 관계 개수 m
    cin >> n >> m;

    while(m--){ 
        //a가 b를 신뢰한다. 즉, b를 해킹하면 a도 해킹 가능하다.
        int a, b; 
        cin >> a >> b; 
        adj[b].push_back(a);
    }

    bfs(n);
    return 0;
}