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


int parent[10000000];
pair<int,int> man[100000];
int find(int x){
    if(x==parent[x]) return x;
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
    int t;cin>>t;
    int n,k,a,b,m;
    int u,v;
    for(int tcase=1;tcase<=t;tcase++){
        cout<<"Scenario "<<tcase<<':'<<'\n';
        cin>>n;

        cin>>k;
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
        for(int j=0;j<k;j++){
            cin>>a>>b;
            unite(a,b);
        }
        cin>>m;
        for(int i=0;i<m;i++){
            cin>>u>>v;
            if(find(u)==find(v)){
                cout<<1<<'\n';
            }
            else cout<<'0'<<'\n';
        }
        cout<<'\n';
    }

    return 0;   
}