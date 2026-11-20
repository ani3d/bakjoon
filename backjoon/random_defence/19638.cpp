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


int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    int n,h,t; cin>>n>>h>>t;
    priority_queue<long long int> maxheap;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        maxheap.push(temp);
    }
    bool cnt=false;
    int idx=0;
    if(maxheap.top()<h){
        cout<<"YES\n"<<0;
        return 0;
    }
    if(h==1){
        if(maxheap.top()==1){
            cout<<"NO\n"<<1;
            return 0;
        }
    }

    for(int i=0;i<t;i++){
        
        int temp=maxheap.top();
        maxheap.pop();
        
        if(temp==1){
            maxheap.push(temp);
        }
        else{
            temp=temp/2;
            maxheap.push(temp);
        }
        if(maxheap.top()<h){
            cnt=true;
            idx=i;
            break;
        }
    }
    if(cnt==true){
        cout<<"YES\n"<<idx+1;
    }
    else{
        cout<<"NO\n"<<maxheap.top();
    }
    


    return 0;   
}