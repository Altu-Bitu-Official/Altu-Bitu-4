#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 가장 인접한 두 공유기 사이의 거리가 dist가 되도록 공유기를 설치했을 때, 설치된 공유기 개수
int cntRouter(int dist, vector<int>& router) {
    // 첫번째 집에 무조건 공유기 설치
    int cnt = 1;
    int cur = router[0];

    for (int i = 1; i < router.size(); i++) {
        if (router[i] - cur >= dist) { // 가장 가까운 집과의 거리가 dist 이상이라면
            cnt++; // 공유기 설치
            cur = router[i];
        }
    }
    return cnt; // 설치된 공유기의 수
}

// 최소 인접 거리 중 최댓값 구하기
int binarySearch(int left, int right, int target, vector<int>& router) {
    while (left <= right) {
        // 가장 인접한 두 공유기 사이의 거리가 mid일 때, 설치할 수 있는 공유기 개수
        int mid = (left + right) / 2;
        int installed = cntRouter(mid, router);

        if (installed >= target) { // mid의 거리로는 target 개수 이상의 공유기를 설치할 수 있음 -> 거리를 늘려보자
            left = mid + 1;
        }
        else { // mid의 거리로는 target만큼의 공유기 설치할 수 없음 -> 거리를 줄여야 한다
            right = mid - 1;
        }
    }
    return left - 1; //upper bound값에서 1을 뺌
}

int main() {
    int n, c;

    // 입력
    cin >> n >> c;
    vector<int> house(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> house[i];
    }

    // 연산
    sort(house.begin(), house.end());

    // 연산 & 출력
    // 최소 거리: 1
    // 최장 거리: 가장 멀리 떨어진 두 집 사이의 거리
    cout << binarySearch(1, house[n - 1] - house[0], c, house);
    return 0;
}