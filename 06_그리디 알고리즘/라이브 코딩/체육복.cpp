#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    vector<int> students(n+1, 1);

    for(int i=0; i<lost.size(); i++) {
        students[lost[i]]--;
    }
    for(int i=0; i<reserve.size(); i++) {
        students[reserve[i]]++;
    }

    for(int i=1; i<=n; i++) {
        //체육복 잃어버린 애면
        if(!students[i]) {
            //앞에서부터 체육복 빌려줄 수 있는지 확인하고
            if(students[i-1]==2) {
                //빌려줄 수 있으면 체육복 개수 조정
                students[i]=students[i-1]=1;
            } else if(students[i+1]==2) {
                students[i]=students[i+1]=1;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        //체육복 있는 학생 수 세기
        if (students[i] > 0) {
            answer++;
        }
    }

    return answer;
}