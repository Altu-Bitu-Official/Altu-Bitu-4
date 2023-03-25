#include "iostream"
#include "vector"
#include "algorithm"
#include "map"

using namespace std;

bool judgePalindrome(string name, map<char, int> &check, vector<char> &keys) {
    int count = name.size() % 2;    // 홀수개의 글자를 용납할 수 있는 횟수 : 글자 길이가 짝수면 0, 홀수면 1

    for (int i = 0; i < name.size(); i++) {
        if (check.find(name[i]) == check.end()) {
            check[name[i]] = 1;
            keys.push_back(name[i]);
        }
        else {
            check[name[i]]++;
        }
    }
    for (int i = 0; i < keys.size(); i++) {
        if ((check[keys[i]] % 2) == 1) {
            count--;
            if (count < 0) {
                return false;
            }
        }
    }
    return true;
}

void setWord(char c, int &count, string &palindrome, int k){
    for(int i=0; i<k; i++){
        palindrome[count] = c;
        palindrome[palindrome.size() - count] = c;
        count++;
    }
}

string makePalindrome(string &name, map<char, int> &check, vector<char> &keys) {
    string palindrome{"", name.size()+1};
    int count = 1;
    sort(keys.begin(), keys.end());

    for(int i=0; i<keys.size(); i++){
        if(check[keys[i]] % 2 == 1){    // 홀수 개수
            setWord(keys[i], count, palindrome, check[keys[i]]/2);
            palindrome[(name.size()/2)+1] = keys[i];
        }
        else{   // 짝수 개수
            setWord(keys[i], count, palindrome, check[keys[i]]/2);
        }
    }
    palindrome.erase(palindrome.begin());

    return palindrome;
}

int main() {
    string name;
    // 입력
    cin >> name;
    map<char, int> name_map;
    vector<char> name_key;

    // 연산과 출력
    if (judgePalindrome(name, name_map, name_key)) {
        cout << makePalindrome(name, name_map, name_key);
    }
    else {
        cout << "I'm Sorry Hansoo";
    }
}