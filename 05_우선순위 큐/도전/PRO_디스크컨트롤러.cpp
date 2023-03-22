//프로그래머스 제출 코드(main미포함)
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct cmp{
    bool operator()(vector<int> x1, vector<int> x2){
        return x1[1]>x2[1];//기존의 값이 더 크면 true를 리턴해 swap.
    }
};
int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue<vector<int>, vector<vector<int>>, cmp> min_h;//최소 힙 선언
    sort(jobs.begin(),jobs.end());//jobs 정렬    
    //최소 힙에 jobs 오름차순으로 넣기
    int time=0; int index=0;
    
    while(index<jobs.size()||!min_h.empty()){
        if(index<jobs.size()&&jobs[index][0]<=time){//요청시간이 현재 시간보다 앞서는지 확인
            min_h.push(jobs[index]);
            index++;
            continue;            
        }
        if(min_h.empty()==0){
            time+=min_h.top()[1];
            answer+=time-min_h.top()[0];
            min_h.pop();
        }
        else{
            time=jobs[index][0];
        }
    }
    return answer/jobs.size();
}
