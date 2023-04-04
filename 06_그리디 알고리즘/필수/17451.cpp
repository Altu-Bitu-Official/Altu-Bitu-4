#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long getInitVel(vector<int> &vel)
{
    long long init_vel = vel.back();
    vel.pop_back();
    while (!vel.empty())
    {
        init_vel = (long long)ceil(init_vel / (double)vel.back()) * vel.back();
        vel.pop_back();
    }
    return init_vel;
}

int main()
{
    int n, v;
    cin >> n;
    vector<int> vel;
    while (n--)
    {
        cin >> v;
        vel.push_back(v);
    }

    cout << getInitVel(vel);
}