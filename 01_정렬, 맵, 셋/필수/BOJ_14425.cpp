#include <iostream>
#include <map>
using namespace std;

int main() {
    
    //입력
    int n, m;
    int count = 0;
    cin >> n >> m;
    string str;
    map<string, bool> stu;
    for(int i=0; i<n; i++){
        cin >> str;
        stu.insert({str, true});
        //insert{key, value}
    }
    for(int i=0; i<m; i++){
        cin >> str;
        if(stu[str]==true){
            count++;
        }
    }
    //출력
    cout << count;
    
    return 0;
}