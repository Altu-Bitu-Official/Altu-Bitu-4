#include <iostream>
#include <vector>
#include <climits>

using namespace std;
const int MAX_N = 20;
int v[MAX_N+1][MAX_N+1];
int member[MAX_N/2+1];
int member_link[MAX_N/2+1];
bool is_used[MAX_N+1];
int n,diff=INT_MAX;



int calcStat() {
    int start = 0, link = 0,j,k=0;
    /*start 능력치 계산 코드*/
    for (int i = 0; i < n / 2; i++) {
        for (int l = 0; l < n/2; l++)
        {
           start+=v[member[i]][member[l]];
        }

    }
    /*link 능력치 계산 코드*/
        for (int i = 1; i <= n; i++) {
            for ( j = 0; j < n / 2; j++) {
                if (member[j] == i) {
                    break;
                }
            }
            if(j==n/2){
                member_link[k++]=i;
            }
    }


    for (int i = 0; i < n / 2; i++) {
        for (int l = 0; l < n/2; l++)
        {
            link+=v[member_link[i]][member_link[l]];
        }

    }

    return abs(link-start);
}


void backTrack(int cnt,int curr){
    int res;

    if(cnt ==n/2){
        res=calcStat();

        if(res < diff){
            diff =res;
        }
        return;
    }

    for(int i=1;i<=n;i++){
        if(is_used[i]){ //이미 사용한 숫자면 continue
            continue;
        }
        if(curr>i){ //현재 숫자보다 작은 숫자는 다시 참조하지 않기
            continue;
        }

        is_used[i]=true;
        member[cnt]=i;
        backTrack(cnt+1,i);
        is_used[i]=false;
    }

}


int main(){
    cin >>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >>v[i][j];
        }
    }

    backTrack(0,0);


    cout <<diff;
    return 0;
}