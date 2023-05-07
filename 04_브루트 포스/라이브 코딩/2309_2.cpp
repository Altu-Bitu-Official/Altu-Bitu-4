// 일곱 난쟁이

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n = 9, sum_height = 0, num;
    vector<int> s;
    
    while (n--){
        cin >> num;
        s.push_back(num);
        sum_height += num;
    }
    sort(s.begin(), s.end());
    
    for (int i=0; i<8; i++)
        for (int j = i+1; j<9; j++){
            if (sum_height - s[i] - s[j] == 100){
                for (int k = 0; k<9; k++)
                    if (k != i && k != j)
                        cout << s[k] << '\n';
                return 0;
            }
        }
}