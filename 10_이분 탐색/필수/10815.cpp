#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int binarySearch(int n, int num, vector<int>& having){
    int left = 0;
    int right = n-1;
    int mid;
    //숫자가 배열에 존재하는지 탐색
    while(left <= right){
        mid = (left + right) / 2;   //중앙값
        if(having[mid] == num){ //숫자가 배열의 중앙값과 같다면
            return 1;   //1 반환
        }
        else if(having[mid] > num){ //숫자가 중앙값보다 작으면
            right = mid-1;  //왼쪽 배열(작은 수) 탐색
        }
        else{   //숫자가 중앙값보다 크면
            left = mid+1;   //오른쪽 배열(큰 수) 탐색
        }
    }
    return 0;
}

int main(){
    int n, m;
    int num;
    //having : 상근이가 가지고 있는 숫자 카드
    //checking : 상근이가 가지고 있는 숫자 카드인지 아닌지를 구해야 할 정수들
    vector<int> having, checking; 
    //입력
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> num;
        having.push_back(num);
    }
    cin >> m;
    for(int i=0; i<m; i++){
        cin >> num;
        checking.push_back(num);
    }
    //탐색할 배열 정렬
    sort(having.begin(), having.end());
    //이분 탐색
    for(int i=0; i<m; i++){
        cout << binarySearch(n, checking[i], having) << ' ';
    }
}