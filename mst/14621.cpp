#include<iostream>
#include<vector>
#include<queue>


using namespace std;
vector<int> parent;
int find(int x){
    if(parent[x]!=x){
        parent[x]=find(parent[x]);
    }
    return parent[x];
}
void unite(int a,int b){
    int rx=find(a);
    int ry=find(b);

    if(rx!=ry){
        parent[ry]=rx;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> v;
    vector<char> s;
    
    v.resize(n+1);
    parent.resize(n+1);
    s.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    long long int money=0;long long int total=0;
    priority_queue<pair<int,pair<int,int>>> pq;
    for(int i=1;i<=n;i++){
        parent[i]=i;
    }
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        if(s[a]!=s[b]){
            total+=c;
            pq.push({-c,{a,b}});
            pq.push({-c,{b,a}});
        }
    }
    while(!pq.empty()){
        pair<int,pair<int,int>> data;
        data=pq.top();
        pq.pop();
        int w=-data.first;
        int st=data.second.first;
        int ed=data.second.second;
        int a=find(st);
        int b=find(ed);
        if(a!=b){
            money+=w;
            unite(a,b);
        }
    }
    for(int i=1;i<n;i++){
        if(find(i)!=find(i+1)){
            cout<<-1;
            return 0;
        }
    }
    
    

    cout<<money;


    return 0;
}