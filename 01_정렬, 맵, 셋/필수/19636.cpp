//
// Created by LG on 2023-02-21.
//
#include <iostream>
#include <cstdlib>

using namespace std;

int divideByTwo(int num){
    int q = 0;
    while(2*q-num > 0)
        q--;
    return q;
}

// 기초 대사량 변화 고려하지 않았을 때 체중
int Weight(int weight, int eat_before, int day, int eat_after, int move){
    weight -= abs(eat_after-(eat_before + move))*day;
    return weight;
}

// 기초 대사량 변화 고려했을 때 체중
int realWeight(int weight, int &eat_change, int day, int limit, int eat_after, int move){
    for(int i=0; i<day; i++){
        int decrease = eat_after-(eat_change + move);
        weight += decrease;
        if(abs(decrease) > limit) {
            eat_change += divideByTwo(decrease);
        }
    }
    return weight;
}


int main() {
    int weight, eat_before, limit, day, eat_after, move, eat_change;
    cin >> weight >> eat_before >> limit >> day >> eat_after >> move;
    eat_change = eat_before;

    int weight1 = Weight(weight, eat_before, day, eat_after, move);
    if(weight1 > 0){
        cout << weight1 << ' ' << eat_before << '\n';
    }
    else
        cout << "Danger Diet" << '\n';

    int weight2 = realWeight(weight, eat_change, day, limit, eat_after, move);
    if(weight2 > 0 && eat_change > 0){
        cout << weight2 << ' ' << eat_change << ' ';
        if(eat_change < eat_before)
            cout << "YOYO";
        else
            cout << "NO";
    }
    else
        cout << "Danger Diet";

}