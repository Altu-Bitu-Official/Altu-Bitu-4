#include <iostream>
#include <map>
#include <vector>

using namespace std;

void printPalindrome(map<char, int> &alpha, int n) {
    vector<char> str(n);
    int i=0;

    for(auto a:alpha) {
        //홀수번 쓰인 알파벳은 중간에 들어가야함
        if(a.second%2==1) {
            str[n/2]=a.first;
            a.second--;
        }
        //사전순 앞서는 알파벳부터 앞뒤로 하나씩 붙임
        while(a.second>0) {
            str[i]=str[n-i-1]=a.first;
            a.second-=2;
            i++;
        }
    }

    for(char s:str) {
        cout << s;
    }
}

int main() {
    string str;
    cin >> str;

    map<char, int> alpha;

    bool flag=false;

    for(int i=0; i<str.size(); i++) {
        //알파벳 키로 map에 저장
        if(!alpha.count(str[i])) {
            alpha.insert(make_pair(str[i],1));
        } else {
            alpha[str[i]]++;
        }
    }

    for(pair<char, int> a: alpha) {
        //홀수개 알파벳 두개 이상이면 팰린드롬 만들 수 없음
        if(a.second%2==1) {
            if(flag) {
                cout << "I'm Sorry Hansoo";
                return 0;
            }
            flag=true;
        }
    }

    //가장 작은 팰린드롬 출력
    printPalindrome(alpha, str.size());

    return 0;
}