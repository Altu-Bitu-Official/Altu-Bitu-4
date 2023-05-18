#include <iostream>

using namespace std;

int main(){

    string name;
    int count[26];
    cin >> name;

    char result[name.length()];

    int n = 0; // result 출력할 때 사용
    int m = name.length()-1;

    for(int i=0; i<26; i++){ 
        count[i] = 0;
    }
    for(int i=0; i<name.length(); i++){ //알파벳 별로 개수 세기
        int a = name[i] - 65;
        count[a] ++;
    }

    int isPossible = 0;
    for(int i=0; i<26; i++){ //홀수개인 알파벳이 두개이상이면 불가능
        if(count[i]%2 ==1){
            isPossible++;
        }
    }

    if(isPossible > 1){
        cout << "I'm Sorry Hansoo" << '\n';
        return 0;
    }

    for(int i=0; i<26; i++){
        if(count[i]%2==1){ //홀수개인 알파벳은 무조건 중앙에 한개 들어감
            result[(name.length()-1)/2] = i + 65;
            count[i]--;
        }
        while(count[i] > 0){
            result[n++] = i + 65;
            count[i]--;
            result[m--] = i + 65;
            count[i]--;
        }
    }

    for(int i=0; i<name.length(); i++){
        cout << result[i];
    }


    return 0;
}