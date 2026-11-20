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
    bool error=false;
    deque<int> dq;
    int t,n;
    string p;
    string arr;
    string num;
    bool where;
    cin>>t;

    while(t--){
        where=true;
        cin>>p;
        cin>>n;
        cin>>arr;
        num="";
        error=false;
        for(int i=0;i<arr.size();i++){
            if(isdigit(arr[i])){
                num+=arr[i];
            }
            else{
                if(!num.empty()){
                    dq.push_back(stoi(num));
                    num="";
                }
            }
            
        }
        for(int j=0;j<p.size();j++){
            if(p[j]=='R'){
                where=!where;
            }
            if(p[j]=='D'){
                if(dq.empty()) {
                    cout<<"error"<<'\n';
                    error=true; 
                    break;
                }
                if(where==true){
                    dq.pop_front();
                }
                else dq.pop_back();
            }
        }

        if(!error){
            cout<<'[';
        }

        if(where==true){
            while(!dq.empty()){
                if(dq.size()==1){
                    cout<<dq.front();
                }
                else cout<<dq.front()<<',';
                dq.pop_front();
            }
        }
        else{
            while(!dq.empty()){
                if(dq.size()==1){
                    cout<< dq.back();
                }
                else{
                    cout<< dq.back()<<',';
                }
                dq.pop_back();
            }
        }
        if(!error){
            cout<<"]\n";
        }

    }







    return 0;
}