/*필수*/
#include <iostream>
#include <string>

using namespace std;
int find666(int n)
{
    int num = 0;
    while (true)
    {
        for (int i = 666;; i++)
        {
            string str = to_string(i);
            for (int k = 0; k < str.size() - 2; k++)
            {
                if (str[k] == '6' && str[k + 1] == '6' && str[k + 2] == '6')
                {
                    num++;
                    if (num == n)
                    {
                        return i;
                    }
                    break;
                }
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    cout << find666(n);
    return 0;
}