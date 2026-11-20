#include <iostream>
#include <string.h>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<sstream>
using namespace std;
int n,m;

vector<int> v[101];
int cnt=0;
int a,b;
int visit[101];

void dfs(int s,int count){
    if(cnt==n) return;

    for(int i=0;i<v[s].size();i++){
        int nn=v[s][i];

        if(!visit[nn]){
            visit[nn]=visit[s]+1;
            dfs(nn,count+1);
            
        }
    }
}
int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    cin>>n;
    cin>>a>>b;
    cin>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(a,0);

    if(visit[b]==0){
        cout<<-1;
    }
    else cout<<visit[b];



    return 0;
}