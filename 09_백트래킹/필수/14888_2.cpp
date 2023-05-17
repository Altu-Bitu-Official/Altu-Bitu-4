// 연산자 끼워넣기
#include <iostream>
using namespace std;

int num[11];
int op[4];

int n, MIN_VAL = 1000000000, MAX_VAL = -1000000000;

void backtrack(int VAL, int cnt){
    // 재귀 종료 조건
    if (cnt == n){
        if (VAL < MIN_VAL){
            MIN_VAL = VAL;
        }
        if (VAL > MAX_VAL){
            MAX_VAL = VAL;
        }
        return;
    }
    // 사용
    for (int i=0; i<4; i++){
        // 이미 사용된 연산자이면
        if (op[i] == 0)
            continue;
        
        // 사용
        op[i]--;
        
        if (i == 0){ // 연산자가 +이면
            backtrack(VAL + num[cnt], cnt+1);
        }
        else if (i == 1){ // 연산자가 -이면
            backtrack(VAL - num[cnt], cnt+1);
        }
        else if (i == 2){ // 연산자가 *이면
            backtrack(VAL * num[cnt], cnt+1);
        }
        else{ // 연산자가 /이면
            backtrack(VAL / num[cnt], cnt+1);
        }
        
        // 반납
        op[i]++;
    }
}

int main(){
    
    cin >> n;

    for (int i=0; i<n; i++)
        cin >> num[i];
    for (int i=0; i<4; i++)
        cin >> op[i];
    
    backtrack(num[0], 1);
    
    cout << MAX_VAL << '\n';
    cout << MIN_VAL;
    
    return 0;
}