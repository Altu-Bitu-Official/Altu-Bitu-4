#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int snack[1000001];
	
long long check(int mid, int n){
    //검사
    long long newSize = 0;
    for(int j=0; j<n; j++){
        //중간값으로 나눌 수 있는 과자의 개수
        newSize += (snack[j] / mid);
    }
    return newSize;
}

int binarySearch(int m, int n){
    //과자 길이의 중간값을 mid로 삼아서 이분탐색.
    int left = 1;
    int right = snack[n-1];
    int answer = 0;
    //cout << right;
    while(left <= right){
        int mid = (left+right)/2;
        if(mid == 0){
            return 0;
        }
        //중간값으로 나눌 수 있는 과자의 개수 검사
        int newSize = check(mid, n);
        //과자 개수가 조카보다 많거나 크면 과자 길이 늘려서 재검사
        if(newSize >= m){
            answer = mid;
            left = mid+1;
        }
        //과자 개수가 조카보다 적으면 과자 길이 줄여서 재검사
        else{
            right = mid-1;
        }
    }
    return answer;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m;
    int n;   //조카의 수 m, 과자의 수 n 
    //입력
    cin >> m >> n;
    for(int i=0; i<n; i++){
        cin >> snack[i];
    }
    //정렬
    sort(snack, snack+n);
    
    //이분탐색 결과(과자 사이즈) 출력
    cout << binarySearch(m, n);
}