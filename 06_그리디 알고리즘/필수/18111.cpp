#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii; //답을 저장할 pair

const int MAX_HEIGHT = 257; //땅의 높이는 256보다 작거나 같은 자연수 또는 0
const int INF = 987'654'321; //최대 시간으로 쓸(비용 초기화시킬) int

//땅을 동일한 높이로 고르는 데 걸리는 시간 계산하는 함수
int calcCost(int height, int n, int m, int b, vector<vector<int>>& blocks) {
    int cost = 0;   //비용
    int added = 0;     //추가한 블록 개수
    int removed = 0;    //제거한 블록 개수
    
    //집터 고르기
    for (int i = 0; i < n; i++) {   //2차원 배열 앞부분 (세로)
        for (int j = 0; j < m; j++) {// 2차원 배열 뒷부분 (가로)
            int gap = abs(height - blocks[i][j]);   //높이 - 해당 집터 높이 차이 
            
            if (blocks[i][j] > height) { //블록의 높이가 목표 높이보다 높으면 
                removed += gap;  //차이만큼 제거한 블록 개수 ++
            }
            
            else if (blocks[i][j] < height) { //블록의 높이가 목표 높이보다 낮으면
                added += gap; //차이만큼 추가한 블록 개수 ++
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
    int minCost = INF; //최소 시간을 최대 INF로 설정
    int height = 0; //땅 높이
    
    // 모든 높이를 다 시도해보기
    for (int i = 0; i < MAX_HEIGHT; i++) {
        //시간을 계산하는 함수 실행
        int cost = calcCost(i, n, m, b, ground);
        
        if (cost <= minCost) { //해당 시간이 더 작으면 
            minCost = cost; //최소 시간 바꾸기
            height = i; // 높이 변경
        }
    }
    
    return {minCost, height};   //최소 시간과 높이 return
}

int main() {
    int n, m, b;    //n: 입력 줄 개수, m:땅의 높이, b:인벤토리 내 블록
    
    cin >> n >> m >> b; //입력 받기
    vector<vector<int>> ground(n, vector<int>(m)); //집터 저장할 벡터
    for (int i = 0; i < n; i++) {  //2차원 배열 앞부분 (세로)
        for (int j = 0; j < m; j++) {// 2차원 배열 뒷부분 (가로)
            cin >> ground[i][j];    //땅 높이 입력 받기
        }
    }

    //연산
    pii answer = makeGroundEven(n, m, b, ground);

    //출력
    cout << answer.first << " " << answer.second << "\n";
    
    //종료
    return 0;
}