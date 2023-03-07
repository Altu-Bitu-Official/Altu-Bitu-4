#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> days;
    int len = progresses.size(), cnt = 1, max;
    
    for (int i = 0; i < len; i++) {
        days.push_back((99-progresses[i])/speeds[i]+1);
    }
    
    max = days[0];
    
    for (int i = 0; i < len; i++) {
        if (i < len-1 && days[i+1] <= max) {
            cnt++;
        } else {
            max = days[i+1];
            answer.push_back(cnt);
            cnt = 1;
        }
        
    }
    return answer;
    
}