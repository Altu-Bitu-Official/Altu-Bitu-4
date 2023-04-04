#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string s;
    int alp[26] = {0,};
    cin >> s;

    if(s.length()==1){
        cout << s;
        return 0;
    }

    for(int i=0;i<s.length();i++){
        alp[s[i]-'A']++;
    }

    int middle = -1;
    int check_odd = 0;
    for(int i=0;i<26;i++){
        if(alp[i]%2!=0){
            middle = i;
            alp[i]--;
            check_odd++;
        }
        if(check_odd > 1){
            cout << "I'm Sorry Hansoo";
            return 0;
        }
    }

    int count = 0;
    string front = "";
    for(int i=0;i<26;i++){
        if(alp[i]%2==0 && alp[i]!=0){
            for(int j=0;j<alp[i]/2;j++){
                //cout << 'A'+i <<" ";
                front+='A'+i;
                count++;
            }
            if(count==s.length()/2){
                break;
            }
        }
    }

    cout << front;

    if(middle!=-1){
        char m = 'A'+middle;
        cout << m;
    }
    reverse(front.begin(), front.end());
    cout << front;

    return 0;
}