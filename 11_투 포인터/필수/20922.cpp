#include <iostream>
#include <vector>
using namespace std;

int TwoPointer(vector<int>& arr, int n, int k) {
    vector<int> freq(100001, 0); //최대 입력 크기가 100,000이므로 freq 벡터의 크기 100,001로 설정
    int max_length = 0, start = 0;
    for (int end = 0; end < n; end++) {
        freq[arr[end]]++;
        while (freq[arr[end]] > k) { //중복 수가 k를 초과한다면 start를 이동시키며 freq 갱신
            freq[arr[start]]--; //start 오른쪽으로 한 칸 이동 
            start++;
        }
        max_length = max(max_length, end - start + 1); //end값에 따라 max_length값 갱신 
        //반복문 돌아가면서 end가 n이 될 때까지 오른쪽으로 한 칸 이동
    }
    return max_length;
}

int main() {
    //입출력 향상 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    //입력 
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    //연산&출력
    cout << TwoPointer(arr, n, k) << '\n';
    return 0;
}