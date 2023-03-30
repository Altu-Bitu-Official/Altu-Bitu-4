#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii; //별칭 지정 -> pair<int, int>가 너무 길기 때문. 최소 걸리는 시간과 그때의 index 값을 도출해야 되기 때문에 pair로 지정해주는 거임

const int MAX_HEIGHT = 257; //상수 선언해 주기
const int INF = 987'654'321;  // 상수 선언해 주기

// 모든 땅의 높이를 height로 만드는 비용 계산 
int calcCost(int height, int n, int m, int b, vector<vector<int>>& blocks) {
    int cost = 0;   //비용 계산
    int added = 0;      // 추가해야 하는 블록의 총 개수
    int removed = 0;    // 제거해야 하는 블록의 총 개수
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int gap = abs(height - blocks[i][j]); //차를 구해주기
            
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
        //i로 만드는 비용 계산, 업데이트 -> 모든 블럭의 높이가 i 이다.
        int cost = calcCost(i, n, m, b, ground); // 계산을 위해 함수로 다시 빼준다.
        if (cost <= minCost) { //같은 시간이 걸릴때 (즉, 최소 시간이 같을 경우), i가 더 큰 걸 답으로 해주는 연산
            minCost = cost;
            height = i;
        }
    }
    
    return {minCost, height}; //pair로 return 해주기
}

int main() {
    int n, m, b;
    
    // 입력
    cin >> n >> m >> b;
    vector<vector<int>> ground(n, vector<int>(m)); //각 칸의 초기 높이를 받아주는 벡터 생성
    for (int i = 0; i < n; i++) {      //한칸씩 받아준다
        for (int j = 0; j < m; j++) {
            cin >> ground[i][j];
        }
    }

    // 연산
    pii answer = makeGroundEven(n, m, b, ground); // 땅을 고르는 함수 설정 -> 필요한 값을 다 넘겨주기

    // 출력
    cout << answer.first << " " << answer.second << "\n";

    return 0;
}