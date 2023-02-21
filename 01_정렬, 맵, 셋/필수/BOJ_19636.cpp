#include <iostream>
#include <cmath> //abs, floor함수를 쓰기위해 필요한 헤더 파일

using namespace std;

int main()
{
    int w0, i0, t, d, i, a;
    cin >> w0 >> i0 >> t;
    cin >> d >> i >> a;
    int w1 = w0;
    int new_i0 = i0;
    for (int j= 0;j <d;j++)
        w0 += i - (i0 + a);
    if (w0 <= 0)
        cout << "Danger Diet\n";
    else
        cout << w0 << " " << i0 << '\n';
    
    for (int j= 0;j <d;j++)
    {
        w1 += i - (new_i0 + a);
        if (abs(i - (new_i0 + a)) > t)
            new_i0 += floor((i - (new_i0 + a)) / 2.0); 
    }

    if (w1 <= 0 || new_i0 <= 0)
        cout << "Danger Diet\n";
    else 
    {
        cout << w1 << " " << new_i0 << " ";
        if(i0 > new_i0) //이전과 이후의 기초대사량 비교
            cout << "YOYO";
        else    
            cout << "NO";
    }

    return 0;
}
