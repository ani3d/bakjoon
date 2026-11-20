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

const long long Inf=(long long)4e18;

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    int n,m; cin>>n>>m;
    vector<vector<pair<int,int>>> nodes(n); 
    int ward[100001];
    for(int i=0;i<n;i++){
        cin>>ward[i];
    }
    ward[n-1]=0;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        nodes[a].push_back({c,b});
        nodes[b].push_back({c,a});
    }
    vector<long long> dist(n,Inf);
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
    dist[0]=0;
    pq.push({0,0});

    while(!pq.empty()){
        auto[cost,u]=pq.top();
        pq.pop();
        if(cost!=dist[u]) continue;
        if(u==n-1) break;

        for(auto[w,v]: nodes[u]){
            if(ward[v]==1&&v!=n-1) continue;
            long long via=cost+(long long int)w;
            if(via<dist[v]){
                dist[v]=via;
                pq.push({via,v});

            }
        }
    }
    cout<<(dist[n-1]==Inf?-1:dist[n-1])<<'\n';


    return 0;   
}