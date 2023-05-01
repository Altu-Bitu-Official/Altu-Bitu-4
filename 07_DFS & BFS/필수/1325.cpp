#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(int s, int n, vector<vector<int>> &graph) { //s 컴퓨터가 해킹할 수 있는 컴퓨터 탐색
    int cnt = 1; // s가 해킹할 수 있는 컴퓨터 수
    vector<bool> hacked (n+1, false); // 컴퓨터 해킹 여부 저장
    queue<int> q;   //해킹되면 넣을 queue

    hacked[s] = true;   //시작 컴퓨터 해킹
    q.push(s);  //시작 컴퓨터 추가

    while(!q.empty()) { //큐가 빌 때까지 반복
        int node = q.front();   //큐의 맨 위를 노드로 설정
        q.pop();    //큐에서 노드 빼기

        for(int i = 0; i < graph[node].size(); i++) { // node 컴퓨터가 해킹할 수 있는 컴퓨터 탐색
            int next_node = graph[node][i]; //신뢰관계에 있는 컴퓨터를 다음 노드로 설정
            if(!hacked[next_node]) { // 아직 해킹되지 않은 컴퓨터 발견
                cnt++;  //해킹할 수 있는 컴퓨터 수 +1
                hacked[next_node] = true;   //해킹 여부 처리
                q.push(next_node);  //큐에 해당 컴퓨터 추가
            }
        }
    }
    return cnt; // s가 해킹할 수 있는 컴퓨터 수 반환
}

vector<int> hack(int n, vector<vector<int>> &graph) {
    int max_cnt = 0; //해킹 가능한 컴퓨터 수의 최대
    vector<int> result;    //컴퓨터 번호 저장하는 vector

    for(int i = 1; i <= n; i++) {   //i 는 최초로 해킹한 컴퓨터
        int tmp = bfs(i, n, graph); //bfs로 해킹 가능한 컴퓨터 수 받기

        if(tmp > max_cnt) {     //i번째 컴퓨터가 해킹한 수가 더 많으면
            max_cnt = tmp;  //최대값 갱신
            result = {i};   //i를 result vector에 저장
        }
        else if(tmp == max_cnt) {   //해킹한 수가 같으면
            result.push_back(i);    //컴퓨터 번호 push
        }
    }
    //한 번에 가장 많은 컴퓨터를 해킹할 수 있는 컴퓨터의 번호 반환
    return result;
}

int main() {
    int n, m, a, b;  //컴퓨터 개수, m개의 줄, 컴퓨터a, 컴퓨터b
    vector<vector<int>> graph;  //탐색할 그래프 (컴퓨터의 신뢰하는 관계 저장)

    // 입력
    cin >> n >> m;
    graph.assign(n+1, vector<int> (0)); //초기화
    while(m--) {    //m개 입력 받기
        cin >> a >> b;  //신뢰 관계 입력
        graph[b].push_back(a);  //b는 a를 감염시킬 수 있다
    }

    // 연산
    vector<int> result = hack(n, graph);
    //결과 개수만큼 for문
    for(int i = 0; i < result.size(); i++) {
        //출력
        cout << result[i] << ' ';
    }
    return 0;
}