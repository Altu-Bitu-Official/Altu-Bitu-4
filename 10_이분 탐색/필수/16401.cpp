#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int countCookie(int n, int length, vector<int>& cookie){
    int count = 0;
    for(int i=0; i<n; i++){
        if(length != 0){
            count += cookie[i] / length;
        }
    }

    return count;
}

int binarySearch(int n, int m, vector<int> &cookie) {
    int left = 1; //left를 0으로 설정할 경우 right가 1일때 가능한 경우에도 계산되지 않을 수 있음
    int right = *max_element(cookie.begin(), cookie.end());
    int mid;
    int result = 0;
    
    while (left <= right) {
        mid = (left + right) / 2;
        int cnt = countCookie(n, mid, cookie);

        if (cnt >= m) {   
            left = mid + 1;
            result = mid;
        }
        else {  
            right = mid - 1;
        }
    }
    return result;
}



int main(){
    int m, n;
    cin >> m >> n ;

    vector<int> cookie(n);
    
    for (int i=0; i<n; i++){
        cin >> cookie[i];
    }

    cout << binarySearch(n, m, cookie) << '\n';


    return 0;
}