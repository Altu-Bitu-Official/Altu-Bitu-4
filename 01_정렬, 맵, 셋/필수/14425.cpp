#include <iostream>
#include <set>

using namespace std;

int main() {
    int n, m;
    int result=0;
    string input;

    cin >> n >> m;

    set<string> s;

    for(int i=0; i<n; i++) {
        cin >> input;
        s.insert(input);
    }

    for(int i=0; i<m; i++) {
        cin >> input;
        //set.find(값) 했을 때 값 찾지 못하면 end() 반환함
        if(s.find(input)!=s.end()) {
            result++;
        }
    }

    cout << result;

    return 0;
}
