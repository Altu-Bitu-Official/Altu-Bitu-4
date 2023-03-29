#include "iostream"
#include "algorithm"

using namespace std;

int main(){
    //입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //입력
    int n, tmp;
    int sum = 0, count = 0;
    cin >> n;

    while(n--){
        cin >> tmp;
        count += tmp/2; // 입력값을 2로 나눈 몫을 count에 더해준다
        sum += tmp;
    }

    if(sum%3){  // sum은 2+1 즉 3의 배수여야함
        cout << "NO";
        return 0;
    }
    // 2짜리 물뿌리개를 쓸 수 있는 경우가 총 물을 뿌리는 횟수인 sum/3보다 크거나 작게 되면 조건을 만족할 수 있다.
    string answer = ((sum/3)<=count) ? "YES" : "NO";
    cout << answer;
}