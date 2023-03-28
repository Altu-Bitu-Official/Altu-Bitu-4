#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n,m,b,a,c,st=0; 
    int plus=0,minus=0; //plus는 블록 추가, minus는 블록 제거
    cin>>n>>m>>b;
    int vecsize = n*m;

    //입력받은 걸 저장할 벡터 생성
    vector<int> ground(vecsize,0);

    for(int i=0; i<vecsize; i++){
        cin>>a;
        ground[i] = a;
    }

    //시간 계산용 벡터 하나 생성 
    vector<int> time;

    int minimum = *min_element(ground.begin(), ground.end());
    int maximum = *max_element(ground.begin(), ground.end());
    int find_min = time[minimum];
    int g=0;

    for(st = minimum;st<=maximum;st++){ //st는 기준이 될 값
        for(int i=0;i<vecsize;i++){
            c=st-ground[i];
            b+=c;
            if(b<0)
            break;
            if(c<0){ // c가 기준보다크다 -> 블록 제거
                minus-=c;
            }
            else{//c가 0보다 크거나 같을 경우 -> 블록 추가
                plus+=c;
            }
        }
        if(b<0)
        continue;
        time[st] = 2*minus+plus;
        if(find_min>time[st]){
            find_min=time[st];
            g=st;
        }
    }
    cout << find_min << g;
    return 0;
}