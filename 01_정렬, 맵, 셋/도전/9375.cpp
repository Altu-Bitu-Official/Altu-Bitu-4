#include <iostream>
#include <map>
#include <set>
using namespace std;



int main() {
    int t, n;
    string input1,input2;
    cin >> t;


    while (t--) {
        int ans=1;
        map<string,int> clothes;
        set<string> s;
        cin >> n;
        while(n--){
            cin >>input1;
            cin >>input2;
            if(s.find(input2)!=s.end()){
                clothes[input2]++;

            }else{
                s.insert(input2);
                clothes[input2]++;
            }

        }
        for(auto iter=clothes.begin();iter!=clothes.end();iter++){
            ans*= (iter->second+1);
        }
        cout <<ans-1<<"\n";

    }

}
