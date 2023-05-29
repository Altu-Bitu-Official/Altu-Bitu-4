// 타임머신
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
const int INF = 5e6;

struct Bus{
    int from;
    int to;
    int w;
};

vector<ll> bellmanFord(int start, int n, vector<Bus> &buses){
    vector<ll> dist(n+1, INF);
    
    // 시작 정점 초기화
    dist[start] = 0;
    // n-1회 실행
    for (int i = 1; i<=n-1; i++){
        for (auto [from, to, w] : buses){
            if (dist[from] != INF && dist[to] > dist[from] + w){
                dist[to] = dist[from] + w;
            }
        }
    }
    // 1회 실행
    for (auto [from, to, w] : buses){
        // n번 갱신이 일어나면 음의 사이클 발생 -> 무한이 갱신됨
        if (dist[from] != INF && dist[to] > dist[from] + w){
            return {-1};
        }
    }
    return dist;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m, a, b, c;
    cin >> n >> m;
    
    vector<Bus> buses(m);
    
    for (int i = 0; i < m; i++){
        cin >> a >> b >> c;
        buses[i] = {a,b,c};
    }
    
    vector<ll> dist = bellmanFord(1,n,buses);
    
    if (dist[0] == -1){ // 시간을 무한히 오래 전으로 되돌릴 수 있으면
        cout << "-1";
    }
    else{
        for (int i = 2; i<=n; i++){
            cout << (dist[i] == INF ? -1 : dist[i]) << '\n';
        }
    }
    
    return 0;
}