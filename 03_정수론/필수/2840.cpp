// 행운의 바퀴

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, k, p;
    char q;
    int pt = 0; // 현재 화살표가 가리키는 위치
    
    cin >> n >> k;
    
    vector <char> s(n,'?');
    
    for (int i=0; i<k; i++){
        cin >> p >> q;
        pt = (pt + p)%n; // 위치 계산
        
        // 이미 값이 들어가있으면 상덕이가 종이에 적어놓은 내용 확인
        if (s[pt] != '?' && s[pt] != q){ 
            cout << '!';
            return 0;
        }
        else{
            s[pt] = q;
        }
    }
    for (int i=0; i<n; i++){
        cout << s[(pt-i+n)%n];
    }
    return 0;
}
