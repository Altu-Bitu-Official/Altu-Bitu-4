#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int before_weight, before_bmr, threshold;
    int duration, intake, activity;
    int sum;

    cin >> before_weight >> before_bmr >> threshold;
    cin >> duration >> intake >> activity;

    int after_weight=before_weight;
    before_weight+=(intake-before_bmr-activity)*duration;

    int after_bmr=before_bmr;

    for(int j=0; j<duration; j++) {
        sum=(intake-after_bmr-activity);
        after_weight+=sum;

        if(abs(sum)>threshold) {
            after_bmr+=floor(sum/2.0);
        }
    }

    if (before_weight<=0) {
        cout << "Danger Diet\n";
    } else {
        cout << before_weight << " " << before_bmr << "\n";
    }

    if (after_weight<=0 || after_bmr<=0) {
        cout << "Danger Diet\n";
    } else {
        cout << after_weight << " " << after_bmr << " ";

        if(before_bmr>after_bmr) {
            cout << "YOYO";
        } else {
            cout << "NO";
        }
    }


    return 0;
}