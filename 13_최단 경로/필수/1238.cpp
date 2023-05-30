#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

//단반향 도로이므로 가는길과 돌아오는 길을 구분함을 주의 
//따라서 걸리는 시간을 배열로 만들어 가장 큰 값을 출력

int INF = 987654321;
using namespace std;

int N, M, X;
int Dist[1010], Res[1010];
vector<pair<int, int>> V[1010];//간선의 정보 저장

void Input(){
    cin >> N >> M >> X; //초기 입력값

    for (int i = 0; i < M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        V[a].push_back(make_pair(b, c));//간선의 정보를 push
    }
}

void Dijkstra(int Start){

    priority_queue<pair<int, int>> PQ;
    Dist[Start] = 0;
    PQ.push(make_pair(0, Start));

    while (PQ.empty() == 0){

        int Cost = -PQ.top().first;
        int Cur = PQ.top().second;
        PQ.pop(); //coast와 cur에 저장한 다음 pop

        for (int i = 0; i < V[Cur].size(); i++){
            int Next = V[Cur][i].first;
            int nCost = V[Cur][i].second;

            if (Dist[Next] > Cost + nCost){//만약 더 크다면->저장
                Dist[Next] = Cost + nCost;
                PQ.push(make_pair(-Dist[Next], Next));
            }
        }
    }

}

void Solution() {

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            Dist[j] = INF;
        }
        Dijkstra(i);
        Res[i] = Dist[X];
    }
    for (int j = 1; j <= N; j++) {
        Dist[j] = INF;
    }

    Dijkstra(X);
    for (int i = 1; i <= N; i++) {
        Res[i] = Res[i] + Dist[i];
    }

    sort(Res + 1, Res + N + 1);// 가장 큰 값을 찾기 위해 정렬
   int  Answer = Res[N];//가장 큰 값
    
    cout << Answer;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solution();

    return 0;
}

