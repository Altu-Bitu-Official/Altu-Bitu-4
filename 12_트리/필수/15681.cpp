#include <iostream>
#include <vector>
using namespace std;
int dfs(int r, vector<vector<int>> &v, vector<bool> &visited, vector<int> &cnt){
    visited[r] = true; //root에 방문 표시 
    int count = 1; //root 노드를를 count에 추가 
    
    for (int next : v[r]) {
        //범위 기반 for문: for(element_declaration : array)
		if (visited[next]){
            continue; //이미 방문한 경우 pass 
        }
		count += dfs(next, v, visited, cnt); //root의 자식 노드 탐색 
	}
	cnt[r] = count; //모든 정점을 root로 하는 서브트리에 속한 정점의 수가  
	                //cnt[r]에 저장됨 
	return count;
}

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    int n, r, q, v1, v2;
    //입력 
    cin >> n >> r >> q;
    vector<vector<int>> v(n+1, vector<int>(0));
    
    for(int i=0; i<n-1; i++){
        cin >> v1 >> v2;
        v[v1].push_back(v2);
        v[v2].push_back(v1);
    }
    
    //연산 
    vector<bool> visited(n+1, false); //방문 표시 
    vector<int> cnt(n + 1, 0); //정점의 수를 세는 벡터 cnt 
    
    cnt[r] = dfs(r, v, visited, cnt); 
    
    //출력 
    for(int i=0; i<q; i++){
        cin >> r;
        cout << cnt[r] << '\n';
    }

    return 0;
}