#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lenSnack(int length,vector<int> &l){
    int cnt =0;
    for(int i=0;i<l.size();i++){
        if(l[i]>=length){
            cnt+=l[i]/length; //한 개의 과자에서 여러 조각이 나올 수 있음. (과자의 길이 / 조각의 길이)
        }
    }
    return cnt;
}

int binarySearch(int left, int right, int target, vector<int>& l){
    while(left<=right){
        int mid =(left+right)/2;
        int num = lenSnack(mid,l);
        if(num >=target){ //나눠진 과자의 갯수가 target보다 크다면 조각의 길이를 더 길게해 갯수를 줄일 수 있도록 함
            left = mid +1;
        }
        else{
            right = mid -1;
        }
    }
    return left-1;
}

int main(){
    int m,n;
    cin >>m >> n;
    vector <int>  l (n,0);
    for(int i=0; i<n;i++){
        cin >>l[i];
    }

    sort(l.begin(),l.end());

    //조각의 최소 길이는 1 최대 길이는 l[n-1]
    cout <<binarySearch(1,l[n-1],m,l);
    return 0;

}