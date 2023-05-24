#include <iostream>
#include <vector>

using namespace std;

int count[26];

void check(int k, int alph, int index, vector<vector<int>> &sequence){
    sequence[alph].push_back(index);
    count[alph]++;

    return;
}

int main(){
    int n;
    cin >> n;

    int k[n];
    int not_fit;
    int max_size;
    int min_size;
    string w[n];
    int size;

    string W;
    int K;

    for(int i=0; i<n; i++){
        cin >> w[i] >> k[i];
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<26; j++){
            count[j] = 0;
        }
        vector<vector<int>> sequence(26);
      
        max_size = 0;
        min_size = 10001;
        not_fit = 0;

        W = w[i];
        K = k[i];
        
      
        for(int j=0; j<W.length(); j++){
            int alph = W[j] - 97;
            check(K, alph, j, sequence);
        }
        for(int j=0; j<26; j++){
            if(count[j]<K){
                not_fit++;
                continue;
            }
            else {
                for(int t=0; t<sequence[j].size() - (K-1); t++){
                    size = sequence[j][t+K-1] - sequence[j][t] + 1;
                    if(size > max_size){
                        max_size = size;
                    }
                    if(size < min_size){
                        min_size = size;
                    }
                }
            }
        }

        if(not_fit==26){
            cout << -1 << '\n';
        }
        else{
            cout << min_size << " " << max_size << '\n';
        }
    }
    
    return 0;
}
