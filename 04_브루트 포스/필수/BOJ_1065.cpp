#include <iostream>
using namespace std;

int check(int n)
{                 // 셋째자리수 또는 1000인 경우 한수의 개수를 반환하는 함수
    int sum = 99; // 이미 셋째 자리 수이므로 100이전까지의 숫자들은 모두 한수

    for (int i = 100; i <= n; i++)
    {
        int first = i / 100;        // 백의 자릿수
        int second = (i / 10) % 10; // 십의 자릿수
        int third = i % 10;         // 일의 자릿수

        if ((first - second) == (second - third))
        {             // 한수인 경우
            sum += 1; // sum에 1추가
        }
    }
    return sum;
}

int main()
{
    int n;
    int sum = 0; // 한수의 개수
    cin >> n;    // 사용자입력

    if (n < 100)
    { // n이 두자리 수 일 경우 모든 수가 한수
        sum = n;
    }
    else
    { // n이 세자리 수 일 경우
        sum = check(n);
    }

    // 출력
    cout << sum;
}