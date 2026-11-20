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
int dist[50001];
vector<pair<int,int>> nodes[50001];

void Dijkstra(int start){
    priority_queue<pair<int,int>> pq;
    pq.push({0,start});
    dist[start]=0;
    int cnt=0;

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
    
    int n,m,a,b,c;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        dist[i]=INF;
    }
    for(int i=1;i<=m;i++){
        cin>>a>>b>>c;
        nodes[a].push_back({c,b});
        nodes[b].push_back({c,a});
    }
    
    Dijkstra(1);
    cout<<dist[n];



    return 0;
}