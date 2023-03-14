#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int w, num , t, day, d_input, d_output;

    cin >> w >> num>> t;
    cin >> day >> d_input >> d_output;

    int w1 = w;
    int w2 = w;

    int num2 = num;

    for (int i=0; i<day; i++){
        w1 += d_input - (num + d_output);
        w2 += d_input - (num2 + d_output);
        if (abs(d_input - (num2 + d_output)) > t)
            num2 += floor((d_input - (num2+d_output))/2.0);
    }

    if (w1 <= 0)
        cout << "Danger Diet\n";
    else
        cout << w1 << " " << num << "\n";

    if (w2 <= 0 || num2 <= 0)
        cout << "Danger Diet\n";
    else{
        cout << w2 << " " << num2 << " ";
        if (num - num2 > 0) 
            cout << "YOYO";
        else
            cout << "NO";
    }
}