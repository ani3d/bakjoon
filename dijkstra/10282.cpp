#include<iostream>
#include<vector>
#include <queue>

using namespace std;
const int INF=1e9;
int dist[10001]={0};
vector<pair<int,int>> nodes[100001];

int t;
int n,d,c;
void dijkstra(vector<pair<int,int>> nodes[],int start){
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
    int cnt=0,ans=0;
    for(int i=1;i<=n;i++){
        if(dist[i]!=INF){
            cnt++;
            ans=max(ans,dist[i]);
        }
    }
    cout<<cnt<<' '<<ans<<'\n';
    

}
int main(){
    cin>>t;
    
    while(t--){
        cin>>n>>d>>c;
        for(int i=1;i<=n;i++){
            dist[i]=INF;
        }
        for(int i=1;i<=n;i++){
            nodes[i].clear();
        }
        for(int i=0;i<d;i++){
            int a,b,s;
            cin>>a>>b>>s;
            nodes[b].push_back({s,a});
        }
        dijkstra(nodes,c);
        

        
    }

    
    



    return 0;
}