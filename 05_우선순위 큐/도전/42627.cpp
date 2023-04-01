#include <string>
#include <vector>
#include <queue>
// #include <iostream>

using namespace std;

struct cmp
{
    bool operator()(const vector<int> &a, const vector<int> &b)
    {
        return b[1] < a[1];
    }
};

int solution(vector<vector<int>> jobs)
{
    // 도착시각(first) 작은 순서대로 우선순위 큐 생성
    priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
    int n = jobs.size();
    for (int i = 0; i < n; i++)
    {
        pq.push(jobs[i]);
    }

    int t = 0;
    int total = 0;
    int end_t = 0;
    while (!pq.empty())
    {
        if (pq.top()[0] > t)
        {
            t++;
            continue;
        }

        // 현재시각 t보다 작은 first 가진 원소 모두 pop한 뒤 새로운 min heap으로 옮겨
        priority_queue<vector<int>, vector<vector<int>>, cmp> candidate;
        while (!pq.empty() && pq.top()[0] <= t)
        {
            candidate.push(pq.top());
            pq.pop();
        }

        // 제일 작은 job 꺼내
        int arr = candidate.top()[0];
        int req_t = candidate.top()[1];
        candidate.pop();

        // 총 걸린시간 업뎃 : 기다림 + 소요시간
        total += t - arr + req_t;
        // 현시각 업뎃
        t += req_t;

        // 남은 후보들 empty할때까지 원래 pq에 다시 넣어
        while (!candidate.empty())
        {
            pq.push(candidate.top());
            candidate.pop();
        }
    }

    int answer = total / n;
    return answer;
}

// int main()
// {
//     cout << solution({{0, 3}, {4, 4}, {5, 3}, {4, 1}});
// }