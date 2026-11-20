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


int n,m,r;
vector<int> vec[100001];
int visit[100001];

int output[100001];
int cnt=1;

void dfs(int dot){
    visit[dot]=1;
    output[dot]=cnt++;
    for(int i=0;i<vec[dot].size();i++){
        if(!visit[vec[dot][i]]){
            dfs(vec[dot][i]);
        }
    }

}

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    
    cin>>n>>m>>r;

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    
    for(int i=1;i<=n;i++){
        sort(vec[i].begin(),vec[i].end(),greater());
    }

    dfs(r);

    for(int i=1;i<=n;i++){
        cout<<output[i]<<'\n';
    }






    return 0;
}