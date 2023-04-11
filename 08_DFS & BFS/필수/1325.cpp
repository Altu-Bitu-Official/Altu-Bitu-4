#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	int n, m;//노드의 개수, 관계의 개수
	cin >> n >> m;
	int n1, n2;
	int largest = 0;
	vector<vector<int>> v(100001);
	
	while (m--) {
		cin >> n1 >> n2;
		v[n2].push_back(n1);//n2의 입장에서 해킹될 수 있는 곳을 저장한다.
	}
	vector<pair<int, int>> answer;
	for (int i = 0; i < n; i++) {//모든 노드에 대하여
		bool vstd[100001] = { false, };//이미 방문한 노드를 표시
		int count = 0;
		queue<int> q;
		q.push(i+1);//컴퓨터 번호로 바꿔서 저장
		while (!q.empty()) {
			int w = q.front();
			vstd[w] = true;
			q.pop();

			for (int k = 0; k < v[w].size(); k++) {
				int tmp = v[w][k];
				if (vstd[tmp] != true) {
					q.push(tmp);
					vstd[tmp] = true;
					count++;
				}
			}
		}
		if (largest < count) {
			largest = count;
		}
		
		answer.push_back(make_pair(i+1, count));//ssinee.tistory.com/entry/%EB%B0%B1%EC%A4%80-1325%EB%B2%88-%ED%9A%A8%EC%9C%A8%EC%A0%81%EC%9D%B8-%ED%95%B4%ED%82%B9C 에서 컴퓨터번호와 접근가능한 pc수를 바로 pair로 저장하는 방법을 참고하였습니다.
	}
	sort(answer.begin(), answer.end());//컴퓨터 오름차순으로 정렬
	for (int i = 0; i < n; i++) {
		if (answer[i].second == largest) {
			cout << answer[i].first << " ";
		}
	}
	return 0;
}