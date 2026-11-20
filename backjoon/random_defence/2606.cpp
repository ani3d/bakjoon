#include <iostream>
#include <string.h>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<sstream>
using namespace std;

queue<int> q;
int n,m;
bool visit[101];
vector<int> v[101];
int g[101][101];
int a,b;
int cnt=0;
/*
void dfs(int n){
    
    visit[n]=true;
    for(int i=0;i<v[n].size();i++){
        int nn=v[n][i];

        if(!visit[nn]){ 
            
            dfs(nn);
            cnt++;
        }
    }
}
    */

void bfs(int s){
    
    

    q.push(s);
    visit[s]=true;

    while(!q.empty()){
        int a=q.front();

        q.pop();

        for(int i=0;i<=n;i++){
            if(g[a][i]==1&&visit[i]==0){
                q.push(i);
                visit[i]=true;
                cnt++;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    cin>>n;
    cin>>m;

    for(int i=0;i<m;i++){
        cin>>a>>b;
        //v[a].push_back(b);
        //v[b].push_back(a);
        g[a][b]=1;
        g[b][a]=1;
    }
    
    bfs(1);
    cout<<cnt<<'\n';


    return 0;
}