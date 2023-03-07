#include <iostream>
#include <string>



using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string a,b;
    cin >> a >> b;

    if(a.length()<b.length()){
        swap(a,b);
    }
    //이제 a가 더 길도록 됨
    int al=a.length(); int bl=b.length();
    string t="";
    if(al!=bl){
        
        for(int i=0;i<al-bl;i++){
            t+="0";
        }
        b=t+b;//b+=t; 이렇게하면 안됨! t를 앞에붙여야
    
    }

    int n1, n2, sum;
    int up=0;//올림수
    string result="";
    for(int i=al-1;i>=0;i--){
        n1=a[i]-'0'; n2=b[i]-'0';
        sum=n1+n2+up;
        if(sum>9){
            up=1;
            result+=sum%10+'0';
        }
        else{
            result+=sum+'0';
            up=0;
        }
    }
    if(up==1) result+="1";

    for(int i=result.length()-1;i>=0;i--){
        cout << result[i];
    }

    

}