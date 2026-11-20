#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>

using namespace std;
vector<int> parent;
long long int find(int x){
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
    int n,q;
    
    
    
    int cnt=1;
    while(cin>>n>>q){
        
        if(n==0&&q==0) break;
        long long int money=1e9;
        parent.clear();
        parent.resize(n+1);
        unordered_map<string,int> city;
        int citycnt=1;
        priority_queue<pair<int,pair<int,int>>> pq;
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
        for(int i=0;i<q;i++){
            string s,e;
            int dist;
            cin>>s>>e>>dist;
            if(city.find(s)==city.end()){
                city[s]=citycnt;
                citycnt++;
            }
            if(city.find(e)==city.end()){
                city[e]=citycnt;
                citycnt++;
            }
            pq.push({dist,{city[s],city[e]}});
            
            
        }
        string s,e;
        cin>>s>>e;
        int snode=city[s];
        int enode=city[e];

        while(!pq.empty()){
            pair<int,pair<int,int>> data;
            data=pq.top();
            pq.pop();
            long long int w=data.first;
            
            int st=data.second.first;
            int ed=data.second.second;
            long long int a=find(st);
            long long int b=find(ed);

            if(a!=b){
                money=min(money,w);
                unite(a,b);
                if(find(snode)==find(enode)){
                    break;
                }
            }
        }
        cout<<"Scenario #"<<cnt<<'\n';
        cout<<money<<" tons"<<'\n'<<'\n';
        cnt++;
    
    }


    return 0;
}