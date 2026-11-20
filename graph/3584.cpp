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

int parent[50001][17];
int depth[50001];
int indeg[50001];
vector<vector<int>> adj;

void dfs(int cur){
    for(int next:adj[cur]){
        if(depth[next]==-1){
            depth[next]=depth[cur]+1;
            parent[next][0]=cur;
            dfs(next);
        }
    }
    return;
}
void connect(int n,int len){
    for(int k=1;k<len;k++){
        for(int i=1;i<=n;i++){
            parent[i][k]=parent[parent[i][k-1]][k-1];
        }
    }
}

int lca(int u,int v, int len){
    if(depth[u]<depth[v]){
        swap(u,v);
    }
    int diff=depth[u]-depth[v];
    for(int k=0;diff!=0;k++){
        if(diff%2==1){
            u=parent[u][k];
        }
        diff/=2;
    }

    if(u!=v){
        for(int k=len-1;k>=0;k--){
            if(parent[u][k]!=parent[v][k]){
                u=parent[u][k];
                v=parent[v][k];
            }
        }
        u=parent[u][0];
    }
    return u;
}

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);

    int t,n;
    cin>>t;
    int a,b;
    while(t--){
        int root;
        cin>>n;
        adj.assign(n+1,{});
        for(int i=1;i<=n;i++){
            indeg[i]=0;
            depth[i]=-1;
            for(int k=0;k<17;k++){
                parent[i][k]=0;
            }
        }
        for(int i=0;i<n-1;i++){
            cin>>a>>b;
            adj[a].push_back(b);
            indeg[b]++;
            
        }
        root=1;
        for(int i=1;i<=n;i++){
            if(indeg[i]==0){
                root=i;
                break;
            }
        }
        
        depth[root]=0;
        cin>>a>>b;
        dfs(root);
        int len=(int)ceil(log2(n))+1;
        connect(n,len);

        int ans=lca(a,b,len);
        cout<<ans<<'\n';
    }



    return 0;   
}