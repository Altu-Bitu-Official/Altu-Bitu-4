#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

queue<int> completionTime(int n, vector<int> progresses, vector<int> speeds) { // 작업별 완료시간 반환
    queue<int> q; // 작업 완료시간

    for(int i = 0; i < n; i++) {
        int remain = 100 - progresses[i]; // 남은 작업량
        q.push(ceil((double) remain / speeds[i])); // 완료시간 계산
    }
    return q;
}

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    int n = progresses.size(); // 작업 개수
    queue<int> q = completionTime(n, progresses, speeds); // 작업 완료시간

    while(!q.empty()) {
        int curr_time = q.front(); // 현재 작업의 완료 시간
        q.pop();
        int cnt = 1; // 현재 작업과 함께 배포될 수 있는 작업 수

        // 현재 작업과 함께 배포할 수 있는 작업 세기
        // q.front() : 현재 작업보다 뒷순서인 작업의 완료 시간
        while(!q.empty() && q.front() <= curr_time) {
            q.pop();
            cnt++;
        }
        answer.push_back(cnt);
    }
    return answer;
}

/*
 * 배포 프로세스 : 작업 완료 후 배포
 * 1. 작업별 작업 완료 시간을 계산한다.
 * 2. 작업 순서대로 배포를 시작한다.
 *
 * HINT : 뒷 순서의 작업이 앞 순서보다 먼저 개발될 수는 있지만 '먼저 배포될 수는 없다'
 * -> 앞 순서의 작업이 먼저 배포되는 (== FIFO) 구조
*/

int main() {
    vector<int> progresses = {93, 30, 55};
    vector<int> speeds = {1, 30, 5};

    // 연산
    vector<int> answer = solution(progresses, speeds);

    // 출력
    for(int i = 0; i < answer.size(); i++) {
        cout << answer[i] << ' ';
    }
    return 0;
}