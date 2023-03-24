#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
bool isit_similar(string word, string factor) {//정렬된 상태의 word와 factor가 전달되었습니다.

    string longer, shorter;
    if (word.length() > factor.length()) {
        longer = word; shorter = factor;
    }
    else if (word.length() < factor.length()) {
        longer = factor; shorter = word;
    }
    else {
        longer = word; shorter = factor;
    }

    vector<char> l(longer.begin(), longer.end());
    vector<char> s(shorter.begin(), shorter.end());

    for (int i = 0; i < shorter.length(); i++) {
        for (int j = 0; j < longer.length(); j++) {
            if (s[i] == l[j]) {
                s[i] = '0'; l[j] = '0';
                //일치하는 문자를 찾으면 지운다.
            }
        }
    }

    int a, b; a = b = 0;
    for (int i = 0; i < shorter.length(); i++) {
        if (s[i] != '0') {
            a++;
        }
    }
    for (int j = 0; j < longer.length(); j++) {
        if (l[j] != '0') {
            b++;
        }
    }
    if ((a + b == 1) || (a == 1 && b == 1)) {
        return true;
    }
    else return false;
}
int main() {
    int n;
    int count;//비슷한 단어 카운트.
    string word;
    count = 0;
    cin >> n >> word;
    n--;
    sort(word.begin(), word.end());
    while (n--) {//n-1번만큼 실행
        string factor;
        cin >> factor;
        sort(factor.begin(), factor.end());
        if (factor.compare(word) == 0) {//둘이 구성이 같으면
            count++;
        }
        else if (isit_similar(word, factor) == true) {//구성이 같진 않더라도 비슷하면
            count++;
        }

    }
    cout << count;
}