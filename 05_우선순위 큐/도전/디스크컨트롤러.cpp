#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

// HINT : 현재 시각에서 요청된 task 중 소요시간이 가장 적은 task를 우선으로 실행해야 해요! 시간이 흘러감에 따라 수행돼야 하는 기능을 생각해보세요!

struct sortMinTime {
    bool operator()(vector<int> a, vector<int> b) {
        return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs) {// 요청시간, 소요시간
    int answer = 0;
    int curt_time = 0; // 현재 시간
    int total_time = 0; // 대기 시간 
    int next_request_job = 0; // 다음으로 요청되는 task 인덱스 번호
    int job_cnt = jobs.size();
    priority_queue<vector<int>, vector<vector<int>>, sortMinTime> pq; // 소요시간이 작은 순으로 정렬해주는 우선순위 큐


    sort(jobs.begin(), jobs.end()); // task를 요청 시간이 작은 순으로 정렬
    

    while (next_request_job < job_cnt || !pq.empty()) {

        // 현재 요청된 task는 없지만 task가 남아 있는 경우
        if (pq.empty()) {
            curt_time = jobs[next_request_job][0];
            pq.push(jobs[next_request_job++]);
        }

        // 현재 요청된 taks 중 소요시간이 가장 적은 task 수행 :
        vector<int> curt_job = pq.top();
        pq.pop();
        total_time += ((curt_time - curt_job[0]) + curt_job[1]);//(요청부터 실행까지 delay된 시간) + 요청부터 종료까지 total 시간 
        curt_time += curt_job[1];

        // 현재 시간까지 요청된 task를 큐에 push
        while (next_request_job < job_cnt && jobs[next_request_job][0] <= curt_time) {
            pq.push(jobs[next_request_job++]);
        }

    }
    answer = int(total_time / job_cnt);

    return answer;
}

/*
* 1. 현재 시각에서 요청된 task 중 소요시간이 가장 적은 task를 우선으로 실행해야 한다!
* 2. pq의 top 에 있는 task를 수행함에 따라 total_time과 curt_time을 변경하자!
* 3. curt_time에 따라 요청된 task는 pq에 삽입하고
*/
int main() {
    vector<vector<int>> jobs;
    int n;
    cout << "task수 입력 : ";
    cin >> n;
    cout << "\ntask 요청시간 소요시간 입력(빈칸으로 구분)\n";
    while (n--) {
        vector<int> time(2);
        cin >> time[0] >> time[1];
        jobs.push_back(time);
    }
    cout << solution(jobs);
    return 0;
}
