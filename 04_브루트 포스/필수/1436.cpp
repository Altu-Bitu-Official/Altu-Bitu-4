// 영화감독 숌

#include <iostream>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{   
    int n;
    cin >> n;
    set<int> s;
    for (int i=0; i<10; i++)
        for (int j=0; j<10; j++)
            for (int k=0; k<10; k++)
                for (int h=0; h<10; h++){
                    s.insert(i*pow(10,6) + j*pow(10,5) + k*pow(10,4) + h*pow(10,3) +666);
                    s.insert(i*pow(10,6) + j*pow(10,5) + k*pow(10,4) + h +6660);
                    s.insert(i*pow(10,6) + j*pow(10,5) + k*10 + h +66600);
                    s.insert(i*pow(10,6) + j*pow(10,2) + k*10 + h +666000);
                    s.insert(i*pow(10,3) + j*pow(10,2) + k*10 + h +6660000);
                }
    vector<int> v(s.begin(), s.end());
    cout << v[n-1];
    return 0;       
}