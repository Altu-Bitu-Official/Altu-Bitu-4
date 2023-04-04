#include<iostream>
#include <vector>

using namespace std;

int main()
{
    string number;
    int k;
    cin >> number >> k;
    
  
    int real_size = number.size() - k;
    //vector<string> a(real_size);
    int start_idx = 0;
 string answer = "";
    for(int i=0;i<real_size;i++)//0     1        2      3      4
    {
        char max_value = number[start_idx];
        int max_idx = start_idx;
        int j;
        for(j= start_idx ;j<= k+i ;j++)//0~3
        {
            if (max_value < number[j])
            {
                max_value = number[j];
                max_idx = j;
            }
        }
        //a.push_back(number[j]);
      answer+=max_value;
        start_idx = max_idx + 1;//중요


    }

cout << answer;
   /* for(int i=0;i<a.size();i++)
    {
        cout << a[i];
    }*/
    return 0;
}