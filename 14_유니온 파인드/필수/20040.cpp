#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

// Find 연산
int findParent(int node) {
	if (parent[node] < 0) {
		return node;
	}
	return parent[node] = findParent(parent[node]);
}

// Union 연산
bool unionInput(int x, int y) {
	int xp = findParent(x);
	int yp = findParent(y);

	if (xp == yp) { // 같은 집합에 속한 원소 -> 사이클 생성
		return false;
	}
	if (parent[xp] < parent[yp]) {
		parent[xp] += parent[yp];
		parent[yp] = xp;
	}
	else {
		parent[yp] += parent[xp];
		parent[xp] = yp;
	}
	return true;
}

/*
* 같은 집합에 있는 두 원소를 유니온하려는 시도 -> 사이클이 발생한 순간
* unionInput에서 boolean을 반환하여 사이클이 발생된 순간 확인
*/

int main()
{
	int n, m, p1, p2, cnt = 0;
	cin >> n >> m;
	// 입력
	parent.assign(n, -1);
	for (int i = 0; i < m; i++) {
		cin >> p1 >> p2;

		// 연산 & 출력
		if (!unionInput(p1, p2)) { // 사이클 생성
			cnt = i + 1; // i가 0부터 시작하므로 + 1
			break;
		}
	}
	cout << cnt << '\n'; // 사이클 생성 X
	return 0;
}