#include <iostream>
#include <string.h>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<sstream>
using namespace std;

int arr[1001][1001];
int visited[1001];
int n,m,v;

void dfs(int v){
    visited[v]=1;
    cout<<v<<" ";

    for(int i=1;i<=n;i++){
        if(arr[v][i]==1&&visited[i]==0){
            dfs(i);
        }
        if(i==n) return;
    }
    
}

void bfs(int v){
    queue<int> q;
    q.push(v);

    while(!q.empty()){
        int next=q.front();
        visited[next]=1;
        cout<<next<<" ";
        q.pop();

        for(int i=1;i<=n;i++){
            if(arr[next][i]==1&&visited[i]==0){
                q.push(i);
                visited[i]=1;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    int u,p;
    cin>>n>>m>>v;

    for(int i=0;i<m;i++){
        cin>>u>>p;
        arr[u][p]=1;
        arr[p][u]=1;
    }
    dfs(v);

    cout<<'\n';

    memset(visited,0,sizeof(visited));
    
    bfs(v);



    return 0;
}