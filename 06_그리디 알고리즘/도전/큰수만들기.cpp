#include <string>
#include <vector>
#include <algorithm>
#include "iostream"

using namespace std;

string solution(string number, int k) {
    string answer;
    int location = -1, count = k;
    vector<int> answer_loc;

    while (count > 0) {
        if (count >= number.size() - (location + 1)) {
            // count = number.size() - (location +1);
            for (int i = 0; i < answer_loc.size(); i++) {
                answer.push_back(number[answer_loc[i]]);
            }
            return answer;
        }

        char tmp = 0;
        for (int i = location + 1, j = 0; j < count + 1; i++, j++) {
            if (tmp < number[i]) {
                tmp = number[i];
                location = i;
            }
        }
        count = k - location + answer_loc.size();
        answer_loc.push_back(location);
    }

    for (int i = 0; i < answer_loc.size(); i++) {
        answer.push_back(number[answer_loc[i]]);
    }
    for (int i = answer_loc[answer_loc.size() - 1] + 1, j = 0;
         j < number.size() - answer_loc[answer_loc.size() - 1] - 1; i++, j++) {
        answer.push_back(number[i]);
    }
    return answer;
}

int main() {
    string input;
    int k;
    cin >> input >> k;
    cout << solution(input, k);
}