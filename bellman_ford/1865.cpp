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

const int INF=1e9;

int tc,n,m,w,s,e,t;

vector<tuple<int,int,int>> edge;
vector<long long int> dist;

bool bellman_ford(){
    dist.assign(n+1,0);
    
    for(int i=1;i<=n;i++){
        for(auto[u,v,cost]:edge){
            if(dist[u]!=INF&&dist[u]+cost<dist[v]){
                dist[v]=dist[u]+cost;

                if(i==n) return true;
            }
        }
    }
    

    return false;
    
}

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    
    cin>>tc;
    while(tc--){
        edge.clear();
        cin>>n>>m>>w;
        for(int i=1;i<=m;i++){
            cin>>s>>e>>t;
            edge.push_back({s,e,t});
            edge.push_back({e,s,t});
        }
        for(int i=1;i<=w;i++){
            cin>>s>>e>>t;
            edge.push_back({s,e,-t});
        }
        bool cycle=false;
        if(bellman_ford()){
            cycle=true;
        }
        cout<<(cycle?"YES":"NO")<<'\n';
        
        
    }
    

    return 0;
}