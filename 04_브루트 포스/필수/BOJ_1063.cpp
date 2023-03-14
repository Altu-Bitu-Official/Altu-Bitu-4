
#include<iostream>
#include<string>
 
#define MAX 51
using namespace std;
 
int N, Kx, Ky, Rx, Ry;
string Move[MAX];
 
void Input()
{
    char a;
    cin >> a >> Ky;
    Kx = a - 'A' + 1;
    cin >> a >> Ry;
    Rx = a - 'A' + 1;
 
    cout << "King = " << Kx << Ky << endl;
    cout << "Rock = " << Rx << Ry << endl;
 
    cin >> N;
 
    for (int i = 0; i < N; i++)
    {
        cin >> Move[i];
    }
 
    //for (int i = 0; i < N; i++) cout << Move[i] << endl;
}
 
bool SamePosition(int Kx, int Ky, int Rx, int Ry)
{
    if (Kx == Rx && Ky == Ry) return true;
    return false;
}
 
bool RangeCheck(int x, int y)
{
    if (x < 1 || y < 1 || x > 8 || y > 8) return false;    // 범위밖을 나가버리면 false를 반환
    return true;                                        // 아니면 true를 반환
}
 
void Movement()
{
    for (int i = 0; i < N; i++)
    {
        if (Move[i] == "R")
        {
            if (RangeCheck(Kx + 1, Ky))
            {
                Kx++;
                if (SamePosition(Kx, Ky, Rx, Ry))
                {
                    if (RangeCheck(Rx + 1, Ry)) Rx++;
                    else Kx--;
                }
            }
        }
        else if (Move[i] == "L")
        {
            if (RangeCheck(Kx - 1, Ky))
            {
                Kx--;
                if (SamePosition(Kx, Ky, Rx, Ry))
                {
                    if (RangeCheck(Rx - 1, Ry)) Rx--;
                    else Kx++;
                }
            }
        }
        else if (Move[i] == "B")
        {
            if (RangeCheck(Kx, Ky - 1))
            {
                Ky--;
                if (SamePosition(Kx, Ky, Rx, Ry))
                {
                    if (RangeCheck(Rx, Ry - 1)) Ry--;
                    else Ky++;
                }
            }
        }
        else if (Move[i] == "T")
        {
            if (RangeCheck(Kx, Ky + 1))
            {
                Ky++;
                if (SamePosition(Kx, Ky, Rx, Ry))
                {
                    if (RangeCheck(Rx, Ry + 1)) Ry++;
                    else Ky--;
                }
            }
        }
        else if (Move[i] == "RT")
        {
            if (RangeCheck(Kx + 1, Ky + 1))
            {
                Kx++;
                Ky++;
                if (SamePosition(Kx, Ky, Rx, Ry))
                {
                    if (RangeCheck(Rx + 1, Ry + 1))
                    {
                        Rx++;
                        Ry++;
                    }
                    else
                    {
                        Kx--;
                        Ky--;
                    }
                }
            }
        }
        else if (Move[i] == "LT")
        {
            if (RangeCheck(Kx - 1, Ky + 1))
            {
                Kx--;
                Ky++;
                if (SamePosition(Kx, Ky, Rx, Ry))
                {
                    if (RangeCheck(Rx - 1, Ry + 1))
                    {
                        Rx--;
                        Ry++;
                    }
                    else
                    {
                        Kx++;
                        Ky--;
                    }
                }
            }
        }
        else if (Move[i] == "RB")
        {
            if (RangeCheck(Kx + 1, Ky - 1))
            {
                Kx++;
                Ky--;
                if (SamePosition(Kx, Ky, Rx, Ry))
                {
                    if (RangeCheck(Rx + 1, Ry - 1))
                    {
                        Rx++;
                        Ry--;
                    }
                    else
                    {
                        Kx--;
                        Ky++;
                    }
                }
            }
        }
        else if (Move[i] == "LB")
        {
            if (RangeCheck(Kx - 1, Ky - 1))
            {
                Kx--;
                Ky--;
                if (SamePosition(Kx, Ky, Rx, Ry))
                {
                    if (RangeCheck(Rx - 1, Ry - 1))
                    {
                        Rx--;
                        Ry--;
                    }
                    else
                    {
                        Kx++;
                        Ky++;
                    }
                }
            }
        }
    }
    char Result_King = Kx + 'A' - 1;
    char Result_Rock = Rx + 'A' - 1;
    cout << Result_King << Ky << endl;
    cout << Result_Rock << Ry << endl;
}
 
void Solution()
{
    Movement();
}
 
void Solve()
{
    Input();
    Solution();
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    freopen("Input.txt", "r", stdin);
    Solve();
    return 0;
}