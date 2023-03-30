#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii; // int형 변수 두 개를 저장할 pair 구조체 pii 선언

const int MAX_HEIGHT = 257; // 땅의 최대 높이
const int INF = 987'654'321;    // 최소 시간 구하기 위해 초기값은 최대한 크게 설정

// 모든 땅의 높이를 height로 만드는 비용 계산
int calcCost(int height, int n, int m, int b, vector<vector<int>>& blocks) {    // 높이, 땅의 세로, 가로 길이, 블록 개수, 땅의 높이 저장된 벡터 전달
    int cost = 0;   // 비용 저장할 변수 선언 및 초기화
    int added = 0;      // 추가해야 하는 블록의 총 개수
    int removed = 0;    // 제거해야 하는 블록의 총 개수

    for (int i = 0; i < n; i++) {   // 땅에 있는 n x m개의 칸에 대해
        for (int j = 0; j < m; j++) {
            int gap = abs(height - blocks[i][j]);   // 목표 높이 height와 해당 칸의 높이 사이의 차이 계산

            if (blocks[i][j] > height) {    // 목표 높이보다 높은 칸인 경우               
                removed += gap; // gap개의 블록 제거
            }
            else if (blocks[i][j] < height) {   // 목표 높이보다 낮은 칸인 경우                
                added += gap;   // gap개의 블록 추가
            }
        }
    }

    // 전체 비용 계산
    cost = 2 * removed + added;

    // 블록 개수가 부족하다면 모든 땅의 높이를 height로 만드는 것이 불가능
    return (added > (b + removed)) ? INF : cost;
}

// 모든 땅의 높이를 같게 만드는 최소 비용과 그 때의 땅의 높이
pii makeGroundEven(int n, int m, int b, vector<vector<int>>& ground) {  // 땅의 세로, 가로 길이와 블록 개수, 땅의 높이 저장된 벡터 전달
    int minCost = INF;  // 충분히 큰 값으로 최소 비용 초기화
    int height = 0; // 땅의 높이 저장할 변수 0으로 초기화

    // 모든 높이를 다 만들어보고 최소 비용 찾기
    for (int i = 0; i < MAX_HEIGHT; i++) {  // 가능한 모든 땅의 높이에 대해서 비용 계산
        int cost = calcCost(i, n, m, b, ground);    // 땅의 높이를 0부터 256까지 1씩 늘려가면서 calcCost 함수를 이용해 비용 계산
        if (cost <= minCost) {  // 땅의 높이가 i일 때 비용이 minCost보다 작다면
            minCost = cost; // 그 비용을 최소값으로 변경
            height = i; // 그때의 높이를 height에 저장
        }
    }

    return { minCost, height }; // 최소 비용과 그때의 높이가 저장된 pair 리턴
}

/*
 * 블록 높이의 최댓값이 256밖에 되지 않으므로
 * 모든 칸을 높이 n(0~256)으로 만드는 모든 경우를 시도해보고
 * 그 중에서 비용이 최소가 될 때를 찾는다.
 */

int main() {
    int n, m, b;    // 땅의 세로, 가로 길이와 블록 개수 저장할 변수 선언

    // 입력
    cin >> n >> m >> b; // n, m, b 입력받기
    vector<vector<int>> ground(n, vector<int>(m));  // n x m 크기의 2차원 벡터 ground 선언
    for (int i = 0; i < n; i++) {   // n x m번 반복
        for (int j = 0; j < m; j++) {
            cin >> ground[i][j];    // 땅의 높이 입력받아서 ground에 저장
        }
    }

    // 연산
    pii answer = makeGroundEven(n, m, b, ground); // makeGroundEven 함수에 땅의 세로, 가로 길이와 블록 개수, ground (땅의 높이 저장) 전달하고 리턴받은 결과를 answer에 저장                                                 

    // 출력
    cout << answer.first << " " << answer.second << "\n";   // 땅을 고르는 데 걸리는 최소 시간과 땅의 높이 출력

    return 0;   // main 함수 종료
}