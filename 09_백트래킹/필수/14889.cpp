// 스타트와 링크
#include <iostream>
#include <cmath>
using namespace std;

int n, MIN_VAL = 1000000000;
int member[21][21]; // 멤버들의 능력치
bool is_used[21] = {false}; // is_used가 true이면 start팀, false이면 link팀으로 판단

void backtrack(int num, int cnt){
    // 종료조건
    if (cnt == (n/2)){
        int diff = 0; // 두 팀의 점수 차이
        
        for (int i=1; i<=n; i++){
            for (int j=i+1; j<=n; j++){ // 다음 멤버는 i 이후 멤버에서 찾기
                if (is_used[i] == is_used[j]){ // 멤버 i와 j가 같은 팀이면 
                    if (is_used[i]) // start 팀이면
                        diff += (member[i][j] + member[j][i]);
                    else // link 팀이면
                        diff -= (member[i][j] + member[j][i]);
                }
            }
        }
        // 최솟값 갱신
        if (MIN_VAL > abs(diff)){
            MIN_VAL = abs(diff);
            return;
        }
    }
    // 시간초과 발생 주의 - 팀 멤버 영입 순서는 상관X -> 이미 영입한 멤버 뒤의 번호에서만 탐색
    for (int i=num; i<=n; i++){
        if (is_used[i]) // 이미 사용된 멤버이면
            continue;
        // 사용
        is_used[i] = true; // start 팀에 멤버 영입
        
        backtrack(i+1, cnt+1);
        
        //반납
        is_used[i] = false;
    }
}

int main(){
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            cin >> member[i][j];
    
    backtrack(1,0);
    
    cout << MIN_VAL;
    
    return 0;
}