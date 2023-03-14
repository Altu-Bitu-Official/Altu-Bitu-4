#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    string num = "666";

    while(n) {
        if (num.find("666") != string::npos) {
            n--;
        }

        if(n==0){
            break;
        }

        int temp = stoi(num);
        temp++;
        num = to_string(temp);
    }

    cout << num;

}