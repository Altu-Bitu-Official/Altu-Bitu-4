#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int movie_num;
    int count = 0;
    string num_apocalypase = "666";
    for (int i = 666; i < 10000000; i++)
    {
        string k = to_string(i);

        k.find(num_apocalypase);
        if (!(k.find(num_apocalypase) == string::npos))
        {
            count++;
        }

        if (count == n)
        {
            movie_num = i;
            break;
        }
    }

    cout << movie_num;
    return 0;
}