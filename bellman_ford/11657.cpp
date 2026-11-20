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

const long long int INF=1e9;
int n,m,a,b,c;
vector<tuple<int,int,int>> edge;
vector<long long int> dist;//

bool bellman_ford(int start){
    dist.assign(n+1,INF);
    dist[start]=0;

    for(int i=1;i<=n;i++){
        for(auto[u,v,cost]:edge){
            if(dist[u]!=INF&&dist[u]+cost<dist[v]){
                dist[v]=dist[u]+cost;
            }
        }
    }
    for(auto[u,v,cost]:edge){
        if(dist[u]!=INF&&dist[u]+cost<dist[v]){
            return false;
        }
    }
    return true;
}


int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    
    
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a>>b>>c;
        edge.push_back({a,b,c});
    }

    if(bellman_ford(1)==false){
        cout<<-1;
        return 0;
    }
    else{
        for(int i=2;i<=n;i++){
            if(dist[i]==INF){
                cout<<-1<<'\n';
            }
            else{
                cout<<dist[i]<<'\n';
            }
            
        }
    }

    





    return 0;
}