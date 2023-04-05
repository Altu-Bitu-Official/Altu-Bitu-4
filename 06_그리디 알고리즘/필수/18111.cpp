#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

const int MAX_HEIGHT = 257;
const int INF = 987'654'321;

// 모든 땅의 높이를 height로 만드는 비용 계산
int calcCost(int height, int n, int m, int b, vector<vector<int>>& blocks) {
    int cost = 0;
    int added = 0;      // 추가해야 하는 블록의 총 개수
    int removed = 0;    // 제거해야 하는 블록의 총 개수
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int gap = abs(height - blocks[i][j]);
            
            if (blocks[i][j] > height) {
                // 목표 높이보다 높은 칸인 경우, gap개의 블록 제거
                removed += gap;
            }
            else if (blocks[i][j] < height) {
                // 목표 높이보다 낮은 칸인 경우, gap개의 블록 추가
                added += gap;
            }
        }
    }
    
    // 전체 비용 계산
    cost = 2 * removed + added;
    
    // 블록 개수가 부족하다면 모든 땅의 높이를 height로 만드는 것이 불가능
    return (added > (b + removed)) ? INF : cost;
}

// 모든 땅의 높이를 같게 만드는 최소 비용과 그 때의 땅의 높이
pii makeGroundEven(int n, int m, int b, vector<vector<int>>& ground) {
    int minCost = INF;
    int height = 0;
    
    // 모든 높이를 다 만들어보고 최소 비용 찾기
    for (int i = 0; i < MAX_HEIGHT; i++) {
        int cost = calcCost(i, n, m, b, ground);
        if (cost <= minCost) {
            minCost = cost;
            height = i;
        }
    }
    
    return {minCost, height};
}

/**
 * 블록 높이의 최댓값이 256밖에 되지 않으므로
 * 모든 칸을 높이 n(0~256)으로 만드는 모든 경우를 시도해보고
 * 그 중에서 비용이 최소가 될 때를 찾는다.
 *
 * 모든 칸을 높이 n으로 만드는
 */

int main() {
    int n, m, b;
    
    // 입력
    cin >> n >> m >> b;
    vector<vector<int>> ground(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> ground[i][j];
        }
    }

    // 연산
    pii answer = makeGroundEven(n, m, b, ground);

    // 출력
    cout << answer.first << " " << answer.second << "\n";

    return 0;
}