#include <iostream>

using namespace std;
const int INF=1000000;
const int MAX=502;

int v[MAX][MAX];

void sol(int n){//학생수를 인자로 가진다
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(v[j][k]>v[j][i]+v[i][k]){
                    v[j][k]=v[j][i]+v[i][k];
                }
            }
        }
    }
}

int main(){
    int n, m;
    
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            v[i][j]=INF;
        }
    }

    for(int i=0;i<m;i++){
        int a, b;//a가 작은 학생 b가 큰 학생
        cin >> a >>b;
        v[a][b]=1;
    }

    sol(n);

    int answer=0;

    for(int i=1;i<=n;i++){
        int count=0;
        for(int j=1;j<=n;j++){
            if(v[i][j]!=INF || v[j][i]!=INF){
                count++;
            }
        }
        if(count==n-1){
            answer++;
        }
    }
    cout << answer;

}