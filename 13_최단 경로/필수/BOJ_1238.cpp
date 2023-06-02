#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF=1e9+7;
int xton[1001];
vector<pair<int, int>> graph[2][1001];
vector<int> dist[2];
int n, m, x;

void dijkstra(int w){
    dist[w][x]=0;

    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push({0,x});

    while(!q.empty()){
        int di=q.top().first;
        int curr=q.top().second;
        q.pop();

        if(di>dist[w][curr]){
            continue;
        }
        for(int i=0;i<graph[w][curr].size();i++){
            int next=graph[w][curr][i].second;
            int next_d=di+graph[w][curr][i].first;
            if(next_d<dist[w][next]){
                dist[w][next]=next_d;
                q.push({next_d,next});
            }
        }
    }
}
int main(){
    
    cin>>n>>m>>x;

    fill_n(xton, 1001,INF);

    for(int i=0;i<m;i++){
        int s,e,t;//start, end, time
        cin>>s>>e>>t;
        graph[0][s].push_back({t,e});
        graph[1][e].push_back({t,s});
    }
    dist[0].resize(n+1, INF);
    dist[1].resize(n+1, INF);

    dijkstra(0);
    dijkstra(1);

    int answer=0;
    for(int j=1;j<=n;j++){
        answer=max(answer,dist[0][j]+dist[1][j]);
    }
    cout<<answer<<'\n';



}