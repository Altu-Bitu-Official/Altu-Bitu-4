#include <iostream>
#include <string>
using namespace std;

//두 단어를 비교해서 비슷한 단어면 1, 아니면 0을 반환한다.
//비슷한 단어이려면 두 단어가 같은 구성을 갖거나
//한문자만 추가,삭제,변환했을때 같아야 한다.
int cmpWord(string a, string b){
    if (a.size()>b.size())    {swap(a,b);}    //a가 b보다 길지 않은 문자열이 되도록 함
    int as = a.size(); int bs = b.size();
    int cnt = 0;    //a에 있는 문자 중 b에 없는 문자 개수 카운트
    
    //두 문자열의 길이차이가 2 이상이면 비슷한 단어 아님
    if (bs-as > 1)   {return 0;}
    
    //둘의 길이가 같거나, b가 a보다 한글자 더 길 때
    //a의 모든 문자를 b에서 찾아서 삭제
    for (auto ch:a){
        //a의 문자가 b에 없다면 cnt는 +1
        //a의 문자가 b에도 있다면 b에서 그 문자 삭제
        //cnt가 2 이상되면은 a와 b는 비슷한 단어 아님
        int num = b.find(ch);
        if (num == -1)    {cnt++;}
        else {b.erase(num,1);}
        if (cnt>1)  {return 0;}
    }
    
    //위의 과정이 끝난 후 b에 남은 문자가 2개 이상이면 비슷한 단어 아님
    if (b.size()>1) {
        return 0;
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;  //기준단어와 비교할 단어의 개수
    string st_word; //기준단어
    string cp_word; //기준단어와 비교할 단어
    int answ = 0;   //기준단어와 같은구성이거나 비슷한 단어의 개수

    cin >> n;
    cin >> st_word;
    for (int i=0; i<n-1; i++){
        cin >> cp_word;
        answ += cmpWord(st_word,cp_word);
    }
    cout << answ;

    return 0;
}