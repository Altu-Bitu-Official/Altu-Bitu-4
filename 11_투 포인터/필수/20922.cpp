#include "iostream"
#include "vector"
#include "map"

using namespace std;

int getSequence(int k, vector<int> numbers){
    int start=0, end=0;
    int length=0;
    map<int, int> n_count;

    while(end < numbers.size()){
        n_count[numbers[end]]++;

        if(n_count[numbers[end]] > k){
            while (n_count[numbers[end]] > k) {
                n_count[numbers[start]]--;
                start++;
            }
        }
        length = (length > (end - start + 1)) ? length : (end - start +1);
        end++;
    }
    return length;
}

int main(){
    int n, k;
    vector<int> numbers;

    cin >> n >> k;
    numbers.assign(n, 0);

    for(int i=0; i<n; i++){
        cin >> numbers[i];
    }
    cout << getSequence(k, numbers);
}