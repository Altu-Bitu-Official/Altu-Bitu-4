#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

//sort의 cmp함수는 return이 false로 반환되었을 때 두 값을 swap하게 되는 bool타입 함수
bool cmp(const string &serial1, const string &serial2){
    if(serial1.length() != serial2.length()){
        return serial1.length() < serial2.length();
    }
    else {
        int sum1=0, sum2=0;
        for(int i=0; i<serial1.size(); i++){
            if((serial1[i]>='1') && (serial1[i]<='9'))
                sum1 += serial1[i] - '0';
            if((serial2[i]>='1') && (serial2[i]<='9'))
                sum2 += serial2[i] - '0';
        }
        if(sum1 == sum2){
           return serial1 < serial2;
        }
        else
            return sum1 < sum2;
    }
}

int main() {
    int n;

    cin >> n;
    vector<string> serial;
    serial.assign(n,{});
    for (int i=0; i<n; i++){
        cin >>serial[i];
    }

    sort(serial.begin(),serial.end(),cmp);

    for(int k=0; k<n; k++){
        cout << serial[k] << "\n";
    }
    return 0;
}
