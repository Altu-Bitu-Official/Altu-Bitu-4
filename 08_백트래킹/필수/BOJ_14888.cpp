#include <iostream>

using namespace std;

int n;       // 수의 개수
int A[100];  // 수의 개수
int oper[4]; // 연산자의 개수 (+,-,*,/)

int mini = 1000000001;  // 최소 -10억
int maxi = -1000000001; // 최대 10억

void calc(int result, int cnt) // cnt가 n번이 되면 종료
{
    if (cnt == n) // 최대, 최소값의 바운더리 제한
    {
        if (result > maxi)
        {
            maxi = result;
        }
        if (result < mini)
        {
            mini = result;
        }
    }

    for (int i = 0; i < 4; i++)
    {
        if (oper[i] > 0)
        {              // 연산자가 남아 있을 경우
            oper[i]--; // 방금 하나 사용
            if (i == 0)
            { // 연산자 +
                calc(result + A[cnt], cnt + 1);
            }
            else if (i == 1)
            {
                calc(result - A[cnt], cnt + 1);
            }
            else if (i == 2)
            {
                calc(result * A[cnt], cnt + 1);
            }
            else
            {
                calc(result / A[cnt], cnt + 1);
            }
            oper[i]++; // 다른 연산자를 사용 -> 아까 --했던 연산자 개수를 늘려줌
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) // 수 사용자 정의
    {
        cin >> A[i];
    }
    for (int i = 0; i < 4; i++) // 연산자 개수 사용자정의
    {
        cin >> oper[i];
    }

    calc(A[0], 1);
    cout << maxi << endl;
    cout << mini;
}
