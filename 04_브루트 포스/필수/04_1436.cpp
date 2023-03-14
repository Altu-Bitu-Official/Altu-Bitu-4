#include <iostream>
#include <string>

using namespace std;


int main() {
    int n;
    cin >> n;

    int a = 666;
    string s;
    while(n){
        s=to_string(a);
        if(s.find("666") != -1){
            n -= 1;
        }
        a += 1;
    }

    cout << s << '\n';


    return 0;
}
