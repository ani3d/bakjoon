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


int n,c;


map<int,int> order;
map<int,int> m;
int num;

bool cmp(pair<int,int>&a,pair<int,int>&b){
    if(a.second==b.second){
        return order[a.first]<order[b.first];
    }
    return a.second>b.second;
}


int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);

    cin>>n>>c;

    for(int i=0;i<n;i++){
        cin>>num;
        m[num]++;

        if(order[num]==0) order[num]=i+1;
    }

    vector<pair<int,int>> vec(m.begin(),m.end());

    sort(vec.begin(),vec.end(),cmp);

    for(auto x:vec){
        for(int i=0;i<x.second;i++){
            cout<<x.first<<" ";
        }
        
    }
    
    
    



    return 0;
}