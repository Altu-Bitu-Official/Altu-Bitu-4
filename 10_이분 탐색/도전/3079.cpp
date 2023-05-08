// 3079 입국심사
/*
  탐색 대상은 mid 시간일 때 처리할 수 있는 사람의 수
  처리할 수 있는 사람의 수가 상근이와 친구들보다 많으면 채택, 적으면 기각
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef unsigned long long ull;

bool chk(ull &mid, vector<ull> &times, ull &M){
    ull possible = 0;
    for(int i = 0; i < times.size(); i++){
        possible += (mid/times[i]);
    }
    if(possible >= M){
        return true;
    } 
    else {
        return false;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    ull N, M;
    cin >> N >> M;
    vector<ull> times;
    while(N--){
        ull x;
        cin >> x;
        times.push_back(x);
    }
    sort(times.begin(), times.end()); // 오름차순 정렬
    // 탐색 대상은 mid 시간일 때, 처리할 수 있는 사람의 수와의 관계식을 통해
    // 상근이와 친구들보다 더 많은 사람을 처리할 수 있다면 O, 아니라면 X입니다.
    ull lo = 1, hi = times[times.size()-1]*M;
    ull mid;
    ull ans = 0;
    while(lo <= hi){
        mid = (lo + hi)/2;
        if(chk(mid, times, M)){
            hi = mid - 1;
            ans = mid;
        }
        else {
            lo = mid + 1;
        }
    }
    cout << ans << "\n";
}