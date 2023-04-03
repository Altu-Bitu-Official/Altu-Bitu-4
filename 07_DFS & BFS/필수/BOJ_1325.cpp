#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int cnt;
vector<bool> visited_dfs;   //방문한 노드 저장

//재귀로 한 컴퓨터가 들어왔을 때, 그 컴퓨터와 연결된 컴퓨터를 dfs로 모두 탐색하는 함수 
void dfs(vector<vector<int>>& input, int n) {
    visited_dfs[n] = true;

    for (int i = 0; i < input[n].size(); i++) {
        int next_node = input[n][i];    //인접 리스트에서 연결된 노드를 다음 노드로 지정
        if (!visited_dfs[next_node]) {  //다음 노드를 방문한 적이 없을 경우
            cnt++;  //해킹 가능한 컴퓨터 수 증가
            dfs(input, next_node);  // 다음 노드로 dfs 호출
        }
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<vector<int>> input;  //컴퓨터 간 신뢰관계를 저장하는 인접 리스트
    vector<int> result;
    int n, m, max_cnt = 0;

    //입력
    cin >> n >> m;
    input.assign(n+1, vector<int> (0));
    visited_dfs.assign(n+1, false);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        input[b].push_back(a);  //a가 b를 신뢰하면 b를 통해 a 감염이 가능 -> 거꾸로 넣어줌.
    }

    for (int i = 1; i <= n; i++) {
        cnt = 0;
        dfs(input, i);  //카운트 구함
        if (cnt >= max_cnt) {   
            if (cnt != max_cnt) {   //최대 카운트와 카운트가 다를 때
                max_cnt = cnt;
                if (!result.empty()) {
                    result.clear();    //비울 수 있으면 결과 벡터 비워주기
                }
            }
            result.push_back(i);
        }
    }

    //출력
    for (int n : result) {
        cout << n << ' ';
    }

}