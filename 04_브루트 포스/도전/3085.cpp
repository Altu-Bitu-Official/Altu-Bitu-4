// 사탕 게임

#include <iostream>
#include <cmath>
#define MAX 50

using namespace std;
// 연속된 문자 개수 세기
int counting(char s[MAX][MAX], int n){
    int max_cnt = 0, cnt;
    char a;
    for (int i=0; i<n; i++){
        a = s[i][0];
        cnt = 1;
        for (int j=1; j<n; j++){
            if (s[i][j] == a)
                cnt++;
            else{
                a = s[i][j];
                max_cnt = max(max_cnt, cnt);
                cnt = 1;
            }
            
        }
        max_cnt = max(max_cnt, cnt);
    }
    for (int i=0; i<n; i++){
        a = s[0][i];
        cnt = 1;
        for (int j=1; j<n; j++){
            if (s[j][i] == a)
                cnt++;
            else{
                a = s[j][i];
                max_cnt = max(max_cnt, cnt);
                cnt = 1;
            }
            
        }
        max_cnt = max(max_cnt, cnt);
    }
    return max_cnt;
}

int main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    char s[MAX][MAX] = {0,}, k, tmp;
    // 입력
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++){
            cin >> k;
            s[i][j] = k;
    }
    // 행렬의 인접한 두 값 바꾸기
    int ans = 0;
    for (int i=0; i<n; i++){
        for (int j = 0; j<n-1; j++){
            tmp = s[i][j];
            s[i][j] = s[i][j+1];
            s[i][j+1] = tmp;
            ans = max(ans, counting(s,n));
            s[i][j+1] = s[i][j];
            s[i][j] = tmp;
        }
    }
    for (int i=0; i<n-1; i++){
        for (int j = 0; j<n; j++){
            tmp = s[j][i];
            s[j][i] = s[j+1][i];
            s[j+1][i] = tmp;
            ans = max(ans, counting(s,n));
            s[j+1][i] = s[j][i];
            s[j][i] = tmp;
        }
    }
    cout << ans;
}