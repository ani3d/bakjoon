#include<iostream>
#include<vector>
#include<queue>


using namespace std;
vector<long long int> parent;
long long int find(long long int x){
    if(parent[x]!=x){
        parent[x]=find(parent[x]);
    }
    return parent[x];
}
void unite(long long int a,long long int b){
    int rx=find(a);
    int ry=find(b);

    if(rx!=ry){
        parent[ry]=rx;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,q;
    cin>>n>>q;
    parent.resize(n+1);
    long long int money=0;long long int total=0;
    priority_queue<pair<pair<long long int,long long int>,pair<long long int,long long int>>> pq;
    for(int i=1;i<=n;i++){
        parent[i]=i;
    }
    for(int i=0;i<q;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        pq.push({{-c,-d},{a,b}});
        pq.push({{-c,-d},{b,a}});
    }
    long long int time=-1;
    while(!pq.empty()){
        pair<pair<long long int,long long int>,pair<long long int,long long int>> data;
        data=pq.top();
        pq.pop();
        long long int w=-data.first.first;
        
        long long int st=data.second.first;
        long long int ed=data.second.second;
        long long int a=find(st);
        long long int b=find(ed);
        if(a!=b){
            money+=w;
            unite(a,b);
            time=max(time,-data.first.second);
        }
        
    }
    for(int i=1;i<n;i++){
        if(find(i)!=find(i+1)){
            cout<<-1;
            return 0;
        }
    }
    

    cout<<time<<' '<<money;


    return 0;
}