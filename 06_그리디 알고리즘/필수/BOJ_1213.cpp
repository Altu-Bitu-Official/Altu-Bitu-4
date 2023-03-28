#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

//팰린드롬 문자열 만드는 함수
string palindrome(string name) {
    int alphabet[26] = { 0 };
    int odd = 0, mid = -1;
    string pal = "";

    //알파벳 배열에 name 할당
    for (int i = 0; i < name.size(); i++) {
        alphabet[name[i] - 'A']++;
    }

    for (int i = 0; i < 26; i++) {
        if (alphabet[i] % 2 == 1) { //알파벳이 홀수개라면
            mid = i; //가운데가 그 알파벳
            alphabet[i]--;
            odd++;
        }
    }

    //홀수개 알파벳이 2개 이상이면 팰린드롬 불가능
    if (odd >= 2) {
        return "I'm Sorry Hansoo";
    }
    else {
        string tmp = "";
        //팰린드롬 앞 절반 채우기
        for (int i = 0; i < 26; i++) {
            if (alphabet[i] > 0) {
                for (int j = 0; j < alphabet[i] / 2; j++) {
                    pal += i + 'A';
                }
            }
        }
        //뒤 절반 채우기
        tmp = pal;
        reverse(tmp.begin(), tmp.end());
        if (mid != -1) {
            pal += mid + 'A';
        }
        pal += tmp;
        return pal;
    }
}

int main() {
    //입력
    string name;
    cin >> name;

    //출력
    cout << palindrome(name);
    return 0;    
}