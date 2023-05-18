#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//n과 카드 숫자가 담긴 배열, 키 값을 인자로 받아 배열 내 키 값의 존재 여부에 따라 숫자를 리턴하는 함수.
int binarySearch(int n, vector<int>& card, int key) {
    int left = 0;
    int right = n-1;
    int mid;

    while (left <= right) {     //left값이 right보다 작거나 같을 동안 반복
        mid = (left+right) / 2;
        if (card[mid] == key) { 
            return 1;
        }
        else if (card[mid] > key) {     //가운데 값이 키 값보다 큼 -> 가운데보다 왼쪽으로 이동
            right = mid-1;
        }
        else {  //가운데 값이 키 값보다 작음 -> 가운데보다 오른쪽으로 이동.
            left = mid+1;
        }
    }
    return 0;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, key;
    vector<int> card;

    //입력
    cin >> n;
    card.assign(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> card[i];
    }
    sort(card.begin(), card.end());
    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> key;
        
        //출력
        cout << binarySearch(n, card, key) << ' ';
    }
}