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

struct Edge{
    int u,v,weight;
};
int parent[100001];

int find(int x){
    if(parent[x]==x) return x;
    return parent[x]=find(parent[x]);
}

void unite(int a,int b){
    a=find(a);
    b=find(b);
    if(a!=b) parent[b]=a;
}




int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    vector<Edge> edges;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        parent[i]=i;
    }
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        edges.push_back({a,b,c});
    }

    sort(edges.begin(),edges.end(),[](Edge a,Edge b){
        return a.weight<b.weight;
    });
    int maxedge=0;
    int totalweight=0;
    for(auto edge : edges){
        if(find(edge.u)!=find(edge.v)){
            unite(edge.u,edge.v);
            totalweight+=edge.weight;
            maxedge=max(edge.weight,maxedge);
        }
    }
    cout<<totalweight-maxedge;




    return 0;
}