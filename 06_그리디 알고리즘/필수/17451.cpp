// 평행 우주

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    long long speed;
    
    cin >> n;
    vector<int> planet(n-1);
    for (int i=0; i<n-1; i++)
        cin >> planet[i];
    cin >> speed; 
    
    for (int i = n-2; i>=0; i--){
        if (speed < planet[i])
            speed = planet[i];
        else if (speed % planet[i] != 0)        
            speed = planet[i]*((speed/planet[i]) + 1);
    }
    cout << speed;
    
    return 0;
}