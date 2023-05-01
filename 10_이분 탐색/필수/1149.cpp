#include <iostream>

using namespace std;
int mymin=1000000000;
int v1[1001][4];
int v2[1001][4];

int main()
{
    //입력
    ios_base::sync_with_stdio();
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    
    //i: 집의 수
    //j: 색깔(빨강, 초록, 파랑)
    for(int i=1; i<=n; i++){
        for(int j=1; j<4; j++){
            cin >> v1[i][j]; 
            //v1[i][j]에 비용 저장 
            //v2[i][j]에 비용의 최솟값 저장 
            
            //i번째 집에 칠할 색깔에 따라 경우의 수를 나눠서
            //최솟값을 저장 
            if(j==1){
                //빨강 
                v2[i][j]=min(v2[i-1][2],v2[i-1][3])+v1[i][j];
            }
            else if(j==2){
                //초록 
                v2[i][j]=min(v2[i-1][1],v2[i-1][3])+v1[i][j];
            }
            else if(j==3){
                //파랑 
                v2[i][j]=min(v2[i-1][1],v2[i-1][2])+v1[i][j];
            }
        }
    }
    for(int i=1; i<4; i++){
        //n번째까지 칠했을 때 최솟값 구하기
        mymin = min(mymin, v2[n][i]);
    }
    cout << mymin << endl;
    return 0;
}