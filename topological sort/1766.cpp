#include<iostream>
#include<algorithm>
#include<vector>
#include <queue>
using namespace std;
int n,m;
int a,b;


int dist[32001];
vector<vector<int>> ord(32001);
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin>>n>>m;
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        dist[b]++;
        ord[a].push_back(b);
    }
    priority_queue<int,vector<int>,greater<int>>q;
    for(int i=1;i<=n;i++){
        if(dist[i]==0){
            q.push(i);
            dist[i]=-1;
        }
    }

    while(!q.empty()){
        int x=q.top();
        cout<<x<<" ";
        q.pop();
        for(int i=0;i<ord[x].size();i++){
            if(--dist[ord[x][i]]==0){
                q.push(ord[x][i]);
                dist[ord[x][i]]=-1;
            }
        }
    }



    return 0;
}