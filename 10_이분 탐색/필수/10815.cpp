#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int binarySearch(int n, int key, vector<int> &cards) {
    int left = 0; 
    int right = n - 1;
    int mid;

    // 키 값의 존재여부 구하기
    while (left <= right) {
        mid = (left + right) / 2;
        if (cards[mid] == key) {   // key 값이 배열의 중앙값과 같을 때
            return 1;
        }
        else if (cards[mid] > key) { // key 값이 배열의 중앙값보다 작을 때-> 더 작은 값 탐색
            right = mid - 1;
        }
        else {  // key 값이 배열의 중앙값보다 클때-> 더 큰 값 탐색
            left = mid + 1;
        }
    }
    return 0;
}

int main()
{
    
    //입력
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m, key;
    cin >> n;
    vector<int> cards(n, 0);
    
    for(int i=0; i<n; i++){
        cin >> cards[i];
    }
    cin >> m;
    sort(cards.begin(), cards.end());   //quick sort를 이용해 배열 오름차순으로 정렬

    while(m--){
        cin >> key;
        cout << binarySearch(n, key, cards) << " ";
    }

    return 0;
}