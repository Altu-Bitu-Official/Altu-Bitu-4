// 컨베이어 벨트 위의 로봇
#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

int n, k, cnt = 0; // 내구성인 0인 곳 개수
int a[200];
bool robot[100] = {false};

void backtrack(int num){ // 단계
    // 종료조건
    if (cnt >= k){
        cout << num-1;
        return;
    }
    // num 단계 시작
    // 벨트 한 칸 회전 -> 인덱스(num) 조정
    // 2*n - num이 항상 양수가 되도록 => 2*n-num%(2*n)
    
    if (robot[(2*n+n-1-num%(2*n))%(2*n)]){ // 내리는 위치에 로봇이 있으면
        robot[(2*n+n-1-num%(2*n))%(2*n)] = false; // 로봇 내림
    }
    
    // 로봇 앞으로 움직이기 - 올리는 위치 다음부터 내리는 위치 전까지 검사하면 됨. 내리는 위치에 가까울수록 먼저 올라온 로봇
    for (int i = 0; i<n-1; i++){
        if (robot[(2*n+n-2-num%(2*n)-i)%(2*n)] && (!robot[(2*n+n-1-num%(2*n)-i)%(2*n)]) && a[(2*n+n-1-num%(2*n)-i)%(2*n)]){ // 로봇의 앞 칸에 내구성이 0이 아니면
            robot[(2*n+n-1-num%(2*n)-i)%(2*n)] = true;
            robot[(2*n+n-2-num%(2*n)-i)%(2*n)] = false;
            a[(2*n+n-1-num%(2*n)-i)%(2*n)]--;
            
            if (!a[(2*n+n-1-num%(2*n)-i)%(2*n)]) // 내구도가 0이 되면
                cnt++;
        }
    }
    if (robot[(2*n+n-1-num%(2*n))%(2*n)]){ // 내리는 위치에 로봇이 있으면
        robot[(2*n+n-1-num%(2*n))%(2*n)] = false; // 로봇 내림
    }
    
    // 로봇 올리기
    if (a[(2*n-num%(2*n))%(2*n)] > 0){ // 올리는 위치에 내구도가 0보다 크면
        robot[(2*n-num%(2*n))%(2*n)] = true; // 로봇을 올림  
        a[(2*n-num%(2*n))%(2*n)]--; // 내구도 감소
        
        if (!a[(2*n-num%(2*n))%(2*n)]) // 내구도가 0이 되면
            cnt++;
    }
    if (robot[(2*n+n-1-num%(2*n))%(2*n)]){ // 내리는 위치에 로봇이 있으면
        robot[(2*n+n-1-num%(2*n))%(2*n)] = false; // 로봇 내림
    }

    backtrack(num+1);
}

int main(){
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> k;
    
    for (int i=0; i<(2*n); i++){
        cin >> a[i];
    }
    
    backtrack(1);
    
    return 0;
}