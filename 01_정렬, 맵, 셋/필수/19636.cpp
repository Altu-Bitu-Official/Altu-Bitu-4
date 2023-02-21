#include <iostream>
#include <math.h>

using namespace std;

void consistentBMR(int weight, int bmr, int days, int energy, int activity)
{
    int wieght_change = energy - (bmr + activity);
    for (int i = 0; i < days; i++)
    {
        weight += wieght_change;
        if (weight <= 0)
        {
            cout << "Danger Diet" << '\n';
            return;
        }
    }
    cout << weight << ' ' << bmr << '\n';
}

void changingBMR(int weight, int bmr, int T, int days, int energy, int activity)
{
    int wieght_change;
    int original_input = bmr;
    for (int i = 0; i < days; i++)
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
    int weight, bmr, T;
    int days, energy, activity;
    cin >> weight >> bmr >> T;
    cin >> days >> energy >> activity;

    consistentBMR(weight, bmr, days, energy, activity);
    changingBMR(weight, bmr, T, days, energy, activity);
}
