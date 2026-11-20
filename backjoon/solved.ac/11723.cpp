#include <iostream>
#include <string.h>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<sstream>
#include<map>
using namespace std;

map<int,int> number;

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);

    

    string order;
    int m;
    cin>>m;
    int ordn;
    for(int i=0;i<m;i++){
        cin>>order;
        if(order=="add"){
            cin>>ordn;
            number[ordn]=1;
        }
        else if(order=="remove"){
            cin>>ordn;
            number.erase(ordn);
        }
        else if(order=="check"){
            cin>>ordn;
            if(number.find(ordn)!=number.end()){
                cout<<1<<'\n';
            }
            else cout<<0<<'\n';
        }
        else if(order=="toggle"){
            cin>>ordn;
            if(number.find(ordn)==number.end()){
                number[ordn]=1;
            }
            else number.erase(ordn);
        }
        else if(order=="all"){
            for(int i=1;i<=20;i++){
                number[i]=1;
            }
        }
        else if(order=="empty"){
            for(int i=1;i<=20;i++){
                number.erase(i);
            }
        }
    }

    return 0;   
}