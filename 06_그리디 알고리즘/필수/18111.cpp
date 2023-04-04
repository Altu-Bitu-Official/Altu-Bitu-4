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
            int gap = abs(height - blocks[i][j]); //height와 (i,j)에서의 블록 높이의 차

            if (blocks[i][j] > height) { //블록의 높이가 더 높다면
                // 목표 높이보다 높은 칸인 경우, gap개의 블록 제거
                removed += gap; //그 차이(gap)만큼 제거
            }
            else if (blocks[i][j] < height) {//블록의 높이가 더 낮다면
                // 목표 높이보다 낮은 칸인 경우, gap개의 블록 추가
                added += gap; //그 차이(gap)만큼 추가
            }
        }
    }

    // 전체 비용 계산
    cost = 2 * removed + added; //제거해야하는 경우는 2초 , 추가해야하는 경우는 1초

    // 블록 개수가 부족하다면 모든 땅의 높이를 height로 만드는 것이 불가능
    return (added > (b + removed)) ? INF : cost; //인벤토리에 저장되어있던 블록갯수 + 제거한 블록갯수 보다 추가해야하는 블록의 갯수가 클 경우 INF 반환 아닐 경우 계산한 비용 반환
}

// 모든 땅의 높이를 같게 만드는 최소 비용과 그 때의 땅의 높이
pii makeGroundEven(int n, int m, int b, vector<vector<int>>& ground) {
    int minCost = INF; //최소 비용 최대 (INF)로 초기화 해두기
    int height = 0; //맞출 높이

    // 모든 높이를 다 만들어보고 최소 비용 찾기
    for (int i = 0; i < MAX_HEIGHT; i++) { //i는 맞출 높이 0~MAX_HEIGHT-1
        int cost = calcCost(i, n, m, b, ground);
        if (cost <= minCost) { //새로 계산한 비용이 이전에 계산한 비용(minCost)보다 작을 경우
            minCost = cost; //minCost 갱신
            height = i; //맞출 높이 i로 갱신
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
    int n, m, b; //가로 세로 인벤토리에 있는 블록 갯수

    // 입력
    cin >> n >> m >> b;
    vector<vector<int>> ground(n, vector<int>(m)); // 땅의 높이 저장할 벡터
    for (int i = 0; i < n; i++) { //n개의 줄에
        for (int j = 0; j < m; j++) {//m개의 땅의 높이 입력받아서 저장
            cin >> ground[i][j];
        }
    }

    // 연산
    pii answer = makeGroundEven(n, m, b, ground); // makeGroundEvent함수로 얻은 값 저장

    // 출력
    cout << answer.first << " " << answer.second << "\n"; //시간, 땅의 높이 순서대로 출력

    return 0;
}