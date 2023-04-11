#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> hacking(int n, int start, vector<vector<int>>& trust) {
	vector<int> hacked(n + 1, false);

	//처음 시작 컴퓨터 초기화
	queue<int> q;
	q.push(start);
	hacked[start] = true;

	while (!q.empty()) {
		int c = q.front();
		q.pop();

		//연결된 컴퓨터 다 해킹
		for (int i = 0; i < trust[c].size(); i++) {
			//아직 해킹되지 않은 컴퓨터라면 해킹
			if (!hacked[trust[c][i]]) {
				q.push(trust[c][i]);
				hacked[trust[c][i]] = true;
			}
		}
	}

	vector<int> result; //해킹한 컴퓨터 번호
	for (int i = 1; i < n + 1; i++) {
		if (hacked[i]) {
			result.push_back(i);
		}
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n, m;
	cin >> n >> m;

	int a, b;
	vector<vector<int>> trust(n + 1, vector<int>());
	while (m--) {
		cin >> a >> b;
		trust[b].push_back(a);
	}

	//연산
	int max_cnt = 0;
	vector<int> computer(n + 1);
	for (int i = 1; i < n + 1; i++) {
		vector<int> result = hacking(n, i, trust);

		//컴퓨터 번호와 해킹 가능한 컴퓨터 개수 저장
		computer[i] = result.size();

		//가장 많은 컴퓨터 해킹 개수 저장
		if (result.size() > max_cnt) {
			max_cnt = result.size();
		}
	}

	//출력
	for (int i = 1; i < n + 1; i++) {
		if (computer[i] == max_cnt) {
			cout << i << " ";
		}
	}

	return 0;
}