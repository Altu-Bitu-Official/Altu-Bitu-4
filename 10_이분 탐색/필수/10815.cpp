#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int binarySearch(int left, int right, int key,vector<int>& card){
    while(left<=right){
        int mid =(left+right)/2;
        if(card[mid] ==key){
            return 1;
        }
        else if(card[mid]>key){
            right = mid -1;
        }else{
            left = mid+1;
        }
    }
    return 0;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(NULL);
    int n,m,key;
    cin >>n;
    vector <int> card (n,0);
    for(int i=0;i<n;i++){
        cin >>card[i];
    }
    sort(card.begin(),card.end());

    cin >>m;
    while(m--){
        cin >>key;
        cout <<binarySearch(0,n-1,key,card)<<" ";
    }

}