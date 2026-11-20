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

int visit[1001][1001];

bool comp(const pair<int,pair<int,int>> a,const pair<int,pair<int,int>> b){
    if(a.second.second==b.second.second){
        return a.second.first<b.second.first;
    }
    return a.second.second>b.second.second;
}
int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    int n;
    cin>>n;
    vector<pair<int,pair<int,int>>> v;
    for(int i=1;i<=n;i++){
        int x,y;
        cin>>x>>y;
        v.push_back(make_pair(i,make_pair(x,y)));
    }

    sort(v.begin(),v.end(),comp);
    /*for(int i=0;i<n;i++){
        cout<<v[i].first<<" "<<v[i].second.first<<" "<<v[i].second.second<<'\n';
    }*/
    for(int i=0;i<n-1;i++){
        cout<<v[i].first<<" "<<v[i+1].first<<'\n';
    }

    

    
    


    return 0;   
}