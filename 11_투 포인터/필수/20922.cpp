#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int>& arr, int n, int k){
    int left = 1, right = 1;
    int ans = 0;
    vector<int> count;  
    count.assign(100001, 0);

    while(right <= n){  //우측 포인터가 배열을 넘기 전까지 반복
        count[arr[right]]++;   //arr[right]의 숫자에 해당하는 count++
        while(count[arr[right]] > k){   //k개가 넘는 숫자가 나오면
            count[arr[left]]--; //다음 범위의 시작점까지 왼쪽 포인터 이동
            left++;
        }
        
        ans = max(ans, right-left+1);
        right++;
    }
    
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    vector<int> arr;
    
    //입력
    cin >> n >> k;
    arr.assign(n+1, 0); //초기화
    
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }
    //연산
    int ans = solution(arr, n, k);
    //출력
    cout << ans;
}