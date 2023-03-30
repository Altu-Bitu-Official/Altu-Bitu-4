#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii;//답안으로 쓸 pair

const int MAX_HEIGHT = 257;//땅 최대높이
const int INF = 987'654'321;//최대시간??


int calcCost(int height, int n, int m, int b, vector<vector<int>>& blocks) {// 모든 땅의 높이를 height로 만드는 비용 계산
    int cost = 0;//비용(시간)
    int added = 0;      // 추가해야 하는 블록의 총 개수
    int removed = 0;    // 제거해야 하는 블록의 총 개수

    for (int i = 0; i < n; i++) {//행
        for (int j = 0; j < m; j++) {//열
            int gap = abs(height - blocks[i][j]);//모든 높이 경우 수 센다했음. 높이(i)-블록의 값(==높이)

            if (blocks[i][j] > height) {// 목표 높이보다 높은 칸인 경우
                removed += gap;//, gap개의 블록 제거
            }
            else if (blocks[i][j] < height) {// 목표 높이보다 낮은 칸인 경우,
                added += gap; //gap개의 블록 추가
            }
        }
    }

    // 전체 비용 계산
    cost = 2 * removed + added;//더하는건 1초 제거하는건 2초니까 총 비용은 일케

    // 블록 개수가 부족하다면 모든 땅의 높이를 height로 만드는 것이 불가능
    return (added > (b + removed)) ? INF : cost;//INF: 초기값. 부족하면 INF뱉고 아니면 cost 계산되어나가고
}


pii makeGroundEven(int n, int m, int b, vector<vector<int>>& ground) {// 모든 땅의 높이를 같게 만드는 최소 비용과 그 때의 땅의 높이
    int minCost = INF;//최소비용 초기화
    int height = 0;//높이: 0초기화

    // 모든 높이를 다 만들어보고 최소 비용 찾기
    for (int i = 0; i < MAX_HEIGHT; i++) {//모든 높이로 돌려본다 
        int cost = calcCost(i, n, m, b, ground);//비용 계산
        if (cost <= minCost) {//작은 코스트로 업데이트
            minCost = cost;//minCost업데이트(작은거로교체)
            height = i;//높이에 인덱스값 넣는다(모든 높이 다 만들어보는 코드니까)
        }
    }

    return { minCost, height };//최소비용과(시간) 높이 반환==(pair)
}

/**
 * 블록 높이의 최댓값이 256밖에 되지 않으므로
 * 모든 칸을 높이 n(0~256)으로 만드는 모든 경우를 시도해보고
 * 그 중에서 비용이 최소가 될 때를 찾는다.
 *
 * 모든 칸을 높이 n으로 만드는
 */

int main() {
    int n, m, b;//세로, 가로, 인벤에 들은 블록 갯수
    cin >> n >> m >> b;// 입력

    vector<vector<int>> ground(n, vector<int>(m));//2차 배열
    for (int i = 0; i < n; i++) {//행
        for (int j = 0; j < m; j++) {//열
            cin >> ground[i][j];// 땅 높이 입력받기
        }
    }

    // 연산
    pii answer = makeGroundEven(n, m, b, ground);//답으로 시간, 가장 높은 블록 높이 출력해야하니까 pair

    // 출력
    cout << answer.first << " " << answer.second << "\n";//답안출력

    return 0;
}