#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int n,m,b;
    int ground_height;
    int t  = 2147483647;
    int input[500][500];
    cin >> n >> m>> b;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> input[i][j];
        }
    }

    for (int h=0;h<=256;h++)
    {
        int remove = 0;
        int add =0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int height = input[i][j]-h;
                if(height > 0)
                {
                    remove+=height;
                }
                if(height < 0)
                {
                    add -= height;
                }
            }
        }

        if(b>= add - remove)
        {
            int time = remove * 2 +add * 1;
            if (t>=time)
            {
                t=time;
                ground_height = h;
            }
        }
    }

    cout << t  << ' '<< ground_height;

    return 0;
}