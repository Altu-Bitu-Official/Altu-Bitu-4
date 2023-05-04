#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool visited[20];
int relation[20][20];
int n=0;
int mymin=10000000; //대강 큰수로 지정해주기

void maketeam(int a, int b){
    vector<int> start; //스타트팀 계산용
    vector<int> link;  // 링크 팀 계산용;

    int s_score = 0;
    int l_score = 0;
    if(b == (n/2)){
        for(int i = 0; i < n; i++){
            if(visited[i] == true) 
                start.push_back(i);
            else 
                link.push_back(i);
        }
        for(int i = 0; i < (n/2); i++){
            for(int j = 0; j < (n/2); j++){
                s_score += relation[start[i]][start[j]];
                l_score += relation[link[i]][link[j]];
            } 
        }

        if(abs(s_score - l_score) < mymin){
            mymin = abs(s_score - l_score);
        }
        return;
    }
    for(int i = a; i < n; i++){
        if(visited[i]){
            continue;
        }
        else{
            visited[i] = true;
            maketeam(i,b+1);// 재귀 해준뒤에
            visited[i] = false; //i를 다시 false로 바꿔주기
        }
    }
}
int main() {
    cin>>n;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>relation[i][j];
        }
    }

    maketeam(0,0);

    cout<< mymin;
}