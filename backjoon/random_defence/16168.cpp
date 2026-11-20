#include<iostream>
#include<vector>
using namespace std;

int parent[3001];
int find(int x){
    if(x==parent[x]) return x;
    else return parent[x]=find(parent[x]);
}
void unite(int a,int b){
    int fa=find(a);
    int fb=find(b);
    if(fa!=fb) parent[fa]=fb;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int v,e;
    cin>>v>>e;
    vector<vector<int>> edge(v+1);
    for(int i=0;i<v+1;i++){
        parent[i]=i;
    }

    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
        unite(a,b);
    }
    int holcnt=0;
    bool flag=true;
    for(int i=1;i<v;i++){
        if(find(parent[i])!=find(parent[i+1])){
            flag=false;
            cout<<"NO"<<'\n';
            return 0;
        }
    }
    for(int i=1;i<=v;i++){
        if(edge[i].size()%2==1){
            holcnt++;
        }
    }
    
    if(holcnt==2||holcnt==0){
        cout<<"YES"<<'\n';
    }
    else cout<<"NO"<<'\n';



    return 0;
}