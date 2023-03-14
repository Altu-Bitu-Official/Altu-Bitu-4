#include <iostream>
#include <vector>

using namespace std;


int main() {
   int n,k;
   cin >> n >> k;
   vector<char> wheel(n,'?');
   int s;
   char word;
   int index=0;

   for(int i=0; i<k; i++){

       cin >> s >> word;
       s = s%n;
       index = index - s;
       if(index < 0) {
           index = index + n;
       }

       if(wheel[index] != word && wheel[index] != '?'){ //돌렸을 때 다른 문자가 들어 있을 때는 '!'출력
           cout << "!\n";
           return 0;
       }
       else wheel[index] = word;
   }

   for(int i=0; i<n-1; i++){
       for(int j=i+1; j<n; j++){
           if(wheel[i]==wheel[j] && wheel[i]!='?'){
               cout << "!\n";
               return 0;
           }
       }
   }

   for(int i=n-1; i>=0; i--){
       cout<<wheel[index];
       index++;
       if(index == n){
           index = 0;
       }
   }

   return 0;
}