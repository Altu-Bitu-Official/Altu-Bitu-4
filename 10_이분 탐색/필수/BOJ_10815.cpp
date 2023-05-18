#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void sol(vector<int> v1, vector<int> v2){
    vector<int> v3(500000,0);//정답을 저장할 벡터 생성

    sort(v1.begin(), v1.end());

    //이분탐색
    for(int i=0;i<v2.size();i++){
    int max=v1.size()-1;
    int min=0;
    while(min<=max){
        int middle=(max+min)/2;
        if(v1[middle]==v2[i]){//상근이가 가지고있는 카드중 middle값이 찾는값과 일치
            v3[i]=1;//정답벡터에 1을 저장
            break;
        }
        if(v1[middle]>v2[i]){//찾으려는 카드가 middle보다 작으면
            max=middle-1;//상한값을 middle-1로 조정
        }
        else{//찾으려는 카드가 middle보다 크면
            min=middle+1;//하한값을 middle+1로 조정
        }
    }
    }
    for(int j=0;j<v2.size();j++){
        cout<<v3[j]<<' ';
    }

}


int main(){
    int m, n;

    cin >> n ;//상근이가 가지고 있는 카드의 개수
    
    vector<int> v1;//상근이가 가지고 있는 카드 벡터

    //상근이의 카드 입력
    int input;
    for(int i=0;i<n;i++){
        cin >> input;
        v1.push_back(input);
    }

    cin >> m;
    vector<int> v2;//상근이가 가지고 있는 숫자카드인지 아닌지를 구해야 할 정수들이 저장될 벡터
    
    for(int i=0;i<m;i++){
        cin >> input;
        v2.push_back(input);
    }

    sol(v1, v2);



}