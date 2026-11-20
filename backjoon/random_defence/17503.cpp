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

vector<pair<int,int>> beers;

struct comp{
    bool operator()(int a,int b){
        return a>b;
    }
};


int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);

    int n,m,k;
    cin>>n>>m>>k;
  
    for(int i=0;i<k;i++){
        int v,c;
        cin>>v>>c;
        beers.push_back({v,c});
    }
    sort(beers.begin(),beers.end(),[](pair<int,int> p1,pair<int,int>p2)->bool{
        return p1.second<p2.second;
    });
    
    int sum=0;
    int idx=n;
    priority_queue<int,vector<int>,comp> max;
    long long total=0;
    for(auto beer : beers){
        max.push(beer.first);
        total+=beer.first;

        if(max.size()>n){
            total-=max.top();
            max.pop();
        }
        if(max.size()==n&&total>=m){
            cout<<beer.second<<'\n';
            return 0;
        }

    }
    cout<<-1<<'\n';
    
    return 0;   
}