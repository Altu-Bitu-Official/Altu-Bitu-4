#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

const int NOT_BELIEVE = -1;

vector<int> bfs(int n, vector<vector<int>> &adj_list, vector<int> &spreader) {
    vector<int> result(n+1, NOT_BELIEVE); // 루머 믿기 시작한 시간
    vector<int> adj_believer_cnt(n+1, 0); // 루머를 믿는 주변인의 수
    queue<int> q;

    for(int i = 0; i < spreader.size(); i++) { // 루머 유포자 세팅
        int p = spreader[i]; // 루머 유포자 p
        result[p] = 0; // (== 루머 유포자는 처음부터 루머를 믿고 있기 때문에 0초 세팅)
        q.push(p);
    }

    while(!q.empty()) {
        int node = q.front(); // 루머를 믿는 node
        int w = result[node]; // node가 루머를 믿기 시작한 시간
        q.pop();

        for(int i = 0; i < adj_list[node].size(); i++) {
            /*
             * node가 주변인 next_node에게 루머를 유포하고자 한다.
             * node가 루머를 믿고 있으므로 루머를 믿는 next_node의 주변인의 수가 증가한다.
            */
            int next_node = adj_list[node][i];
            adj_believer_cnt[next_node]++; // (== next_node의 주변인 node가 루머를 믿는다)

            /*
             * [next_node가 루머를 믿기 시작하는 경우]
             * 1. 아직 루머를 믿고 있지 않으며
             * 2. next_node의 주변인의 절반 이상이 루머를 믿고 있다.
            */
            if(result[next_node] == NOT_BELIEVE && adj_believer_cnt[next_node] >= ceil((float) adj_list[next_node].size() / 2)) {
                result[next_node] = w+1;
                q.push(next_node);
            }
        }
    }
    return result;
}

/*
 * [루머 유포하기]
 * 전제조건 : "주변인의 절반 이상이 루머를 믿을 때 본인도 루머를 믿는다."
 * -> 루머를 믿는 주변인의 수를 계산해야 한다.
*/

int main() {
    int n, m, p;
    vector<vector<int>> adj_list;
    vector<int> spreader; // 루머 유포자 번호 저장

    // 입력
    cin >> n;
    adj_list.assign(n+1, vector<int> (0));
    for(int i = 1; i <= n; i++) { // i사람 주변인 입력
        while(true) {
            cin >> p;
            if(p == 0) {
                break;
            }
            adj_list[i].push_back(p);
        }
    }
    cin >> m;
    spreader.assign(m, 0);
    for(int i = 0; i < m; i++) {
        cin >> spreader[i];
    }

    // 연산 & 출력
    vector<int> result = bfs(n, adj_list, spreader);
    for(int i = 1; i <= n; i++) {
        cout << result[i] << ' ';
    }
    return 0;
}