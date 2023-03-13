#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int count = 0;

    if (N < 100) {
        cout << N;
    }
    else {
        count += 99;

        for (int n = 100; n <= N; n++) {
            int hun = n / 100;
            int ten = (n / 10) % 10;
            int one = n % 10;

            if (hun+one==2*ten) {
                count++;

            }
        }
        cout << count;
        

    }
    
    return 0;
}