// 체육복

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
 * 각 학생들이 가지고 있는 체육복의 개수를 배열에 저장
 * 1번 학생부터 양 옆의 학생으로부터 대여가 가능한지 여부를 확인하여 빌려준다.
 * 최종적으로 체육복 개수가 1개 이상인 학생들의 인원을 센다.
 */
int solution(int n, vector<int> lost, vector<int>reverse){
    int cnt = 0;
    
    vector<int> student(n+1, 1); // 체육복 개수 정보 닫음
    
    //입력
    for (int i=0; i<reverse.size(); i++) // 여벌 체육복이 있는 학생
        student[reverse[i]]++;
    for (int i=0; i<lost.size(); i++) // 체육복을 잃어버린 학생
        student[lost[i]]--;
    
    // 체육복 대여 가능 확인
    for (int i=1; i<=n; i++){
        if (student[i]>0){ // 체육복이 있음
            continue;
        }
        if (student[i-1] == 2){ // 앞 번호 체육복 여분 있음
            student[i]++;
            student[i-1]--;
        }
        else if (student[i+1] == 2){ // 뒷 번호 체육복 여분 있음
            student[i]++;
            student[i+1]--;
        }
    }
    for (int i=1; i<=n; i++){ // 체육복 있는 학생 count
        cnt += (student[i]>0);
    }
    return cnt;
}

int main()
{
    vector<int> lost = {2,4};
    vector<int> reverse = {1,3,5};
    int n = 5;
    
    cout << solution(n, lost, reverse);
    
    return 0;
}