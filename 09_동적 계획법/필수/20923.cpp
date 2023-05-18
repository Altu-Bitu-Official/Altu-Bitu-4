#include <iostream>
#include <deque>

using namespace std;

int n;
deque<int> dodo;
deque<int> suyeon;
deque<int> ground_d;
deque<int> ground_s;

void set_ground(int count){
    int card;
    if (count%2 == 1){
        card = dodo.front();
        dodo.pop_front();
        ground_d.push_front(card);
    }
    else {
        card = suyeon.front();
        suyeon.pop_front();
        ground_s.push_front(card);
    }
}

int main(){
    int m;
    cin >> n >> m;

    for(int i=0; i<n; i++){
        int d, s;
        cin >> d >> s;
        dodo.push_front(d);
        suyeon.push_front(s);
    }

    int count = 0;

    while(count<m){
        count++;

        set_ground(count);

        if(dodo.empty() || suyeon.empty()){
            break;
        }

        if((ground_d.size() > 0 && ground_d.front()==5) || (ground_s.size()>0 && ground_s.front()==5)){
            int card;
            while(!ground_s.empty()){
                card = ground_s.back();
                ground_s.pop_back();
                dodo.push_back(card);
            }
            while(!ground_d.empty()){
                card = ground_d.back();
                ground_d.pop_back();
                dodo.push_back(card);
            }
        }

        else if(ground_d.size() > 0 && ground_s.size() > 0 && ground_d.front()+ground_s.front() == 5){
            int card;
            while(!ground_d.empty()){
                card = ground_d.back();
                ground_d.pop_back();
                suyeon.push_back(card);
            }
            while(!ground_s.empty()){
                card = ground_s.back();
                ground_s.pop_back();
                suyeon.push_back(card);
            }
        }
        
        if(dodo.empty() || suyeon.empty()){
            break;
        }

    }
    if (dodo.size() == suyeon.size()){
        cout << "dosu";
    }
    else if (dodo.size() < suyeon.size()){
        cout << "su";
    }
    else{
        cout << "do";
    }




    return 0;
}