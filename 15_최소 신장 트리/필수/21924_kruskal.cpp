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

long long kruskal(int n, vector<tp>& edge) {
    int cnt = 0;
    long long sum = 0;
    for (auto [w, n1, n2] : edge) {
        if (!unionNodes(n1, n2)) {
            continue;
        }
        sum += w;
        cnt++;
        if (cnt == n - 1) {
            return sum;
        }
    }
    return -1; // 모든 건물을 연결할 수 없는 경우
}

/*
* 주의: 최소한의 도로를 건설하는 비용이 아닌 절약한 비용을 구해야 함
* 크루스칼 알고리즘을 이용하여 총 비용 구하기
*/

int main() {
	int n, m, a, b, c;
	long long total_price = 0;
    vector<tp> edge;
	// 입력
	cin >> n >> m;
    parent.assign(n + 1, -1);
	while (m--) {
		cin >> a >> b >> c;
        edge.push_back({ c, a, b });
		total_price += c;
	}
    sort(edge.begin(), edge.end());
	// 연산 & 출력
	long long result = kruskal(n, edge);
	if (result == -1) {
		cout << result << '\n';
	}
	else { // 절약한 비용 = 총 비용 - 최소한의 도로를 연결하는데 드는 비용
		cout << total_price - result << '\n';
	}
	return 0;
}