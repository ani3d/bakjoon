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
    int n,k;
    cin>>n>>k;
    vector<int> v(n+1,-1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    bool flag=true;
    int idx=1;
    while(idx<=n){
        if(idx!=v[idx]){
            v[idx]+=k;

            if(v[idx]>n){
                cout<<0<<'\n';
                return 0;
            }
            
            sort(v.begin(),v.end());
            idx=1;
            continue;

        }   
        idx++;
    }
    
    cout<<1;
  


    
    

    return 0;   
}