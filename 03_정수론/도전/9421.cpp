#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

queue<int> getPrimes(int range)
{
    queue<int> primes;
    vector<bool> is_prime(range + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i <= sqrt(range); i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= range; j += i)
            {
                is_prime[j] = false;
            }
        }
    }

    // 범위 내 소수 모아놓은 array 만들기
    for (int i = 2; i <= range; i++)
    {
        if (is_prime[i])
        {
            primes.push(i);
        }
    }
    return primes;
}

queue<int> getAnswer(queue<int> &primes)
{
    int s = primes.size();
    string number;

    for (int i = 0; i < s; i++)
    {
        vector<int> q;
        q.push_back(primes.front());

        while (true)
        {
            number = to_string(q.back());
            int sum_of_digit = 0;
            for (int j = 0; j < number.length(); j++)
            {
                sum_of_digit += pow(number[j] - '0', 2);
            }
            if (sum_of_digit == 1)
            {
                primes.push(primes.front());
                primes.pop();
                break;
            }

            // 각 자리수의 제곱합의 패턴이 반복되는지 확인
            else if (find(q.begin(), q.end(), sum_of_digit) != q.end())
            {
                primes.pop();
                break;
            }
            else
            {
                q.push_back(sum_of_digit);
            }
        }
    }
    return primes;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int range;
    queue<int> primes, answer;

    cin >> range;

    primes = getPrimes(range);
    answer = getAnswer(primes);

    while (!answer.empty())
    {
        cout << answer.front() << '\n';
        answer.pop();
    }
}