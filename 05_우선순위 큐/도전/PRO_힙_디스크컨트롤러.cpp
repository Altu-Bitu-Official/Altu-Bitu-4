#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//소요시간으로 sort
struct sortMinTime {
	bool operator()(vector<int> a, vector<int> b) {
		return a[1] > b[1];
	}
};

int solution(vector<vector<int>> jobs) { //요청시간, 소요시간
	int answer = 0;
	int job_cnt = jobs.size();
	int curt_time = 0; //현재 시간
	int total_time = 0; //전체 실행 시간
	int next_job = 0; //다음 task의 인덱스

	//소요시간이 작은 task가 top이 되는 우선순위 큐
	priority_queue<vector<int>, vector<vector<int>>, sortMinTime> pq;

	//요청시간으로 sort
	sort(jobs.begin(), jobs.end());

	//job이나 pq가 끝날때까지 실행
	while (next_job < job_cnt || !pq.empty()) {
		//1. 현재 요청된 task가 없다면, 요청시간이 가장 빠른 task 선택
		if (pq.empty()) {
			curt_time = jobs[next_job][0]; //현재시간을 가장 빠른 task의 요청시간으로 바꿈
			pq.push(jobs[next_job++]);
		}

		//2. 요청된 task가 여러개인 경우, 소요시간이 가장 빠른 task 선택
		vector<int> curt_job = pq.top();
		pq.pop();

		total_time += ((curt_time - curt_job[0]) + curt_job[1]);
		curt_time += curt_job[1];

		//현재시간 전에 요청된 task가 있다면 pq에 삽입
		while (next_job < job_cnt && jobs[next_job][0] <= curt_time) {
			pq.push(jobs[next_job++]);
		}

	}

	answer = int(total_time / job_cnt);
	return answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n = 3;

	vector<vector<int>> jobs(3, vector<int>(2));
	for (int i = 0; i < 3; i++) {
		cin >> jobs[i][0] >> jobs[i][1];
	}

	cout << solution(jobs);

	return 0;
}