#include <iostream>
#include <string.h>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<sstream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    
    int n;
    cin>>n;
    string order;

    stack<int> num;


    for(int i=0;i<n;i++){
        int t;
        cin>>order;
        if(order=="push"){
            cin>>t;
            num.push(t);
        }
        if(order=="pop"){
            if(num.empty()){
                cout<<-1<<'\n';
            }
            else {
                cout<<num.top()<<'\n';
                num.pop();
            }
        }
        if(order=="size"){
            cout<<(num.size())<<'\n';
        }
        if(order=="empty"){
            if(num.empty()) cout<<1<<'\n';
            else cout<<0<<'\n';
        }
        if(order=="top"){
            if(num.empty()) cout<<-1<<'\n';
            else cout<<num.top()<<'\n';
        }

    }


    return 0;
}