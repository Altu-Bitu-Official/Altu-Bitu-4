#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

//단반향 도로이므로 가는길과 돌아오는 길을 구분함을 주의 
//따라서 걸리는 시간을 배열로 만들어 가장 큰 값을 출력

int inf= 987654321;
using namespace std;

int n, m, x;
int dist[1010], res[1010];
vector<pair<int, int>> v[1010];//간선의 정보 저장

void Input(){
    cin >> n >> m >> x; //초기 입력값

    for (int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back(make_pair(b, c));//간선의 정보를 push
    }
}

void Dijkstra(int start){

    priority_queue<pair<int, int>> PQ;
    dist[start] = 0;
    PQ.push(make_pair(0, start));

    while (PQ.empty() == 0){

        int cost = -PQ.top().first;
        int cur = PQ.top().second;
        PQ.pop(); //coast와 cur에 저장한 다음 pop

        if (cost > dist[cur]) {//탐색하려는 값이 기존 값 보다 크다면 탐색할 필요x->구하지 않고 넘어감
            continue;
        }

        for (int i = 0; i < v[cur].size(); i++){
            int next = v[cur][i].first;
            int nCost = v[cur][i].second;

            if (dist[next] > cost + nCost){//만약 더 크다면->최소값으로 갱신->pq에 저장
                dist[next] = cost + nCost;
                PQ.push(make_pair(-dist[next], next));
            }
        }
    }

}

void Solution() {

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[j] = inf;
        }
        Dijkstra(i);
        res[i] = dist[x];//i에서 x까지 가는데 걸리는 시간을 구함->res[i]에 저장
    }
    for (int j = 1; j <= n; j++) {
        dist[j] = inf;//배열 다시 초기화
    }

    Dijkstra(x);// x에서 i까지 가는데 걸리는 시간
    for (int i = 1; i <= n; i++) {
        res[i] = res[i] + dist[i];//총 소요 시간=가는데 걸리는 시간+오는데 걸리는 시간 (도로가 단방향이므로)
    }

    sort(res + 1, res + n + 1);// 가장 큰 값을 찾기 위해 정렬
   int  answer = res[n];//가장 큰 값
    
    cout << answer;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solution();

    return 0;
}

