#include <iostream>
#include <string.h>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<sstream>
using namespace std;

int N,M,u,v;
bool visit[1001];
vector<int> vec[1001];
int cnt;

void dfs(int n){
    visit[n]=true;

    for(int i=0;i<vec[n].size();i++){
        if(!visit[vec[n][i]]){
            dfs(vec[n][i]);
            
        }

    }
}

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    cin>>N>>M;

    for(int i=0;i<M;i++){
        cin>>u>>v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }

    for(int i=1;i<=N;i++){
        if(!visit[i]){
            dfs(i);
            cnt++;
        }
    }
    cout<<cnt;


    return 0;
}