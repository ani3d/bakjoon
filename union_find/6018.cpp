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

pair<int,int> cow[5001];
int parent[5001];
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
    
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++){
        parent[i]=i;
    }
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        unite(a,b);
    }
    for(int i=1;i<=q;i++){
        int a,b;
        cin>>a>>b;
        if(find(a)!=find(b)){
            cout<<'N'<<'\n';
        }
        else cout<<'Y'<<'\n';
    }
   


    return 0;
}