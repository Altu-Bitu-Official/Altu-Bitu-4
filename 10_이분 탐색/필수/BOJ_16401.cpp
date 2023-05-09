#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sol(vector<int> &v, int m){//m은 조카의 수
    int ans=0;

    //내림차순으로 정렬
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    int longe=v[0];//가장 긴 막대 과자의 길이부터 시작
    int shorte=1;
    
    while(shorte<=longe){
        int cnt=0;
        int middle=(shorte+longe)/2;
        for(int i=0;i<v.size();i++){//과자를 나눠줄 수 있는 사람수 세기
            cnt+=v[i]/middle;
        }
        if(cnt<m){//과자를 나눠줄 수 있는 인원이 조카의 수보다 작으면(과자의 길이가 너무 길면)
            longe=middle-1;//상한을 middle보다 줄인다
        }
        else{//과자를 나눠줄 수 있는 인원이 조카의 수보다 크거나 같으면
            ans=middle;
            shorte=middle+1;
        }
    }
    cout<< ans;
    return 0;

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, n;//m명의 조카, n개의 과자

    cin >> m >> n;//조카 수와 과자 개수 입력
    
    vector<int> v;//과자의 길이를 저장할 벡터 생성
    
    //과자 길이 저장
    int input;
    for(int i=0;i<n;i++){
        cin>>input;
        v.push_back(input);
    }
    
    //풀이하기
    sol(v, m);

}