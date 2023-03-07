#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    // 입력
    int N, K;
    cin >> N >> K;

    queue<int> circle;  // 현재 서클 상태를 나타내는 큐 

    // 1부터 N까지 큐에 push
    int i = 1;
    while(i < N + 1)
    {
        circle.push(i);
        i++;
    }

    i=0; 

    cout << "<";
    // 큐가 빌 때까지 = 모든 사람이 제거될 때 까지 
    while(!circle.empty())
    {
        i++;
        // i가 K의 배수가 아니라면 큐의 front 원소를 큐의 가장 뒤에 push
        if(i%K != 0)
        {
            circle.push(circle.front());
        }
        // i가 K의 배수라면 출력
        else
        {
            cout << circle.front();
            if(circle.size() != 1)
            {
                cout << ", ";
            }
        }
        // 큐의 front 원소를 pop
        circle.pop();
    }
    cout << ">";
}