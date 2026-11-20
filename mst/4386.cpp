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
    int u,v;
    double weight;
};
int parent[101];

double find(int x){
    if(parent[x]==x) return x;
    return parent[x]=find(parent[x]);
}
void unite(int a,int b){
    a=find(a);
    b=find(b);
    if(a!=b) parent[b]=a;
}

double length;

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    int n;
    vector<Edge> edges;
    cin>>n;
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
    vector<pair<double,double>> point(n);
    for(int i=0;i<n;i++){
        cin>>point[i].first>>point[i].second;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            double dx=point[i].first-point[j].first;
            double dy=point[i].second-point[j].second;
            double dist=sqrt(dx*dx+dy*dy);
            edges.push_back({i,j,dist});
        }
    }
    sort(edges.begin(),edges.end(),[](Edge a,Edge b){
        return a.weight<b.weight;
    });
    double total=0;
    for(auto edge:edges){
        if(find(edge.u)!=find(edge.v)){
            unite(edge.u,edge.v);
            total+=edge.weight;
        }
    }
    cout.precision(2);
    cout<<fixed<<total<<'\n';
    


    return 0;
}