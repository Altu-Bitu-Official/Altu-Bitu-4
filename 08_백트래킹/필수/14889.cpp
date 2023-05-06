#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int n;
vector <vector<int>> s;
int Min = 1000000000;
bool is_team1[20]; //team1에 배정한 선수 저장

void getDiff(){
    int team1 = 0;
	int team2 = 0;

	for (int i=0; i<n; i++){
	    for (int j=i+1; j<n; j++){
		    if (is_team1[i] && is_team1[j]){ //team1에 대항하는 선수이면 시너지값을 더해줌
                    team1 += s[i][j] + s[j][i];
                }
			    else if (!is_team1[i] && !is_team1[j]){
                    team2 += s[i][j] + s[j][i];
                }
		    }
	    }
        int diff = abs(team1 - team2);
        if(Min > diff){
            Min = diff;
        }
}

void backtrack(int mem, int cnt) 
{
	if (mem == n/2) 
	{
        getDiff(); //시너지 값의 차이 계산
		return;
	}

	for (int i=cnt; i<n; i++)
	{
        if(!is_team1[i]){
		    is_team1[i] = true;
		    backtrack(mem+1, i+1);
		    is_team1[i] = false;
        }
	}

}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    s.assign(n, vector<int>(n));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> s[i][j];
        }
    }
    backtrack(0,0);

    cout << Min;
    
    return 0;
}