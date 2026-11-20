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

int parent[10001];
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
    int v,e;
    cin>>v>>e;
    vector<Edge> edges;
    int a,b,c;
    for(int i=1;i<=v;i++){
        parent[i]=i;
    }
    for(int i=0;i<e;i++){
        cin>>a>>b>>c;
        edges.push_back({a,b,c});
    }

    sort(edges.begin(),edges.end(),[](Edge a,Edge b){
        return a.weight<b.weight;
    });

     int totalWeight = 0;
    for (auto edge : edges) {
        if (find(edge.u) != find(edge.v)) {
            unite(edge.u, edge.v);
            totalWeight += edge.weight;
        }
    }
    cout<<totalWeight<<'\n';


    return 0;
}