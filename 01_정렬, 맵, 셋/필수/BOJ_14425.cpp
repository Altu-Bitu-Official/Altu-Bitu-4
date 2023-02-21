#include <iostream>
#include <map>
#include <string>

using namespace std;

int main ()
{
    //입출력 속도 향상
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int n, m, cnt = 0;
    string n_str, m_str;

    map<string ,int> arr;   
    
    cin >> n >> m;

    for(int i = 0 ; i < n; i++)
    {
        cin >> n_str;
        arr[n_str] = 1; //n개의 arr[문자열]의 값을 1이라고 생각
    }

    while(m--)
    {
        cin >> m_str;
        if(arr[m_str]==1) // arr[비교하는 문자열]이 1이면 
        cnt++; // 이전 문자열과 같은 것이 존재하므로 +1하기
    }
    cout << cnt;
    return 0;
}