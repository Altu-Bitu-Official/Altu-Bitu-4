#include <iostream> // 입출력을 위한 헤더
#include <vector> // 벡터 객체를 사용하기 위한 헤더

using namespace std;

typedef pair<int, int> pii; // 최소 시간과 고른 높이를 출력하기 위한 구조체 pii 선언

const int MAX_HEIGHT = 256; // 고른 높이의 초기값 상수로 선언 
// 땅의 높이의 최대는 256이므로 초기에 최대로 선언
const int INF = 987654321; // 최소 시간의 초기값 상수로 선언

// 모든 땅의 높이를 기준 높이 (height)로 만드는 비용 계산하는 함수 
int calcCost(int height, int n, int m, int b, vector<vector<int>>& blocks) { 
    int cost = 0;         // 걸리는 시간 
    int added = 0;      // 추가해야 하는 블록 개수
    int removed = 0;    // 제거해야 하는 블록 개수

    for (int i = 0; i < n; i++) { // n행
        for (int j = 0; j < m; j++) { // m열의 모든 칸 순회
            int gap = abs(height - blocks[i][j]); // 기준 높이와 현재 블록의 높이 차
            // 블록을 추가 or 제거 -> gap만큼 추가 or 제거

            if (blocks[i][j] > height) {// 목표 높이보다 높은 칸인 경우
                removed += gap; // gap개의 블록 제거
            }
            else if (blocks[i][j] < height) {// 목표 높이보다 낮은 칸인 경우
                added += gap; //  gap개의 블록 추가
            }
        }
    }

    // 전체 비용 계산
    cost = 2 * removed + added;
    // 제거하는 데 2초, 추가하는 데 1초 걸림 -> 전체 비용 계산

    // 블록 개수가 부족하다면 모든 땅의 높이를 height로 만드는 것이 불가능
    return (added > (b + removed)) ? INF : cost;
    // 추가해야 하는 블록이 
    // (인벤토리에 있던 블록 + 제거되어 인벤토리에 넣은 블록) 개수보다 많으면
    // INF (굉장히 큰수) return하여 불가능하다고 선언
    // 그렇지 않다면 구한 최소 시간 반환
}

// 모든 땅의 높이를 같게 만드는 최소 비용과 그 때의 땅의 높이 구하는 함수
pii makeGroundEven(int n, int m, int b, vector<vector<int>>& ground) { 
    int minCost = INF; // 땅을 고르게 만드는 최소시간 
    int height = 0; // 고른 높이 

    // 가능한 높이 (0~256)를 모두 시도해보고, 그 중에서 최소 비용 찾기
    for (int i = 0; i <= MAX_HEIGHT; i++) { // i로 만드는 비용 계산, 업데이트
        // 계산
        int cost = calcCost(i, n, m, b, ground); // 높이로 i로 만드는 데 걸리는 최소 시간 

        // 업데이트
        if (cost <= minCost) {
            minCost = cost; // 0~256 돌면서 최솟값 업데이트
            height = i; // 그때의 i를 높이로 업데이트
        }
    }
    return { minCost, height }; // 최소시간, 고르게 만든 높이 반환
}

/**
 * 블록 높이의 최댓값이 256밖에 되지 않으므로
 * 모든 칸을 높이 n(0~256)으로 만드는 모든 경우를 시도해보고
 * 그 중에서 비용이 최소가 될 때를 찾는다.
 *
 * 모든 칸을 높이 n으로 만드는
 */

int main() { // 가장 먼저 실행되는 main 함수
    int n, m, b; // 행, 열, 인벤토리에 들어있는 블록의 개수
    cin >> n >> m >> b; // 입력

    vector<vector<int>> ground(n, vector<int>(m)); // ground라는 2차원 벡터 선언 (n행 m열)
    for (int i = 0; i < n; i++) { // n행
        for (int j = 0; j < m; j++) { // m열에 
            cin >> ground[i][j]; // 초기 블록 높이 입력
        }
    }

    // 연산
    pii answer = makeGroundEven(n, m, b, ground); // 땅을 고르게 만들고 난 후 최소시간, 높이를 answer로 받음

    // 출력
    cout << answer.first << " " << answer.second << "\n";
    // 높이를 고르게 만드는 데 걸리는 최소 시간, 그 고른 높이 출력
    return 0; // 메인 함수 종료
}