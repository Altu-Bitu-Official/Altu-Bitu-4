#include "iostream"
#include "vector"
#include "algorithm"
#include "map"

using namespace std;

// 팰린드롬을 만들 수 있는지 판단하는 함수
bool judgePalindrome(string name, map<char, int> &check) {
    int count = name.size() % 2;    // 홀수개의 글자를 용납할 수 있는 횟수 : 글자 길이가 짝수면 0, 홀수면 1
                                    // 홀수 단어라면 중앙자리가 생겨 홀수개의 글자 1개가 있을 수 있지만, 짝수는 모든 글자 개수가 2의 배수가 되어야하므로 X

    // name의 i번째 글자가 check에 key로 존재하지 않는다면 새로운 key로 등록, value는 항상 1
    // name의 i번째 글자가 check에 key로 존재한다면 해당하는 value를 ++
    for (int i = 0; i < name.size(); i++) {
        if (check.find(name[i]) == check.end()) {
            check[name[i]] = 1;
        } else {
            check[name[i]]++;
        }
    }
    // check를 돌면서 홀수개의 글자가 있다면 count--
    // count가 0보다 작을 경우 허용하는 홀수 개의 단어 수보다 많다는 뜻이므로 팰린드롬을 만들 수 없다.
    for (auto iter: check) {
        if ((iter.second % 2) == 1) {
            count--;
            if (count < 0) {
                return false;
            }
        }
    }
    return true;
}

// 글자들을 palindrome에 넣어주는 함수
void setWord(char c, int &count, string &palindrome, int k) {
    for (int i = 0; i < k; i++) {
        palindrome[count] = c;
        palindrome[palindrome.size() - count] = c;
        count++;
    }
}

// 팰린드롬 단어를 만드는 함수
string makePalindrome(string &name, map<char, int> &check) {
    string palindrome("", name.size() + 1); // setWord에서 앞뒤 자리 계산이 용이하도록 name크기 +1로 설정
    int count = 1;  // 글자들을 넣을 위치

    // check를 돌면서 key에 해당하는 글자가
    // 홀수개라면 setWord를 해주고 중앙에 남은 하나를 넣어준다
    // 짝수개라면 setWord를 해준다.
    for (auto iter: check) {
        if (iter.second % 2 == 1) {
            setWord(iter.first, count, palindrome, iter.second / 2);
            palindrome[(name.size() / 2) + 1] = iter.first;
        } else {
            setWord(iter.first, count, palindrome, iter.second / 2);
        }
    }
    // palindrome[0]을 지우고 return
    palindrome.erase(palindrome.begin());
    return palindrome;
}

int main() {
    string name;
    map<char, int> name_map;
    // 입력
    cin >> name;
    // 연산과 출력
    if (judgePalindrome(name, name_map)) {
        cout << makePalindrome(name, name_map);
    }
    else {
        cout << "I'm Sorry Hansoo";
    }
}