#include <iostream>
#include <set>

using namespace std;


int main() {
    int n,m,ans=0;
    string input;
    cin >>n>>m;
    set<string> s;
    set<string>::iterator iter;
    while(n--){
        cin >>  input;
        s.insert(input);
    }
    for(int i=0;i<m;i++){
        cin >>input;
        iter = s.find(input);
        if(iter!=s.end()){
            ans+=1;

        }

    }

    cout <<ans;
}
