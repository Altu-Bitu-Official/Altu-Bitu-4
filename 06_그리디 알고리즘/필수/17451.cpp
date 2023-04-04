#include <iostream>
#include <cmath> //ceil()
#include <vector>

using namespace std;

/*
 * 힌트: 자료형마다 값의 범위가 정해져 있다는걸 명심하세요. 어디에서부터 속도를 확인하는 게 더 유리할까요?
 *
 * 마지막 행성부터 시작하여, 출발속도가 현재 행성의 필요속도의 배수면서도 증가하도록 만든다.
 */

int main()
{
    int n;
    // 들어오게 되는 값이 10^9 이하의 정수이므로 int 대신 double로 정의
    vector<double> planet;
    // 입력
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        double input; // 들어오게 되는 정수의 값이 10^9 이하이므로 int 대신 double로 정의
        cin >> input;
        planet.push_back(input);
    }

    // 연산
    double ans = 1;

    // 역순으로 속도가 작은 것부터 계산하여 처음속도를 계산하는 그리디 알고리즘 채택
    for (int i = n - 1; i >= 0; i--)
    {
        // ans: 지난 i에서 업데이트한 속도의 최솟값
        // +) ans(last_speed)값이 더 작을 때만 업데이트 해줘서 답이 틀렸었는데 ans(last_speed)값이 더 커도 업데이트 해줘야 함
        ans = ceil(ans / planet[i]) * planet[i];
    }

    // 출력
    cout << (long long)ans; // ans가 나올 수 있는 범위>10^9이므로 long long으로 변환
}