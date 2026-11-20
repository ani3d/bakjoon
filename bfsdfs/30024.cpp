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

int Map[1001][1001];
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
bool visit[1001][1001];
priority_queue<pair<int,pair<int,int>>> pq;
vector<pair<int,int>> ans;

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    
    int n,m,k;cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>Map[i][j];
            if(i==0||i==n-1){
                pq.push(make_pair(Map[i][j],make_pair(i,j)));
                visit[i][j]=true;
            }
            else{
                if(j==0||j==m-1){
                    pq.push(make_pair(Map[i][j],make_pair(i,j)));
                    visit[i][j]=true;
                }
            }
        }
    }
    cin>>k;
    while(k--){
        if(pq.empty()){
            break;
        }
        pair<int,pair<int,int>> top=pq.top();
        pq.pop();
        for(int i=0;i<4;i++){
            int ny=top.second.first+dy[i];
            int nx=top.second.second+dx[i];
            if(ny>=0&&ny<n&&nx>=0&&nx<m&&!visit[ny][nx]){
                pq.push(make_pair(Map[ny][nx],make_pair(ny,nx)));
                visit[ny][nx]=true;
            }
        }
        ans.push_back(make_pair(top.second.first+1,top.second.second+1));
    }
    for(int i=0;i<(int)ans.size();i++){
        cout<<ans[i].first<<" "<<ans[i].second<<'\n';
    }

    return 0;   
}