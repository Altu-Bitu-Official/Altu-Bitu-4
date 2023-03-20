#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

//완료 시간을 담은 큐
queue<int> completionTime(vector<int> progresses, vector<int> speeds) {
    queue<int> q; 

    for (int i = 0; i < progresses.size(); i++) {
        int time = ceil((100 - progresses[i]) / floor(speeds[i]));
        q.push(time);
    }

    return q;
}

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    queue<int> q = completionTime(progresses, speeds);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        int count = 1;
        while (!q.empty() && curr >= q.front()) {
            count++;
            q.pop();
        }
        answer.push_back(count);
    }

    return answer;
}

int main() {
	int t;
	cin >> t;

    vector<int> progresses(t);
    vector<int> speeds(t);

    for (int i = 0; i < t; i++) {
        cin >> progresses[i];
    }

    for (int i = 0; i < t; i++) {
        cin >> speeds[i];
    }

    vector<int> result = solution(progresses, speeds);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

	return 0;
}