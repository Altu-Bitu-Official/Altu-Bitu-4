#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n; //입력받을 숫자
    cin >> n;
    vector<int> tripleSix;
    int i=666;
while(true){
    if(to_string(i).find("666")!= std::string::npos){
        tripleSix.push_back(i);
    }
    if(tripleSix.size()==n){
        break;
    }
    i++;
}
cout << tripleSix[n-1];

    return 0;
}