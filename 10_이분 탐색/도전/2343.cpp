#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int cntBlu(int time, vector<int> &lecture){
    int blu =0; //블루레이 갯수
    int sum = lecture[0]; // 한 블루레이에 저장되는 영상의 길이 합
    for(int i=1;i<lecture.size();i++){
        if((sum+lecture[i])<=time){ //다음 영상을 합쳤을 때 길이와 time(블루레이의 길이) 비교
            sum+= lecture[i];
        }else{
            blu++; //합이 더 길다면 블루레이 갯수 +1
            sum= lecture[i]; // 한 블루레이에 저장되는 영상의 길이도 i번째 영상으로 초기화
        }
    }
    return blu;
}

int binarySearch(int left,int right,int target, vector<int> &lecture){
    while(left<=right){
        int mid = (left+right)/2;
        int cnt = cntBlu(mid,lecture);
        if(cnt >=target){ //블루레이의 갯수가 target보다 많다면 힌 블루레이의 크기를 늘려줌
            left = mid +1;
        }else{
            right = mid - 1;
        }
    }
    return left;

}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(NULL);
    int n,m;
    cin >> n >>m;
    vector<int> lecture(n,0);
    for(int i=0;i<n;i++){
        cin >>lecture[i];
    }

    int sum = accumulate(lecture.begin(),lecture.end(),0);

    //최소는 영상의 최댓값, 최대는 영상의 전체 합
    cout << binarySearch(*max_element(lecture.begin(),lecture.end()),sum,m,lecture);

}