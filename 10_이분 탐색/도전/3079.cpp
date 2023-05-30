#include <iostream> 
#include <vector>
#include <algorithm> 

using namespace std;

typedef long long ll;
const int MAX = 1e5;

/*
* 매개변수 탐색을 이용하여 입국 심사에 걸리는 시간을 계산합니다.
* 각 입국 심사에 걸리는 시간에 따라 심사가능한 인원을 계산한 후, 일행 인원과 비교해가며 진행합니다.
*/

ll paramSearch(ll &m, ll &n, vector<ll>& times, ll &max_wait) {
    // 최소 시간: 0, 최대 대기 시간: 최대 단일 대기시간*m
    ll left = 0, right = max_wait*m;
    // 대기 시간의 최댓값으로 설정 후 값을 줄여갑니다
    ll result = right;

    while (left <= right) {
        ll mid = (left + right) / 2;
        ll sum = 0; // mid만큼 기다릴 때, 입국심사 가능한 인원
        for (int i = 0; i < n; i++) {
            sum += mid / times[i];
            if (sum > m){
                break;
            }
        }
        // 입국심사 가능한 인원이 일행 수보다 크거나 같은 경우 -> 더 적게 기다릴 수도 있음
        if (sum >= m) {
            result = min(result, mid);
            right = mid - 1;
        }
        // 입국심사 가능한 인원이 일행 수보다 작은 경우 -> 더 오래 기다려야 함
        else {
            left = mid + 1;
        }
    }
    return result;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll n, m;
    ll max_wait = -1;
    vector<ll> times(MAX+1);

    // 입력
    cin >> n >> m;

    // 입국심사에 걸리는 시간 입력
    for (int i = 0; i < n; i++) {
        cin >> times[i];
        max_wait = max(max_wait, times[i]);
    }
    sort(times.begin(), times.begin()+n);

    // 연산 & 출력
    cout << paramSearch(m, n, times, max_wait);
    return 0;
}