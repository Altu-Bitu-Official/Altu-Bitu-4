#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

const int MAX_HEIGHT = 257;
const int INF = 987'654'321;

//땅을 동일한 높이로 고르는 데 걸리는 시간 계산하는 함수
int calcCost(int height, int n, int m, int b, vector<vector<int>>& blocks) {
    int cost = 0;
    int added = 0;  
    int removed = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int gap = abs(height - blocks[i][j]);
            
            //블록의 높이가 목표 높이보다 높으면 블록 제거
            if (blocks[i][j] > height) {
                removed += gap;
            }
            //블록의 높이가 목표 높이보다 낮으면 블록 추가
            else if (blocks[i][j] < height) {
                added += gap;
            }
        }
    }
    
    // 전체 시간 계산
    cost = 2 * removed + added;
    
    // 블록 개수가 부족하다면? -> 불가능한 경우
    return (added > (b + removed)) ? INF : cost;
}

// 모든 땅의 높이를 같게 만드는 최소 비용과 그 때의 땅의 높이
pii makeGroundEven(int n, int m, int b, vector<vector<int>>& ground) {
    int minCost = INF;
    int height = 0;
    
    // 모든 높이를 다 시도해보기
    for (int i = 0; i < MAX_HEIGHT; i++) {
        //시간을 계산하는 함수 실행
        int cost = calcCost(i, n, m, b, ground);
        //해당 시간이 더 작으면 minCost, height 바꾸기
        if (cost <= minCost) {
            minCost = cost;
            height = i;
        }
    }
    
    return {minCost, height};
}

int main() {
    int n, m, b;    //n: 입력 줄 개수, m:땅의 높이, b:인벤토리 내 블록
    
    //입력 받기
    cin >> n >> m >> b;
    //집터 저장할 벡터
    vector<vector<int>> ground(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> ground[i][j];
        }
    }

    //연산
    pii answer = makeGroundEven(n, m, b, ground);

    //출력
    cout << answer.first << " " << answer.second << "\n";

    return 0;
}