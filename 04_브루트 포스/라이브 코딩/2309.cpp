// 일곱 난쟁이

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int nanjaengi(vector<int> s){
    sort(s.begin(), s.end());
    int sum = accumulate(s.begin(), s.end(), 0);
    for (int i=0; i<8; i++)
        for (int j = i+1; j<9; j++)
            if (sum-s[i]-s[j] == 100){
                for (int h=0; h<9; h++){
                    if (h == i | h == j)
                        continue;
                    cout << s[h] << '\n';
                }
                return 0;
            }
}

int main()
{
    int k;
    vector<int> s;
    for (int i=0; i<9; i++){
        cin >> k;
        s.push_back(k);
    }
    nanjaengi(s);
    return 0;
}