#include <iostream>
#include <algorithm> 
#include <string>
#include <vector>
#include <map>

using namespace std;


int main(void)
{
    int n, m, answer;     
    string s;  
    map <string, bool> M;

    //입력 
    cin >> n >> m; 

    for (int i=0; i<n; i++)
    {
        cin >>s;
        M[s] = true;
    }

    for (int i = 0; i <m; i++)
    {
        cin>>s;
        if(M[s]) answer ++;
    }

    //출력
    cout <<answer<< endl; 
   
    return 0;
}

