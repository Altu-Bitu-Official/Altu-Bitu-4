#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct cmp {
    bool operator()(vector<int>& a, vector<int>& b) {
        return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs) {
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq; //min heap으로 구성
    int answer = 0;
    int current = 0; //현재 시간
    int cnt = 1; //작업 경과 시간

    vector<int> job; //기준 작업

    sort(jobs.begin(), jobs.end()); // 요청 시간이 작은 순으로 정렬 

    //요청 시간이 가장 작은 작업을 기준 작업으로 설정
    pq.push(jobs[0]);
    current = jobs[0][0];


    while (!pq.empty()) { // pq가 비지 않을 때까지 반복
        //기준 job 상대로 소요시간 계산 후 현재 시간 변경
        job = pq.top();
        pq.pop();

        answer += ((current - job[0]) + job[1]);
        current += job[1];

        //현재 시간보다 요청 시간이 작았던 작업들 모두 pq에 push
        for (; cnt < jobs.size() && jobs[cnt][0] <= current; cnt++) {
            pq.push(jobs[cnt]);
        }

        //만약 현재 시간보다 훨씬 떨어진 시간에 작업이 있다면 기준 작업 바꿈
        if (pq.empty() && cnt < jobs.size()) {
            current = jobs[cnt][0];
            pq.push(jobs[cnt++]);
        }
    }

    answer /= jobs.size();

    return answer;
}