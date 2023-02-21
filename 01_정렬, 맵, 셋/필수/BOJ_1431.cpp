#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
//비교함수
bool cmp (const string& a,  const string&b)
{
    //문자열 길이가 다를 경우 
    if (a.size() != b.size()) 
        return a.size() < b.size(); //문자열 길이가 증가하는 순서
    //문자열 길이가 같을 경우 
    else
    {
        int a_sum = 0 , b_sum = 0;
       
        for (int i=0 ; i< a.size();i++)  //문자열 a와 b는 서로 길이가 같음
        {
            if ('0'<= a[i] && a[i] <='9') //a 문자열 각각의 인덱스가 숫자일 경우
                a_sum += a[i] - '0';
            if ('0'<= b[i] && b[i]<='9') // b 문자열 각각의 인덱스가 숫자일 경우
                b_sum += b[i] - '0';

        }
        if(a_sum != b_sum) //(문자열 길이가 같을때) a합과 b합이 다르면
            return a_sum < b_sum; //합이 증가하는 순서
        
        else   //(문자열 길이가 같을때) a합과 b합이 같으면
            return a < b; //사전순으로 증가하는 순서

           

    }
}

int main()
{
    int n;
    cin >> n;
    string arr[50];

    for(int i=0; i< n;i++)
        cin >> arr[i];
    
    sort(arr,arr+n,cmp);
    
    for(int i=0; i< n;i++)
        cout << arr[i] << '\n';

    return 0;
}