// // 1260번

// #include <iostream>
// #include <vector> //그래프구현
// #include <stack>  // dfs
// #include <queue>  // bfs

// using namespace std;

// vector<int> dfs(int n, int v, vector<vector<bool>> &adj_matrix)
// {
//     vector<int> result;                 // 탐색 결과 저장
//     vector<bool> visited(n + 1, false); // 방문 여부 저장
//     stack<int> s;

//     // 시작정점
//     visited[v] = true; // 시작정점을 방문처리
//     s.push(v);
//     result.push_back(v); // 탐색결과에도push

//     while (!s.empty())
//     {
//         int node = s.top(); // 현재 노드
//         bool find = false;
//         // 현재 노드와 연결된 정점 탐색
//         for (int i = 1; i <= n; i++)
//         {
//             if (adj_matrix[node][i] && !visited[i] {
//                     visited[i] = true;
//                     result.push_back(i);
//                     s.push(i);
//                     find = true;
//                     break; // 인접한 정점을 찾으면 break
//                 })
//         }
//         if (!find)
//         {            // 인접한 정점을 찾지 못한 경우
//             s.pop(); // 갈림길로 돌아간다.
//         }
//     }

//     return result;
// }

// vector<int> bfs(int n, int v, vector<vector<bool>> &adj_matrix)
// {
//     vector<int> result;
//     vector<bool> visited(n + 1, false);
//     queue<int> q;

//     visited[v] = true;
//     result.push_back(v);
//     q.push(v);

//     // 시작정점
//     while (!q.empty())
//     {
//         int node = q.front();
//         q.pop();
//         for (int i = 1; i <= n; i++)
//         {
//             if (adj_matrix[node][i] && !visited[i])
//             {
//                 visited[i] = true;
//                 q.push(i);
//                 result.push_back(i);
//             }
//         }
//     }
// }
// int main()
// {
//     int n, m, v; // ㅈ어점개수, 간선개수, 시작 정점
//     int n1, n2;  // 간선이 연결하는 두 정점의 번호
//     // 인접행렬
//     vector<vector<bool>> adj_matrix;

//     cin >> n >> m >> v;
//     adj_matrix.assign(n + 1, vector<bool>(n + 1, false)); // 정점이 1부터 시작하니 1씩 더하기

//     while (n--)
//     {
//         cin >> n1 >> n2;
//         adj_matrix[n1][n2] = true;
//         adj_matrix[n2][n1] = true; // 양방향 처리  - 간선이 존재한다
//     }
//     vector<int> dfs_result = dfs(n, v, adj_matrix);
//     vector<int> bfs_result = bfs(n, v, adj_matrix);

//     for (int i = 0; i < dfs_result.size(); i++)
//     {
//         cout << dfs.result << endl;
//     }
//     for (int i = 0; i < bfs_result.size(); i++)
//     {
//         cout << bfs.result[i] << endl;
//     }
//     return 0;
// }