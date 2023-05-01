#include <iostream>
#include <deque>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    deque<int> dd;
    deque<int> sy;
    deque<int> d_gr;
    deque<int> s_gr;

    //초기 카드 더미 세팅
    for(int i=0;i<n;++i){
        int tmp;
        cin >> tmp;
        dd.push_front(tmp);
        cin >> tmp;
        sy.push_front(tmp);
    }
    int flag=0;//0이면 도도, 1이면 수연

    //승부
    for(int i=0;i<m;++i){
        
        if(flag==0){//도도차례
            d_gr.push_front(dd.front());
            dd.pop_front();
            if(dd.empty()){
                cout << "su"<< '\n';
                return 0;
            }
        }
        else{//수연이차례
            s_gr.push_front(sy.front());
            sy.pop_front();
            if(sy.empty()){
                cout << "do" << '\n';
                return 0;
            }
        }


        if((d_gr.size()&&d_gr.front()==5)||(s_gr.size()&&s_gr.front()==5)){//도도가 종을 치고 
            while(s_gr.size()){//수연이의 그라운드더미를 합치고
                dd.push_back(s_gr.back());
                s_gr.pop_back();
            }
            while(d_gr.size()){//도도의 것도 합친다
                dd.push_back(d_gr.back());
                d_gr.pop_back();
            }
        }
        
        if(d_gr.size()&&s_gr.size()&&d_gr.front()+s_gr.front()==5){//수연이가 종을 치고 
            while(d_gr.size()){//도도의 그라운드더미를 합치고
                sy.push_back(d_gr.back());
                d_gr.pop_back();
            }
            while(s_gr.size()){//수연이의 것도 합친다
                sy.push_back(s_gr.back());
                s_gr.pop_back();
            }
        }

        flag=1-flag;

        
    }
    if(dd.size()>sy.size()){
        cout << "do"<< '\n';
    }
    else if(dd.size()<sy.size()){
        cout << "su" << '\n';
    }
    else{
        cout << "dosu"<<'\n';
    }
    return 0;
}