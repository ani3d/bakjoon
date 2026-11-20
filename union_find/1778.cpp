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

vector<int> student(50001);
int parent[50001];

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
    
    int n,m,caseNum=1;
    
    while(1){
        cin>>n>>m;
        int cnt=n;
        if(n==0&&m==0) break;
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
        for(int i=1;i<=m;i++){
            int a,b;
            cin>>a>>b;
            if(find(a)!=find(b)){
                unite(a,b);
                cnt--;
            }
        }
        cout<<"Case "<<caseNum++<<": "<<cnt<<'\n';
    }


    return 0;
}