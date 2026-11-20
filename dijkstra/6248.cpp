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
vector<pair<int,int>> nodes[100001];
int dist[100001];
void Dijkstra(int start){
    priority_queue<pair<int,int>> pq;
    pq.push({0,start});
    dist[start]=0;

    while(!pq.empty()){
        int here=pq.top().second;
        int cost=-pq.top().first;
        pq.pop();

        if(dist[here]<cost) continue;

        for(int i=0;i<nodes[here].size();i++){
            int via=cost+nodes[here][i].first;
            if(via<dist[nodes[here][i].second]){
                dist[nodes[here][i].second]=via;
                pq.push({-via,nodes[here][i].second});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    int n,m,x;
    cin>>n>>m>>x;
    int a,b,c;
    int maxdist=0;
    for(int i=1;i<=m;i++){
        cin>>a>>b>>c;
        nodes[a].push_back({c,b});
        nodes[b].push_back({c,a});
    }
    for(int i=1;i<=n;i++){
        dist[i]=INF;
    }
    
    Dijkstra(x);
    
    
    for(int i=1;i<=n;i++){
        if(dist[i]!=INF){
            maxdist=max(maxdist,dist[i]);
        }
    }

    cout<<maxdist*2;


    


    return 0;
}