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

int V,e;
int k,u,v,w;
int dist[20001];
vector<pair<int,int>> nodes[20001];

void dijkstra(int start){
    priority_queue<pair<int,int>> pq;
    dist[start]=0;
    pq.push({0,start});

    while(!pq.empty()){
        int cost=-pq.top().first;
        int here=pq.top().second;
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
    cin>>V>>e;
    cin>>k;
    for(int i=1;i<=V;i++) dist[i]=INF;
    for(int i=1;i<=e;i++){
        cin>>u>>v>>w;
        nodes[u].push_back({w,v});
    }

    dijkstra(k);
    for(int i=1;i<=V;i++){
        if(dist[i]==INF) cout<<"INF\n";
        else cout<<dist[i]<<'\n';
    }

    
   


    return 0;
}