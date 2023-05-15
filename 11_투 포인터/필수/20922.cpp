#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;
//left와 right 사이에 있는 원소들==연속부분수열
//right 포인터를 오른쪽으로 이동하면서 연속 부분 수열에 원소를 추가 
//만약 연속 부분 수열에 k개 초과의 같은 정수가 포함되면 left 포인터를 오른쪽으로 이동하면서 연속 부분 수열에서 원소를 제거
int LCS(vector<int> arr, int k, int n) {
    int left = 0, right = 0;
    vector<int> cnt(200001, 0);
    int length = 0;
    while (right < n) {//다 조사했다는뜻
        cnt[arr[right]]++;
         while (cnt[arr[right]] > k) {
            cnt[arr[left]]--;//앞으로 나가야 하니까. 없던걸로 침
            left++;//대신 연속순열 시작점을 옮겨서 상쇄시킴
        }
        length = max(length, right - left + 1);//max갱신
        right++;//앞으로나가기
    }
    return length;
}

int main() {
    //입력
    int n, k;
    cin >> n >> k;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    //계산&출력
    cout << LCS(arr, k, n);
    return 0;
}
