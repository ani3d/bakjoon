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
int dist[100001];
vector<pair<int,int>> v[100001];
void Dijkstra(int start){
    priority_queue<pair<int,int>> pq;
    pq.push({0,start});
    dist[start]=0;

    while(!pq.empty()){
        int here=pq.top().second;
        int cost=-pq.top().first;
        pq.pop();

        if(dist[here]<cost) continue;

        for(int i=0;i<v[here].size();i++){
            int via=cost+v[here][i].first;

            if(via<dist[v[here][i].second]){
                dist[v[here][i].second]=via;
                pq.push({-via,v[here][i].second});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    int n,m,s,t,a,b,c;

    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a>>b>>c;
        v[a].push_back(make_pair(c,b));
        v[b].push_back(make_pair(c,a));
    }    
    for(int i=1;i<=n;i++){
        dist[i]=INF;
    }
    cin>>s>>t;
    Dijkstra(s);

    cout<<dist[t];




    return 0;
}