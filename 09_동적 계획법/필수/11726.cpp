#include <iostream>

using namespace std;
 
int main(void)
{
    ios_base::sync_with_stdio();
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    int rect_num[n];

    rect_num[1] = 1;
    rect_num[2] = 2;

    for(int i=3; i<=n; i++){
        //2*i 크기의 직사각형을 채울수 있는 방법의 수는 2*(i-1)을 채우고 
        //너비가1인 사각형을 더하는 것과 2*(i-2)를 채우고 너비가 2인 막대 두개를 채우는 방법이 있음
        rect_num[i] = (rect_num[i-1]+rect_num[i-2])%10007; 
    }

    cout << rect_num[n];

 
    return 0;
}
