// N과 M (1)
#include <iostream>
#include <vector>

using namespace std;

int n, m;
const int MAX_N = 8;
bool is_used[MAX_N+1];
int sequence[MAX_N+1];

void printSequence(){
    for (int i=0; i<m; i++){
        cout << sequence[i] << " ";
    }
    cout << "\n";
}

void backtrack(int cnt){
    // 종료 조건
    if (cnt == m){
        printSequence();
        return;
    }
    for (int i=1; i<=n; i++){
        // 이미 사용된 숫자라면
        if (is_used[i]){
            continue;
        }
        // 사용
        sequence[cnt] = i;
        is_used[i] = true;
        
        // 다음 숫자 뽑기
        backtrack(cnt+1);
        
        // 반납
        is_used[i] = false;
    }
}

int main(){
    
    cin >> n >> m;
    backtrack(0);
    
    return 0;
}