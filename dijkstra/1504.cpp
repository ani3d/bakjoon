#include<iostream>
#include<vector>
#include<queue>

using namespace std;
const int INF=1e9;
int dist[200001];
vector<pair<int,int>> v[200001];
void dijkstra(int start){
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
    ios::sync_with_stdio();
    cin.tie(0);cout.tie(0);
    int n,e;
    cin>>n>>e;
    for(int i=1;i<=n;i++){
        dist[i]=INF;
    }
    
    
    for(int i=0;i<e;i++){
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back({c,b});
        v[b].push_back({c,a});
    }
    int v1,v2;
    cin>>v1>>v2;
    dijkstra(1);
    long long ans1=0;
    long long ans2=0;
    ans1+=dist[v1];
    ans2+=dist[v2];
    for(int i=1;i<=n;i++){
        dist[i]=INF;
    }
    dijkstra(v1);
    ans1+=dist[v2];
    ans2+=dist[v2];
    for(int i=1;i<=n;i++){
        dist[i]=INF;
    }
    dijkstra(v2);

    ans1+=dist[n];
    for(int i=1;i<=n;i++){
        dist[i]=INF;
    }
    dijkstra(v1);
    ans2+=dist[n];
    long long ans=min(ans1,ans2);
    if(ans>=INF) cout<<-1;
    else cout<<ans;

    


    return 0;
}