#include <iostream>
#include <string.h>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<sstream>
using namespace std;
int visit[1001]; 
vector<int> v[10001];
int N,M,V;

void dfs(int n){
    visit[n]=1;
    cout<<n<<' ';

    for(int i=0;i<v[n].size();i++){
        if(!visit[v[n][i]]){
            dfs(v[n][i]);
        }
    }
}

void bfs(int n){
    queue<int> q;
    q.push(n);
    visit[n]=1;

    while(!q.empty()){
        int x=q.front();
        q.pop();
        cout<<x<<' ';

        for(int i=0;i<v[x].size();i++){
            if(!visit[v[x][i]]){
                q.push(v[x][i]);
                visit[v[x][i]]=1;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    
    

    cin>>N>>M>>V;

    for(int i=0;i<M;i++){
        int a1,a2;
        cin>>a1>>a2;
        v[a1].push_back(a2);
        v[a2].push_back(a1);
    }

    for(int i=1;i<=N;i++){
        sort(v[i].begin(),v[i].end());
    }
    dfs(V);
    memset(visit,0,sizeof(visit));
    cout<<'\n';
    bfs(V);


    return 0;
}