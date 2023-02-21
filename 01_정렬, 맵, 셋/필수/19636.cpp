#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int w0, L0, t;        // 전체중, 기초대사량, 역치
    int D, input, output; // 기간, 섭취량, 대사량

    cin >> w0 >> L0 >> t;
    cin >> D >> input >> output;

    int w1 = w0;
    int w2 = w0;

    int L1 = L0;

    for (int i = 0; i < D; i++)
    {
        w1 += input - (L0 + output);
        w2 += input - (L1 + output);
        if (abs(input - (L1 + output)) > t)
            L1 += floor((input - (L1 + output)) / 2.0);
    }

    if (w1 <= 0)
        cout << "Danger Diet\n";
    else
        cout << w1 << " " << D << "\n";

    if (w2 <= 0 || L1 <= 0)
        cout << "Danger Diet\n";
    else
    {
        cout << w2 << " " << L1 << " ";
        if (D - L1 > 0)
            cout << "YOYO";
        else
            cout << "NO";
    }
}