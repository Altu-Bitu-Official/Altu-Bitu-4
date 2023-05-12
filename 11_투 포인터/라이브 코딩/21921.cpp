#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> ci;

//슬라이딩 윈도우로 최대 방문자 수(ans)와 그 기간의 개수를 pair로 리턴
ci slidingWindow(vector<int> &count, int n, int x) {
    // 윈도우 초기화
    int left = 1, right = x;
    int visitor = 0; // 방문자 수
    int cnt = 1;     // 최대 방문자 수 기간 개수

    for (int i = left; i <= right; i++) {
        visitor += count[i];
    }
    int max_visitor = visitor;   // 최대 방문자 수

    while (right < n) {
        visitor -= count[left++];  // 이번 윈도우에서 제외
        visitor += count[++right]; // 이번 윈도우에서 추가

        if (visitor > max_visitor) {    // 현재 방문자 수(section_visitor)가 최대 방문자 수(ans)보다 크다면
            max_visitor = visitor; // 최대 방문자 수(ans) 갱신
            cnt = 1; // 최대 방문자 수 기간 개수 초기화
        }
        else if (visitor == max_visitor) { // 현재 방문자 수(section_visitor)가 최대 방문자 수(ans)와 같다면
            cnt++;   // 최대 방문자 수 기간 개수 1 추가
        }
    }
    return {max_visitor, cnt};
}

ci prefixSum(vector<int> &count, int n, int x) {
    int max_visitor = 0, cnt = 0;
    vector<int> sum(n + 1, 0); // i번째 일까지의 방문자 수 누적합 저장하는 배열
    for(int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + count[i];
    }

    for(int i = x; i <= n; i++) {
        int visitor = sum[i] - sum[i - x]; // i-x부터 x일간 방문자 수
        if (visitor > max_visitor) { // 최대 방문자 수 갱신
            max_visitor = visitor;
            cnt = 1;
        }
        else if (visitor == max_visitor) { // 최대 방문자 수가 같은 경우 기간 개수 갱신
            cnt++;
        }
    }
    return {max_visitor, cnt};
}

int main() {
    int x, n;
    vector<int> count;
    
    // 입력
    cin >> n >> x;
    count.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> count[i];
    }

    // 연산
    ci ans = slidingWindow(count, n, x);
    // ci ans = prefixSum(count, n, x);

    // 출력
    if (ans.first == 0) { // 최대 방문자 수가 0이면
        cout << "SAD";
    } else {
        cout << ans.first << "\n" << ans.second;
    }

    return 0;
}