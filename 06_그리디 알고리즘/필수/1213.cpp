#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

bool checkPalindrome(int &n, int &odd) { // 팰린드롬이 존재하는지 여부 반환
    // 팰린드롬 존재 조건
    // 문자열 길이가 홀수 -> 홀수 하나 존재 / 짝수 -> 모두 짝수
    if((n % 2 && odd == 1) || (!(n % 2) && !odd)) {
        return true;
    }
    return false;
}

string makePalindrome(string &str) { // str로부터 만들어진 팰린드롬 반환, 없다면 "" 반환
    map <char, int> chars; // string의 각 문자와 그 개수를 저장할 맵
    int n = str.length();
    for(int i = 0; i < n; i++) {
        if(chars.find(str[i]) == chars.end()) { // 문자가 저장되지 않았으면
            chars.insert({ str[i], 1 }); // 개수를 1로 설정
            continue;
        }
        chars[str[i]]++; // 이미 저장되었으면 개수 + 1
    }
    
    int odd = 0; // 홀수 개수
    auto iter = chars.begin();
    while (iter != chars.end()) { // 맵에 저장된 문자마다 반복
        if(iter->second % 2) { // 해당 문자가 홀수 개면
            odd++;
        }
        ++iter;
    }

    if(!checkPalindrome(n, odd)) { // 팰린드롬이 존재하지 않으면
        return "";                 // "" 반환
    }

    // 팰린드롬이 존재하면
    string result("", n); // 결과를 저장할 문자열
    int idx = 0;          // 문자열에 저장할 인덱스
    iter = chars.begin();
    while (iter != chars.end()) { // 맵에 저장된 문자마다 반복
        char c = iter->first;     // 개수
        int num = iter->second;   // 문자
        if(num % 2) { // 홀수 개면 
            result[n / 2] = c;  // 먼저 중간에 저장하고
            num--;              // 개수 - 1
        }
        for(int i = 0; i < num / 2; i++) {
            result[idx] = result[n - 1 - idx] = c; // 문자열을 대칭으로 채우고
            idx++; // 인덱스 증가
        }  
        ++iter;
    }
    return result;
}

int main() {    
    string input;
    cin >> input;

    string result = makePalindrome(input); // 입력으로부터 만들어진 팰린드롬, 없다면 ""
    if(result == "") {
        cout << "I'm Sorry Hansoo";
        return 0;
    }
    
    cout << result;
    return 0;
}