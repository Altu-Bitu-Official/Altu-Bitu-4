#include <iostream>
#include <vector>

using namespace std;

#define MAX 100000

//arr의 값을 입력받으면서 조건에 따라 포인터를 이동하고, 최대 길이를 리턴하는 함수
int checkLength(vector<int>& arr, int n, int k) {
    int left = 0, len = 0;
    int cnt[MAX + 1] = {0}; //숫자의 등장 횟수를 세는 배열

    for (int i = 0; i < n; i++) {
        cin >> arr[i];  //배열에 수 입력
        cnt[arr[i]]++;  //등장 횟수 증가
        while (cnt[arr[i]] > k) {   //만약 k보다 숫자의 등장 횟수가 많으면, 왼쪽 포인터 이동.
            cnt[arr[left++]]--;     //왼쪽 포인터 숫자의 cnt 감소 후 한 칸 오른쪽으로 이동.
        }
        len = max(len, i-left + 1);     //최대 길이 저장
    }

    return len;
}

int main() {
    int n, k;
    vector<int> arr;

    cin >> n >> k;
    arr.assign(n, 0);

    //출력
    cout << checkLength(arr, n, k);
}