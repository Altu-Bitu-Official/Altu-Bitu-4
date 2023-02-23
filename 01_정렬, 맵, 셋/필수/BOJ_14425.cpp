#include <iostream>
#include <map>
#include <string>
//#include <set>
// set::find 함수 이용 키값존재하면 해당 iterator, 존재하지않으면 set::end 반환
//set은 이진트리구조를 사용하므로 원소의 시간 복잡도가 O(log2n)
using namespace std;

int main ()
{
    //입출력 속도 향상
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int n, m, cnt = 0;
    string n_str, m_str;

    map<string ,int> arr;   
    //set<string> s;
    
    cin >> n >> m;

    for(int i = 0 ; i < n; i++)
    {
        cin >> n_str;
        arr[n_str] = 1; //n개의 arr[문자열]의 값을 1이라고 생각
    }
    /*
    while (n--)
    {
        cin >> n_str;
        s.insert(n_str);
    }
    */

    while(m--)
    {
        cin >> m_str;
        if(arr[m_str]==1) // arr[비교하는 문자열]이 1이면 //if(arr[m_str])과 같은 의미!
        {
            cnt++; // 이전 문자열과 같은 것이 존재하므로 +1하기
        }
    }
    /*
    while (m--)
    {
        cin >> n_str;
        if(s.find(n_str) != s.end())
        {
            cnt++;
        }
        // cnt += s.count(n_str);
    }
    */
    cout << cnt;
    return 0;
}