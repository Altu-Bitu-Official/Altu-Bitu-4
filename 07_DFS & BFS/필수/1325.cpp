#include <iostream>
#include <vector>
#include <algorithm>

using  namespace std;

vector<int> trust[10001];
int visited_recur[10001];
int v;

int dfs(int s){
    int cnt = 1;
    visited_recur[s] = v;

  //cout<< v << ' '<< s <<' '<<cnt<<'\n';

    for(int i=0; i<trust[s].size(); i++){
        int t = trust[s][i];
        
        if(visited_recur[t]!=v){
            cnt += dfs(t);
        }
    }
    return cnt;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int m, n;
    int n1, n2;

    int max = 0;

    cin >> n >> m;

    int count[n+1];

    for(int i=0; i<m; i++){
        cin >> n1 >> n2;
        trust[n2].push_back(n1);
    }

    for(int i=1; i<=n; i++){
        v = i; 
        //https://sdev.tistory.com/552
        //visited_recur을 매 반복문마다 0으로 초기화 하지 않고 반복문을 시행하는 방법 참고
        count[i] = dfs(i);
        if(max<count[i]){
            max = count[i];
        }
    }

    for(int i=1; i<=n; i++){
        if(count[i] == max){
            cout << i << ' ';
        }
    }

    return 0;
}