#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// int getCommonDivisor(int a, int b)
// {
//     for (int i = a; i > 0; i--)
//     { // a와 b의 공약수가 될 수는 a이하, 최대공약수이므로 큰 것부터 시작해서 return
//         if (a % i == 0 && b % i == 0)
//         {
//             return i;
//         }
//     }
//     return -1;
// }

int Euclidean(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    return Euclidean(b % a, a);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int first_numerator, first_denominator, second_numerator, second_denominator; // 분자 분모
    cin >> first_numerator >> first_denominator;
    cin >> second_numerator >> second_denominator;
    int mulitple_sum = first_numerator * second_denominator + first_denominator * second_numerator;
    int mutiple_of_denominators = first_denominator * second_denominator;
    // 이제 multiple_sum과 first_denominator*second denominator의 최대공약수로 나누어주면 됨

    int greatest_common_divisor = Euclidean(min(mulitple_sum, mutiple_of_denominators), max(mulitple_sum, mutiple_of_denominators));
    int final_numerator, final_denominator;
    final_numerator = mulitple_sum / greatest_common_divisor;
    final_denominator = mutiple_of_denominators / greatest_common_divisor;
    cout << final_numerator << " " << final_denominator;
    return 0;
}