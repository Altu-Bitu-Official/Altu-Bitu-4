#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<char,int> getStringMap(string s1){ //문자열이 A~Z까지 각 문자를 몇 개씩 가지고 있는지 나타내줄 map 반환해주는 함수
 map<char,int> a;
    for (char c = 'A'; c < 'Z'; c++)
       a.insert({c,0});

    for(int i=0;i<s1.size();i++){
        a[s1[i]]++;
    }
    return a;

}

int isSimilar(vector<string> words){ //비슷한 단어 갯수 출력 함수
    string comp = words[0]; // 첫 번째 단어
    int ans=0;
    map<char,int> s1=getStringMap(comp),s2;

    for(int i=1;i<words.size();i++) {
        s2=getStringMap(words[i]);
        int sub =comp.length()-words[i].length(); //두 문자열 길이 차
        if(abs(sub)>1){ //문자열의 길이차가 1 초과라면 비슷한 단어가 될 수 없음
            continue;
        }
        int tmp=0; //서로 다른 문자 갯수를 카운트하는 변수
        for (char c = 'A'; c < 'Z'; c++){
                tmp +=abs(s1[c]-s2[c]);
        }
            if(tmp<=2){ //0개의 경우 같은 구성을 갖는 단어

                ans++;
            }
        }

    return ans;
    }


int main(){
    int num; // 입력 받을 단어 갯수
    string tmp; //입력 받을 단어 저장할 변수
    vector<string> words; //입력 받은 단어들
 cin >> num;
    for(int i =0;i<num;i++){
       cin >>tmp;
       words.push_back(tmp);
    }

cout <<isSimilar(words);
    return 0;
}
