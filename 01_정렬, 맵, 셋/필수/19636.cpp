#include <iostream>
#include <cmath>

using namespace std;

void calc(int weight, int basic_meta, int threshold, int day, int energy_in, int energy_out) {
    int next_weight = weight;

    int diet_weight = weight;
    int diet_meta = basic_meta;

    while (day--) { // 기초 대사량 변화 X
        int next_delta = energy_in - (basic_meta + energy_out);
        int diet_delta = energy_in - (diet_meta + energy_out);
        next_weight += next_delta;
        diet_weight += diet_delta;

        if (abs(diet_delta) > threshold) {
            diet_meta += (floor)((energy_in - (diet_meta + energy_out)) / 2.0);
        }
    }

    if (next_weight <= 0 || basic_meta <= 0) {
        cout << "Danger Diet\n";
    } else {
        cout << next_weight << " " << basic_meta << "\n";
    }

    if (diet_weight <= 0 || basic_meta <= 0 || diet_meta <= 0) {
        cout << "Danger Diet";
    } else {
        cout << diet_weight << " " << diet_meta;
        if (diet_meta < basic_meta) {
            cout << " YOYO";
        } else {
            cout << " NO";
        }
    }
}

int main() {
    int weight; //몸무게
    int basic_meta; //일일 기초 대사량
    int threshold; //역치
    int day;
    int energy_in, energy_out;

    cin >> weight >> basic_meta >> threshold; //입력 #1
    cin >> day >> energy_in >> energy_out; //입력 #2

    calc(weight, basic_meta, threshold, day, energy_in, energy_out);//계산 및 출력

    return 0;
}