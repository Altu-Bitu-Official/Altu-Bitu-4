#include <iostream>
#include <math.h>

using namespace std;

void consistentBMR(int weight, int bmr, int days, int energy, int activity)
{
    weight += days * (energy - (bmr + activity));
    if (weight <= 0)
    {
        cout << "Danger Diet" << '\n';
        return;
    }
    cout << weight << ' ' << bmr << '\n';
}

void changingBMR(int weight, int bmr, int T, int days, int energy, int activity)
{
    int wieght_change; //가독성을 위해 일일 몸무게변화 변수 지정
    int original_input = bmr;
    while (days--)
    {
        wieght_change = energy - (bmr + activity);
        weight += wieght_change;
        if (weight <= 0)
        {
            cout << "Danger Diet" << '\n';
            return;
        }
        if (abs(wieght_change) > T)
        {
            bmr += floor(double(wieght_change) / 2);
            if (bmr <= 0)
            {
                cout << "Danger Diet" << '\n';
                return;
            }
        }
    }
    cout << weight << ' ' << bmr << ' ';
    if (bmr < original_input)
        cout << "YOYO";
    else
        cout << "NO";
}

int main()
{
    int weight, bmr, T;         // 몸무게, 기초대사량, 변화역치
    int days, energy, activity; // 다이어트 기간, 섭취량, 활동대사량
    cin >> weight >> bmr >> T;
    cin >> days >> energy >> activity;

    consistentBMR(weight, bmr, days, energy, activity);  // 기초대사량 불변하는 케이스
    changingBMR(weight, bmr, T, days, energy, activity); // 기초대사량 변화 고려한 케이스
}
