#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int check(string fw, string nw, vector<int> alp){
    int n = nw.size();
    int f = fw.size();
    //두 단어의 길이 차이가 2 이상이면 종료
    if(abs(n-f) > 1){
        return 0;
    }
    //문자 비교
    for(char i : nw){
        alp[i-'A']--;
    }

    int sum = 0;
    int m = 0;
    int p = 0;
    
    for(int i=0; i<30; i++){
        sum += alp[i];

        //2이상 차이나면
        if(alp[i] < -1 || alp[i] > 1){
            return 0;
        }
        
        if(alp[i] == -1){
            m++;
        }
        else if(alp[i] == 1){
            p++;
        }

        //차이나는 문자가 여러개 존재하면
        if(m > 1 || p > 1){
            return 0;
        }
    }
    //같은 구성이면
    if(sum == 0){
        return 1; 
    }
    //비슷한 단어이면
    if(p == 1 || m == 1){
        return 1;
    }
}

int main()
{
    int n;
    int sum = 0;
    string fw, nw;

    cin >> n;
    cin >> fw;

    vector<int> alp(30);
    
    //첫 단어에 존재하는 알파벳 분석
    for(char i : fw){
        alp[i-'A']++;
    }
    //첫 단어 제외
    n--;

    while(n--){
        cin >> nw;
        //비슷한 단어 개수 체크
        sum += check(fw, nw, alp);
    }

    cout << sum;
}