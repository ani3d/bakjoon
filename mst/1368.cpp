#include<iostream>
#include<vector>
#include<queue>

#define INF 1e9
using namespace std;
vector<int> parent;
bool visit[301];
struct compare{
    bool operator()(pair<int,int> a,pair<int,int> b){
        return a.second>b.second;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;
    vector<int> water(n+1);
    vector<pair<int,int>> adj[301];
    vector<vector<int>> v(n+1,vector<int>(n+1));
    int watermin=INF;
    int idx=0;
    for(int i=1;i<=n;i++){
        cin>>water[i];
        adj[0].push_back({i,water[i]});
        adj[i].push_back({0,water[i]});
    }
    

    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>v[i][j];
            if(v[i][j]!=0){
                adj[i].push_back({j,v[i][j]});
                adj[j].push_back({i,v[i][j]});
            }
        }
    }
    pq.push({0,0});
    long long total=0;
    int cnt=0;
    
    while(cnt<n+1){
        pair<int,int> now=pq.top();
        pq.pop();

        int node=now.first;
        int w=now.second;
        
        if(visit[node]) continue;
        visit[node]=true;
        cnt++;
        total+=w;
        for(int i=0;i<adj[node].size();i++){
            int nnode=adj[node][i].first;
            if(!visit[nnode]) pq.push(adj[node][i]);
        }
    }
  
    cout<<total;
    


    return 0;
}