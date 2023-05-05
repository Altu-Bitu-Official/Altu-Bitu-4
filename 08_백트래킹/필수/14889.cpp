#include <iostream>
#include <vector>

using namespace std;
#define INT_MAX 2147483647

int n;
int ans = INT_MAX;
bool team[21];
vector<vector<int>> s;

void calculate(){       //스타트 팀의 능력치와 링크 팀의 능력치의 차이 구하기
    int start = 0;
    int link = 0;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            //스타트팀 능력치 더하기
            if(team[i] == 1 && team[j] == 1){
                start += s[i][j];
            }
            //링크 팀 능력치 더하기
            else if(team[i] == 0 && team[j] == 0){
                link += s[i][j];
            }
        }
    }
    //절댓값
    int gap = abs(start - link);
    //현재 차이가 이전 차이보다 더 작다면 답 교체
    ans = min(ans, gap);
}

void combination(int m, int count, int start){      //조합 계산
    if(count == m){
        //능력치 차이 계산
        calculate();
        return;
    }
    
    for(int i = start; i<=n; i++){
        //조합에서 뽑은 수에 해당하는 team[i] true로 바꾸기 -> start team
        team[i] = 1;
        combination(m, count+1, i+1);
        team[i] = 0;
    }
    return;
}

int main(){
    //입력
    cin >> n;
    s.assign(n+1, vector<int>(n+1, 0)); //초기화
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> s[i][j];
        }
    }
    //조합 계산
    combination(n/2, 0, 1);
    //출력
    cout << ans;
}