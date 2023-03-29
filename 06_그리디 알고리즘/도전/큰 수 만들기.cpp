#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    int n = number.length();
    vector<int> num(n);
    
    for (int i=0; i<n; i++) // 벡터에 넣기
        num[i] = number[i] - '0';
    
    string answer = "";
    int cnt = n-k, max_num, max_idx, start_idx = 0;
    
    while (1){
        if (cnt == 0) // k번 제거 시 종료
            break;
        max_num = *max_element(num.begin() + start_idx, num.end() - cnt + 1); // 최고자릿수 결정
        max_idx = find(num.begin() + start_idx, num.end() - cnt + 1, max_num) - num.begin(); // 최고자릿수 인덱스
        answer += to_string(max_num);
        cnt--;
        start_idx = max_idx+1;
    }
    return answer;
}

int main(){
    
    string number; int k;
    
    cin >> number >> k;
    
    cout << solution(number, k);
    
}