#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//각 자리수의 합을 구하는 함수
int getSum(int n){
    string p = to_string(n); // 검사할 소수
    int sum = 0;
    
    for(int j=0; j<p.size(); j++){
        int t = p[j] - '0';
        sum += t*t;
    }
    return sum;
}

vector<int> isPrime(const int n)
{
    vector<int> prime(n + 1, 1);
    // 소수 = 1, 소수 아님 = 0
    prime[0] = prime[1] = 0;
    for (int i = 2; i * i <= n; i++)
    {
        if (prime[i] == 1)
        {
            for (int j = i * i; j <= n; j += i)
            {
                prime[j] = 0;
            }
        }
    }
    
    return prime;
}

vector<int> check(vector<int> &prime, int const n)
{
    vector<int> answer;
    
    for(int i=2; i<=n; i++){
        //소수라면 상근수 계산
        if (prime[i] == 1)
        {
            vector<int> visit;      //방문한 합계

            int tt = i;
            while(1){
                
                int sum = getSum(tt);
                
                //소수상근수
                if(sum == 1){
                    answer.push_back(i);
                    break;
                }
                //합계가 이전에 나온 적 있는 합계라면
                if(find(visit.begin(), visit.end(), sum) != visit.end()){
                    break;
                }
                
                visit.push_back(sum);
                tt = sum;
            }
        }
    }
    return answer;
}

int main()
{
    int n;
    // 입력
    cin >> n;
    // n 이하 소수 구하기
    vector<int> prime = isPrime(n);
    //소수 상근수 계산
    vector<int> answer = check(prime, n);
    //출력
    for(int i : answer){
        cout << i << '\n';
    }
}