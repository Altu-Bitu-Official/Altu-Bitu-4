#include <iostream>
#include <algorithm>

using namespace std;

int color[1001][3];

int main() {
    int N;
    int cost[3];// 칠할 때의 비용을 저장할 배열

    //값을 저장할 배열 선언, 0번째 집은 존재x->0으로 저장
    color[0][0] = 0; //빨간색으로 칠할 때
    color[0][1] = 0; //초록색으로 칠할때
    color[0][2] = 0; //파란색으로 칠할 때

    cin >> N;

    for (int i = 1; i <= N; i++){

        cin >> cost[0] >> cost[1] >> cost[2];//비용 입력 받음

        color[i][0] = min(color[i - 1][1], color[i - 1][2]) + cost[0];
        //빨간색으로 칠할 때: 이전 집이 파랑or초록 중 최소값+ 빨간색으로 칠하는 비용
        color[i][1] = min(color[i - 1][0], color[i - 1][2]) + cost[1];
        //초록색으로 칠할 때: 이전 집이 빨강or 파랑 중 최소값+초록으로 칠하는 비용
        color[i][2] = min(color[i - 1][1], color[i - 1][0]) + cost[2];
        //파란색으로 칠할 때: 이전 집이 빨강or초록 중 최소값+ 파랑으로 칠하는 비용
    }
    cout << min(color[N][2], min(color[N][0], color[N][1]));//빨강, 파랑, 초록 중 가장 작은 값을 출력
}