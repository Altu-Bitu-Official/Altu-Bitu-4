#include <iostream>

using namespace std;

#define MAX 1000000 // 최대수를 상수로 설정
int arr[MAX] = {0}; // 0으로 초기화, 소수를 저장할 정수배열

void makePrime()
{ // 소수를 구하는 함수
    for (int i = 2; i * i <= MAX; i++)
    { // 에라토스테네스의 체 이용
        if (arr[i] == 0)
        {
            for (int j = i * i; j < MAX; j += i)
            {
                arr[j] = 1;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); // 시간단축
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    makePrime(); // 소수배열 생성

    while (1)
    {
        cin >> n; // 사용자 입력
        if (n == 0)
        {
            break;
        } // 0입력시 종료

        bool imp = false; // 소수의 합으로 나타낼 수 업는 경우를 담은 변수

        for (int a = 3; a <= n; arr[n - a] == 0)
        { // a는 3부터 시작하여 홀수이기에 2씩 더해가며 a,b의 소수여부 체크
            cout << n << "= " << a << "+" << n - a << "\n";
            imp = true; // 조건을 만족하는 a,b가 존재
            break;
        }
        if (!imp)
        { // n = a + b 인 a, b 가 존재하면
            cout << "Goldbach's conjecture is wrong.\n";
        }
        return 0;
    }

    return 0;
}