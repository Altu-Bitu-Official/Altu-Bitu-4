#include <string>
#include <vector>

using namespace std;

string solution(string number, int k)
{ //[msd 정하기]
    string ans = "";
    int len = number.size() - k;
    while (k && ans.size() < len)
    {
        int max = number[0];
        int idx = 0;
        // 0~kth index 중 제일 큰 수하나 뽑고,
        for (int i = 0; i <= k; i++)
        {
            if (max < number[i])
            {
                max = number[i];
                idx = i;
            }
        }
        // 그 앞에 있는 애들 다 지우기
        ans += number[idx];
        number = number.substr(idx + 1);
        // 지운 수만큼 k 차감
        k -= idx;
    }
    if (ans.size() < len)
    {
        ans += number;
    }

    return ans;
}