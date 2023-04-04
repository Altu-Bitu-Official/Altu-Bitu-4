#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<char, int> setMap(string &name){
    map<char, int> m;  //key = 알파벳, value = 빈도수

    for(char i:name){
        if(m.empty()){
            m.insert({i, 1});
            continue;
        }
        //m이 비지 않았다면 알파벳이 존재하는지 검사 후 ++
        if(m.find(i) != m.end()){
            m.find(i) -> second++;
            continue;
        }
        //찾지 못했으면 추가
        m.insert({i, 1});
    }
    
    return m;
}

bool checkName(map<char, int> &m, char &c){
    bool check = false;
    for(auto p : m){
        //빈도수가 홀수인데 이미 홀수인 알파벳이 존재한다면 실패
        if(p.second % 2 != 0){
            //실패
            if(check == true){
                return false;
            }
            //else
            check = true;   
            //c에 홀수인 알파벳 하나 저장해주고 map에는 갯수 하나 빼기
            c = p.first;
            p.second--;
        }
    }
    return true;
}

vector <char> makeName(map<char, int> &m, char& c){
    vector <char> answer;

    //팰린드롬 만들기 (앞부분)
    for(auto p:m){
        for(int j=0; j<p.second/2; j++){
            answer.push_back(p.first);
        }
    }
    //팰린드롬 만들기 (뒷부분)
    //홀수인 알파벳이 존재한다면 정 가운데에 추가
    if(c != '0'){
        answer.push_back(c);
        for(int i=answer.size()-2; i>=0; i--){
            answer.push_back(answer[i]);
        }
    }
    //알파벳 개수가 모두 짝수라면
    else{
        for(int i=answer.size()-1; i>=0; i--){
            answer.push_back(answer[i]);
        }
    }

    return answer;
}

int main()
{
    string name;

    //입력
    cin >> name;
    //map에 알파벳 빈도수 채우기
    map<char, int> m = setMap(name);
    
    char c = '0';   //홀수일 경우 알파벳을 저장할 변수

    //빈도수 검사
    //빈도수 : 홀수는 1개만 존재 가능
    if(!checkName(m, c)){
        cout << "I'm Sorry Hansoo";
        return 0;
    }
    //팰린드롬 만들기
    vector <char> answer = makeName(m, c);
    
    //출력
    for(auto i : answer){
        cout << i;
    }
}
/*
@@질문입니다!
처음에는 map 대신에 pair을 써서 사용했는데 벡터에 값이 

input : AABB
vector : 
A 1
A 1
B 1
B 1

이런 식으로 쪼개져서 들어가더라구요 ㅠㅠ 
왜... 아래 코드는 안 됐는지 궁금합니다.

vector<pair<char, int>> v;  //first = 알파벳, second = 빈도수
    
for(char i:name){
    if(v.empty()){
        v.push_back({i, 1});
        continue;
    }
    //v가 비지 않았다면 알파벳이 존재하는지 검사 후 ++
    for(int i=0; i<v.size(); i++){
        if(v[i].first == i){
            v[i].second++;
            continue;
        }
    }
    //찾지 못했으면 추가
    v.push_back({i, 1});
}
*/