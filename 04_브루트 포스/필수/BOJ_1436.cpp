#include <iostream>
#include <string>
using namespace std;
int isContain666(int num) {
    string str = to_string(num);
    if (str.find("666") == string::npos) {
        return 1;
    }
    else {
        return 0;
    }

}
int main() {
    int n;
    cin >> n;

    int number = 0;
    while (1) {
        number++;
        if (isContain666(number)) {
            n--;
        }

        if (n <= 0) {
            break;
            
        }
    }
    cout << number;

}