#include <iostream>
#include <vector>
using namespace std;

/**m개의 집에서 k보다 작은 돈을 훔칠 수 있는 경우의 수 구하기*/
int steal(vector<int> house, int n, int m, int k) {
    int ans = 0;    // 훔칠 수 있는 가짓수
    int total = 0;  // 현재 도둑질한 돈
    int left = 0, right = m - 1;

    for(int i = left; i <= right; i++) {
        total += house[i];
    }
    if(n == m) { // 모든 집을 훔쳐야하는 경우 -> 즉시 리턴
        return total < k;
    }

    while(left != n) { // 슬라이딩 윈도우
        if(total < k) { // 도둑질한 돈이 k보다 작으면 훔칠 수 있음
            ans++;
        }
        total -= house[left++];
        right = (right+1) % n;
        total += house[right];
    }
    return ans;
}
/**[백준 13422: 도둑]
 * 1. 윈도우의 크기를 m으로 설정하고, 윈도우를 시계방향으로 움직이면서 도둑질할 수 있는 돈 계산
 * 2. right는 left보다 m만큼 떨어지는 집으로 설정하면, 마을이 원 모양으로 생겼으므로 right가 인덱스 범위를 벗어날 수 있음!
 *    -> right = (left + m)이 아닌 right = (left + m) % n
 * 3. (주의) n == m인 경우, 모든 집을 훔쳐야 하므로 슬라이딩 윈도우로 탐색하지 않고 바로 현재 값 리턴
*/
int main() {
    int t, n, m, k;
    vector<int> house;
    
    // 입력
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        house.assign(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> house[i];
        }

        // 연산 & 출력
        cout << steal(house, n, m, k) << "\n";
    }
    return 0;
}