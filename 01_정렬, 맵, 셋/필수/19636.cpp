#include <iostream>

using namespace std;

int weightChange(int weight, int energy_plus, int energy_base, int energy_act){
    weight += energy_plus - (energy_base + energy_act);
    return weight;
}

void diet1(int weight, int energy_plus, int energy_base, int energy_act, int day){
    for(int i=0; i<day; i++){
        weight = weightChange(weight, energy_plus, energy_base, energy_act);
        if ((weight<=0)||(energy_base<=0)){
            cout << "Danger Diet \n";
            return;
        }
    }
    cout << weight << ' ' << energy_base << '\n';
}

void diet2(int weight, int energy_plus, int energy_base, int energy_act, int day, int energy_diff){
    int base = energy_base;
    for(int i=0; i<day; i++){
        weight = weightChange(weight, energy_plus, energy_base, energy_act);
        if (abs(energy_plus - (energy_base + energy_act))>energy_diff){
            energy_base += floor((energy_plus - (energy_base + energy_act))/2.0) ; 
        }
        if ((weight<=0)||(energy_base<=0)){
            cout << "Danger Diet \n";
            return;
        }
    }

    if ((base-energy_base)>0){
        cout <<  weight <<' '<< energy_base <<' '<< "YOYO" << '\n';
    }
    else {
        cout <<  weight <<' '<< energy_base <<' '<< "NO" << '\n';
    }
}

int main(){
    int weight, energy_plus, energy_base, energy_act;
    int energy_diff;
    int day;

    cin >> weight >> energy_base >> energy_diff;
    cin >> day >> energy_plus >> energy_act;

    diet1(weight, energy_plus, energy_base, energy_act, day);
    diet2(weight, energy_plus, energy_base, energy_act, day, energy_diff);
    return 0;





}
