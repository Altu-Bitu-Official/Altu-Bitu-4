#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k;
    queue<int> q;
    
    cin >> n >> k;  //입력 - n명의 사람, k번째 사람 제거
    for (int i=1; i<=n; i++) {q.push(i);}   //1부터 n까지의 숫자 순서대로 a에 넣기
    int answ[n];    //출력할 배열

    for (int i=0; i<n; i++){    //0부터 n까지 n번 반복
        for (int j=1; j<k; j++){    //1부터 (k-1)까지 k-1번 반복
            q.push(q.front());      //원형 테이블
            q.pop();
        }
        answ[i] = q.front();    //k 번째 수 answ에 저장하고
        q.pop();    //q 에서 뺌
    }
    
    //출력
    cout << '<' <<answ[0];
    for (int i=1;i<n;i++)   cout<<", "<<answ[i];
    cout << ">\n";

    return 0;
}