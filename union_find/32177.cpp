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

struct person{
    int x,y,v,photo;
};


int find(vector<int>& parent,int x){
    if(parent[x]==x) return x;
    return parent[x]=find(parent,parent[x]);
}

void unite(vector<int>& parent,int a,int b){
    a=find(parent,a);
    b=find(parent,b);
    if(a!=b) parent[b]=a;
}
double dist(const person& a,const person& b){
    return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}
bool can_connect(const person &a,const person& b,int k,int t){
    return dist(a,b)<=k&&abs(a.v-b.v)<=t;
}

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    int n,k,t;
    
    cin>>n>>k>>t;
    vector<person> people(n+1);
    vector<int> parent(n+1);
    
    cin>>people[0].x>>people[0].y>>people[0].v;
    people[0].photo=0;


    for(int i=1;i<=n;i++){
        cin>>people[i].x>>people[i].y>>people[i].v>>people[i].photo;
        
    }
    for(int i=0;i<=n;i++){
        parent[i]=i;
    }

    for(int i=0;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(can_connect(people[i],people[j],k,t)){
                unite(parent,i,j);
            }
        }
    }
    int puang=find(parent,0);
    vector<int> result;

    for(int i=1;i<=n;i++){
        if(people[i].photo==1&&find(parent,i)==puang){
            result.push_back(i);
        }
    }
    if(result.empty()){
        cout<<0<<'\n';
    }
    else{
        sort(result.begin(),result.end());
        for(int x:result) cout<<x<<' ';
        cout<<'\n';
    }

    return 0;
}