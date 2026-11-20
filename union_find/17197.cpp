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

const int INF=1e9;
int parent[100001];
pair<int,int> cow[100001];


int find(int x){
    if(parent[x]==x) return x;
    return parent[x]=find(parent[x]);
}
void unite(int a,int b){
    a=find(a);
    b=find(b);
    if(a!=b){
        parent[b]=a;
    }
}

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    int n,m;

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        parent[i]=i;
    }
    for(int i=1;i<=n;i++){
        int x,y;
        cin>>x>>y;
        cow[i]={x,y};
    }    
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        unite(a,b);
    }

    vector<int> minx(n+1,INF),maxx(n+1,0),miny(n+1,INF),maxy(n+1,0);

    for(int i=1;i<=n;i++){
        int root=find(i);
        int x=cow[i].first;
        int y=cow[i].second;

        minx[root]=min(minx[root],x);
        miny[root]=min(miny[root],y);
        maxx[root]=max(maxx[root],x);
        maxy[root]=max(maxy[root],y);
    }
    int ans=INF;
    for(int i=1;i<=n;i++){
        if(find(i)==i){
            int perim=2*((maxx[i]-minx[i])+(maxy[i]-miny[i]));
            ans=min(ans,perim);
        }
    }

    cout<<ans<<'\n';

    return 0;
}