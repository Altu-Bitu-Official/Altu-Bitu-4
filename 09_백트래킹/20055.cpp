// 20055 컨베이어 벨트 위의 로봇
// 시뮬레이션 + 자료구조 덱을 이용하여 풀었습니다.(회전시키는 것 구현= 자료구조 덱 이용)
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;
void rotateBelt(deque<int> &conveyer_belt, deque<bool> &is_exist){
        int tmp = conveyer_belt.back();
        conveyer_belt.push_front(tmp);
        conveyer_belt.pop_back();
        int rob = is_exist.back();
        is_exist.push_front(rob);
        is_exist.pop_back();
}

int solve(deque<int> &conveyer_belt, deque<bool> &is_exist, int &N, int &K){
    int answer = 0;
    while(true){
        // 현재 턴에서 컨베이어 벨트의 내구도를 측정한다.
        int duraBility = 0;
        for(int i = 0; i < conveyer_belt.size(); i++){
            if(conveyer_belt[i] == 0){
                duraBility++;
            }
        }
        if(duraBility >= K) {
            break;
        }
            answer++;
            // -- 벨트를 회전 시킵니다. --
            rotateBelt(conveyer_belt, is_exist);
            is_exist[N-1] = false;
            for(int i = N-2; i >= 0; i--){
                if(is_exist[i] == true && is_exist[i+1] == false){
                    if(conveyer_belt[i+1] >= 1){
                        conveyer_belt[i+1]--;
                        is_exist[i] = false;
                        if(i == N-2) { //로봇 땅에 내리기 
                            continue;
                        }
                        is_exist[i+1] = true;
                    }
                }
            }
            if(is_exist[0]== false) {
                if(conveyer_belt[0] >= 1){
                    is_exist[0] = true;
                    conveyer_belt[0]--;
                }
            }
    }
    return answer;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N, K;
    cin >> N >> K;
    deque<int> conveyer_belt; // 컨베이어 벨트 := 덱 구현
    deque<bool> is_exist; // 로봇이 있는지 없는지 확인해주는 덱 배열
    for(int i = 0; i < 2 * N; i++){
        int x;
        cin >> x;
        conveyer_belt.push_back(x);
        is_exist.push_back(false);
    }
    cout << solve(conveyer_belt, is_exist, N, K);
}
