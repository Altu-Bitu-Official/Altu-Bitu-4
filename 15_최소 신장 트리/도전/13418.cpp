#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

typedef tuple<int, int, int> tp;
vector<int> parent;

// Find 연산
int findParent(int x) {
    if (parent[x] < 0) {
        return x;
    }
    return parent[x] = findParent(parent[x]);
}

// union 연산
bool unionNodes(int x, int y) {
    int px = findParent(x);
    int py = findParent(y);

    if (px == py) {
        return false;
    }

    if (parent[px] < parent[py]) {
        parent[px] += parent[py];
        parent[py] = px;
    }
    else {
        parent[py] += parent[px];
        parent[px] = py;
    }
    return true;
}

int kruskal(int n, vector<tp>& edge) {
    int sum = 0;
    for (auto [w, n1, n2] : edge) {
        if (!unionNodes(n1, n2)) {
            continue;
        }
        sum += w;
    }
    return sum;
}

// 입구는 항상 1번 도로와 연결
void entry(int n, int e1, int e2, vector<tp>& edge) {
    parent.assign(n + 1, -1);
    unionNodes(e1, e2);
}

/*
* 크루스칼 알고리즘을 이용하여 최악, 최선의 경로 구하기
* 최선: 간선의 weight의 합이 가장 작은 경우 -> 오름차순으로 정렬
* 최악: 간선의 weight의 합이 가장 큰 경우 -> 내림차순으로 정렬
* !주의! 입구(0)는 항상 1번 건문과 연결된 도로를 가짐(입력도 먼저 주어짐)
* !주의! 내리막과 오르막의 weight를 반대로 바꿔서 MST 적용 -> weight가 작을수록 피로도가 적음
*/

int main() {
    int n, m, e1, e2, ew, a, b, c;
    vector<tp> edge;
    // 입력
    cin >> n >> m;
    cin >> e1 >> e2 >> ew;
    ew = 1 - ew; // (오르막: 0, 내리막: 1) -> (내리막: 0, 오르막: 1)
    while (m--) {
        cin >> a >> b >> c;
        edge.push_back({ 1 - c, a, b }); 
    }
    // 연산 & 출력
    // 최솟값 (내리막(0)으로 먼저 가야 함)
    entry(n, e1, e2, edge);
    sort(edge.begin(), edge.end()); // 오름차순
    int min_stress = kruskal(n, edge) + ew;
    // 최댓값 (오르막(1)으로 먼저 가야 함)
    entry(n, e1, e2, edge);
    sort(edge.begin(), edge.end(), greater<>()); // 내림차순
    int max_stress = kruskal(n, edge) + ew;
    cout << max_stress * max_stress - min_stress * min_stress << '\n';
    return 0;
}