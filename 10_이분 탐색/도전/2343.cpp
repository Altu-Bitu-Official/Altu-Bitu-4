// 2343 기타 레슨
 /* 
    설정한 블루레이의 용량(각 블루레이 당 담을 수 있는 강의의 길이)가 커질 수록,
    담을 수 있는 강의의 갯수는 늘어납니다.[단조성이 보장됩니다]
    [강토가 가지고 있는 블루레이의 수를 넘어가지 않는다] 는 조건 내에서,
    후보군 용량 중 가장 작은 값을 추출해내는 것이므로 이분탐색 알고리즘을 이용할 수 있습니다.
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef unsigned long long ull;

bool chk(ull &mid, ull &N, ull &M, int lec[]){
    int need = 1; // 현재 턴에서 필요한 블루레이 개수(일단 강의를 하나 담고 시작)
    ull tmp_total = 0; // 현재 시점에서 담은 강의의 총 길이를 담은 변수
    for(int i = 0; i < N; i++) {
        if(tmp_total + lec[i] <= mid){ // 현재 시점의 강의를 담았을 때, 설정한 용량보다 작거나 같으면
            tmp_total += lec[i]; // 아직까지는 강의를 담을 수 있으므로 강의를 담습니다.
        }
        else { // 혹은 설정한 용량을 초과하므로, 다른 블루레이에 해당 강의를 담아야 합니다.
            tmp_total = lec[i]; //따라서 다음 블루레이 해당 강의를 넣고,
            need++; // 필요한 블루레이의 수를 증가시켜줍니다.
        }
    }
    if(need <= M){ // 필요한 블루레이 개수가 강토가 가진 블루레이 개수보다 적으면
        return true; // 해당 후보용량은 채택
    }
    else {
        return false; // 아니라면 해당 후보용량은 기각
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    ull N, M;
    int lec[100004];
    cin >> N >> M; //강의의 수, 강토가 가지고 있는 블루레이의 수
    ull lec_total = 0; // 총 강의 길이
    int mx= -987654321;
  /*
    주의 해야 할 점: sort(lec, lec+N); (X)
     가장 긴 강의의 길이값을 골라내야 한다고 해서, sort()함수를 이용하면 안됩니다.
     왜냐하면 문제 조건에 강의를 담는 순서가 보장되어야 한다고 되어있기 때문입니다.
     (저 같은 경우 sort()함수를 계속 이용하여 계속 오답이 나왔습니다)
  */
    for(int i = 0; i < N; i++){
        cin >> lec[i]; // 강의 길이 입력받기
        lec_total += lec[i];
        mx = max(mx, lec[i]);
    }
    // 탐색 대상은 블루레이 용량입니다.
    // lo, hi는 각각 설정할 수 있는 블루레이 용량(크기)의 최소/최댓값을 담고 있습니다.
    // lo는 적어도 모든 강의의 수를 하나씩은 담을 수 있어야 하므로, lec배열 중 가장 큰 값으로 설정해줍니다.
    ull lo = mx;
    // 만약, 블루레이 하나 당 용량이 강의의 총 길이이면, 블루레이 하나에 몽땅 담아버릴 수 있습니다.
    // 따라서 hi 는 강의의 총 길이입니다.
    ull hi = lec_total;
    ull mid;
    ull ans = 0;
    while(lo <= hi){
        mid = (lo + hi)/2;
        if(chk(mid, N, M, lec)) { // 조건을 만족하는 블루레이 용량의 최솟값을 담읍시다.
            hi = mid - 1; 
            ans = mid; 
        }
        else {
            lo = mid + 1;
        }
    }
    cout << ans << "\n";
}