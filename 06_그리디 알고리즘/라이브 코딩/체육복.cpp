#include <iostream>
#include <string>
#include <vector>

using namespace std;
/*
 * 각 학생들이 가지고 있는 체육복의 개수를 배열에 저장
 * 1번 학생부터 양 옆의 학생으로부터 대여가 가능한지 여부를 확인하여 빌려준다.
 * 최종적으로 체육복 개수가 1개 이상인 학생들의 인원을 센다.
 */

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    vector<int> student(n + 1, 1); //체육복 개수 정보 담음

    //입력내용대로 초기화
    for (int i = 0; i < reserve.size(); i++) { //여벌 체육복이 있는 학생은 플러스
        student[reserve[i]]++;
    }
    for (int i = 0; i < lost.size(); i++) { //체육복을 잃어버린 학생은 마이너스
        student[lost[i]]--;
    }

    //1번부터 체육복 대여 가능 여부 체크
    for (int i = 1; i <= n; i++) { //1번 학생부터 체크하며 양옆으로 체육복을 빌릴 수 있는가 확인
        if (student[i] > 0) { //빌릴 필요가 없으면 넘어가기
            continue;
        }

        if (student[i - 1] == 2) { //앞 번호 학생에게 여벌 체육복이 있는 경우
            student[i - 1]--;
            student[i]++;
        }
        else if (student[i + 1] == 2) { //뒷 번호 학생에게 여벌 체육복이 있는 경우
            student[i] = student[i + 1] = 1;
        }
    }

    for (int i = 1; i <= n; i++) { //체육복을 입을 수 있는 학생 수 세기
        if (student[i] > 0) {
            answer++;
        }
    }

    return answer;
}

//프로그래머스 테스트용으로 실행 가능한 메인 함수
int main() {
    vector<int> lost = {2, 4};
    vector<int> reserve = {1, 3, 5};
    int n = 5;

    cout << solution(n, lost, reserve);

    return 0;
}
