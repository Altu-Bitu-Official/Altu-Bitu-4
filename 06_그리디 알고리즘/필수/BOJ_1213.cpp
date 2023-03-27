#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

// 주어진 문자열이 팰린드롬이 될 수 있는지 문자열의 알파벳과 그 개수를 저장한 맵을 통해 체크하는 함수
bool checkPalindrome(char& odd_alp, const map<char, int>& alp_cnt) {
    int odd_cnt = 0;
    for (auto iter : alp_cnt) {
        if (iter.second % 2 == 1) {     //개수가 홀수인 알파벳이 있을 때
            odd_alp = iter.first;   //그 알파벳을 저장
            odd_cnt++;  //홀수 카운트 증가
            if (odd_cnt == 2) {     //홀수인 알파벳이 1개 초과 -> 팰린드롬 불가.
                return false;
            }
        }
    }
    return true;
}

//주어진 문자열을 팰린드롬으로 만드는 함수
string makePalindrome(int name_len, char odd_alp, map<char, int> alp_cnt) {
    string answer = "";

    for (auto iter : alp_cnt) {
        //사전 순으로 정렬된 알파벳을 등장 횟수의 절반만 빈 문자열에 추가.
        for (int i = 0; i < iter.second/2; i++) {
            answer += iter.first;
        }
    }

    if (odd_alp != 'a') {   //홀수 갯수의 알파벳이 존재할 때
        answer += odd_alp;  //가운데에 추가
    }
    for (int i = name_len/2 -1; i >= 0; i--) {
        answer += answer[i];    //문자열을 뒤집어서 뒤에 추가.
    }
    return answer;
}

int main() {
    int name_len;   //주어진 문자열의 길이
    char odd_alp = 'a';     //등장 횟수가 홀수인 알파벳
    string name;    //주어진 문자열
    map<char, int> alp_cnt;     //문자열 내 알파벳과 각각의 개수를 저장하는 맵
    
    //입력
    cin >> name;
    name_len = name.length();

    for (int i = 0; i < name_len; i++) {
        alp_cnt[name[i]]++;     //알파벳의 개수를 저장하는 맵을 생성.
    }

    //팰린드롬이 될 수 있는지 확인
    if (!checkPalindrome(odd_alp, alp_cnt)) {
        cout << "I'm Sorry Hansoo";
        return 0;
    }

    //가능할 경우 팰린드롬 출력
    cout << makePalindrome(name_len, odd_alp, alp_cnt);


}