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

int parent[200001];

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
    

    int m,n;
    while(1){
        cin>>m>>n;
        if(m==0&&n==0) break;
        vector<Edge> edges;
        for(int i=0;i<m;i++){
            parent[i]=i;
        }

        int light=0;
        for(int i=0;i<n;i++){
            int x,y,z;
            cin>>x>>y>>z;
            light+=z;
            edges.push_back({x,y,z});
        }
        sort(edges.begin(),edges.end(),[](Edge a,Edge b){
            return a.weight<b.weight;
        });
        int totalweight=0;
        for(auto edge : edges){
            if(find(edge.u)!=find(edge.v)){
                unite(edge.u,edge.v);
                totalweight+=edge.weight;
            }
        }

        cout<<light-totalweight<<'\n';
    }


    return 0;
}