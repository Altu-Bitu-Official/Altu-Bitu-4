#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

int searchCards(int left, int right, vector<int>& cards, int check){
    int mid;
    while(left <= right){
        mid = (left+right)/2;
        if(cards[mid] == check){
            return 1;
        }
        else if(cards[mid] > check){
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, check;

    cin >> n;
    vector<int> cards(n, 0);
    for(int i=0; i<n; i++){
        cin >> cards[i];
    }

    sort(cards.begin(), cards.end());

    cin >> m;
    for(int i=0; i<m; i++){
        cin >> check;
        cout << searchCards(0, n-1, cards, check) << " ";
    }
    return 0;
}