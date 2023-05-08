#include <iostream>
#include <algorithm>

using namespace std;

int card[500001]; //숫자 카드에 적혀있는 정수 저장
int findCard[500001]; //가지고 있는건지 아닌건지 판단용용


void binarySearch(int n, int k)
{
    int left = 0;
    int right = n-1;
 
    while(left<=right){
        int mid = (left+right)/2;
        if(card[mid]==k){
            cout<<"1"<<" ";
            return;
        }else{
            if(card[mid]>k){
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
    }
    cout<<"0"<<" ";
}

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(NULL);
    
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>card[i];
    }
    
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>findCard[i];
    }
    
    sort(card,card+n); //정렬
    
    for(int i=0; i<m; i++){
        binarySearch(n,findCard[i]);
    }
    return 0;
}