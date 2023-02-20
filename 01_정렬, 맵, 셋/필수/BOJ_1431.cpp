#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(string s1, string s2){
    int sum1 = 0, sum2 = 0;
    if (s1.length() != s2.length()) {
        return s1.length() < s2.length();
    }
    for (int i = 0; i < s1. length(); i++) {
        if (isdigit(s1[i])) sum1+= s1[i] - '0';
        if (isdigit(s2[i])) sum2+= s2[i] - '0';
    }
    // 질문 : sum1, sum2는 s1과 s2에서 값을 더해온다는 것을 빼면 s1, s2와 완전히 별개의 변수인데, sum1< sum2라는 식이 어떻게 s1과 s2가 정렬되도록 하는 것인지 궁금합니다. (어쩌다 보니 제대로 작동하는데 원리를 모르겠습니다.ㅜㅜ)
    if (sum1 != sum2) {
        return sum1 < sum2;
    }
    return s1 < s2;
}


int main() {
    int n;
    cin >> n;
    vector<string> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    

    sort(arr.begin(), arr.end(), comp);

    for (int i = 0; i < n; i++) cout << arr[i] << "\n";
}
