#include <iostream>
#include <map>
#include <queue>

using namespace std;

map<int, int> count;
queue<int> sequence;

int max_size=0;

void check(int m, int key){
    if(count[key]<m){
        count[key]++;
        sequence.push(key);
        if(max_size<sequence.size()){
            max_size = sequence.size();
        }
    }
    else{
        while(sequence.front()!=key){
            int pop_key = sequence.front();
            sequence.pop();
            count[pop_key]--;

        }
        sequence.pop();
        sequence.push(key);
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    int key;

    for (int i=0; i<n; i++){
        cin >> key;
        check(m, key);
    }

    cout << max_size;

    return 0;
}