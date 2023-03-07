//1431번
#include <iostream>
#include <algorithm> // sort() 사용하기 위함
using namespace std;

/* a != b 이면 짧은 순서대로 정렬
 * a와 b의 숫자부분의 합이 작은 순서대로 리턴
 * 두 가지로 비교 안되면 사전순으로 정렬
 *
 */

int sum(string a, int a_len) {
    int sum = 0;
    for(int i=0; i<a_len; i++)
        if(a[i] >= '0' && a[i] <= '9')
            sum += a[i] - '0';
    return sum;
}

int cmp(string a, string b){
    int a_len = a.length(), b_len = b.length();
    int a_sum = sum(a, a_len), b_sum = sum(b,b_len);

    if(a_len != b_len)
        return a_len < b_len;
    else
        if(a_sum != b_sum)
            return a_sum < b_sum;
        else
            return a<b;
}

int main() {
    int n;
    cin >> n;

    string num[n];
    for(int i=0; i<n; i++)
        cin >> num[i];
    sort(num, num+n, cmp);
    for(int i=0; i<n; i++)
        cout << num[i] << "\n";
    return 0;
}