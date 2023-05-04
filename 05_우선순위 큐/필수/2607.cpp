#include <iostream>
#include <vector>

using namespace std;

bool check(string word, string new_word){
    int n = new_word.length();
    vector<int> word_compare(n); //new_word의 글자 중 이미 word와 일치하는것으로 세어진 글자를 구분하기위함.
    for(int i=0; i<n; i++){
        word_compare[i] = 0;
    }
    if ((new_word.length() > (word.length()+1))||(new_word.length() < (word.length()-1))){ //두 단어의 글자 수 차이가 2이상이면 조건에 부합할 수 없음
        return false;
    }
    int same_Alp = 0;
    for(int i=0; i<word.length(); i++){
        for(int j=0; j<new_word.length(); j++){
            if((word[i] == new_word[j])&&(word_compare[j]==0)){
                same_Alp += 1; 
                word_compare[j] = 1; //이미 same_alp에 반영된 해당 글자 체크
                break;
            }
        }
    }

    //구성이같거나 한글자를 더하면 같아지는 경우
    if(word.length() == same_Alp){  
        return true;
    }
    //한글자 빼면 구성이 같아지는 경우
    if((word.length()-1==new_word.length())&&(same_Alp == new_word.length())){
        return true;
    }
    //한글자를 교체하면 구성이 같아지는 경우
    if((word.length()==new_word.length())&&(word.length()-1==same_Alp)){
        return true;
    }
    return false;
}

int main(){
    int n;
    int count = 0;
    cin >> n;

    string word;

    cin >> word;

    for(int i=0; i<n-1;i++){
        string new_word;
        cin >> new_word;

        if(check(word, new_word)){
            count += 1;
        }
    }

    cout << count << '\n';

    return 0;
}