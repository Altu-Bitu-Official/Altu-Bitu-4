// 13422 도둑
/*
    누적 합(prefix sum)에서 '슬라이딩 윈도우' 기법을 이용하여 풀었습니다.
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solve(vector<int> &home, vector<int> &psum, int &N, int &M, int &K) {
    int answer = 0;
    int s = 0, e = M-1;
    while(s <= e && e < N+M) {
        if(psum[e] - psum[s-1] < K){
            answer++;
        }
        s++; e++;
    }
    return answer;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        int N, M, K;
        vector<int> home(N);
        vector<int> psum(N+M);
        cin >> N >> M >> K;
        for(int i = 0; i < N; i++){
            cin >> home[i];
        }
        psum[0] = home[0];
        for(int i = 1; i < N+M; i++){ //psum은 N+M-1 인덱스까지 저장 
            psum[i] = psum[i-1] + home[(i-1)%N];
        }
        cout<< solve(home, psum, N, M, K) << "\n";
    }
}