#include <iostream>
#include <string.h>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<sstream>
#include<deque>
using namespace std;

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);

    deque<int> dq;
    int n,x;
    cin>>n;
    string ord;
    for(int i=0;i<n;i++){
        cin>>ord;
        if(ord=="push_front") {
            cin>>x;
            dq.push_front(x);
        }
        if(ord=="push_back"){
            cin>>x;
            dq.push_back(x);
        }
        if(ord=="pop_front"){
            if(dq.empty()) cout<<-1<<'\n';
            else{
                cout<<dq.front()<<'\n';
                dq.pop_front();
            }
        }
        if(ord=="pop_back"){
            if(dq.empty()) cout<<-1<<'\n';
            else{
                cout<<dq.back()<<'\n';
                dq.pop_back();
            }
        }
        if(ord=="size"){
            cout<<dq.size()<<'\n';
        }
        if(ord=="empty"){
            cout<<dq.empty()<<'\n';
        }
        if(ord=="front"){
            if(dq.empty()){
                cout<<-1<<'\n';
            }
            else cout<<dq.front()<<'\n';
        }
        if(ord=="back"){
            if(dq.empty()){
                cout<<-1<<'\n';
            }
            else cout<<dq.back()<<'\n';
        }
    }


    



    return 0;
}