#include <string>
#include <vector>
#include <math.h>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    
    //큐에 남은 작업 진도 입력
    for(int i = 0; i < progresses.size(); i++){
        q.push(ceil(float(100-progresses[i])/speeds[i]));
    }
    
    //큐가 빌 때까지 (배포가 다 이루어질 때까지) 반복
    while(!q.empty()){
        int f = q.front();
        q.pop();
        int ans = 1;    //pop을 했으니 return할 값에 +1
        
        //오늘 배포할 기능이 몇 개인지 계산
        while(!q.empty() && q.front() <= f){    
            q.pop();
            ans++;
        }
        //다음 기능이 아직 완성되지 않았으면 멈추고 answer에 배포할 기능 개수 push
        answer.push_back(ans);
    }
    return answer;
    
}