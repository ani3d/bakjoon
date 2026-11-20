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

int world[21][21];
int visit[21][21];
int n;

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int cury,curx;
int bsize=2;
int eat=0;
int bfs(){
    memset(visit,0,sizeof(visit));
    queue<pair<int,int>>q;
    int dist=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    q.push({cury,curx});
    visit[cury][curx]=1;

    while(!q.empty()){
        int y=q.front().first;
        int x=q.front().second;

        q.pop();
        if(visit[y][x]==dist) break;
        for(int i=0;i<4;i++){
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(ny<0||ny>=n||nx<0||nx>=n) continue;
            if(visit[ny][nx]) continue;
            if(!world[ny][nx]||world[ny][nx]==bsize){
                q.push({ny,nx});
                visit[ny][nx]=visit[y][x]+1;
            }
            else if(world[ny][nx]<bsize){
                if(!dist){
                    eat++;
                }
                visit[ny][nx]=visit[y][x]+1;
                dist=visit[ny][nx];
                pq.push({ny,nx});
            }
        }
    }
    if(pq.empty()){
        return 0;
    }
    cury=pq.top().first;
    curx=pq.top().second;
    world[cury][curx]=0;
    if(eat==bsize){
        bsize++;
        eat=0;
    }
    return visit[cury][curx]-1;

    
}
int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    int ans=0;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>world[i][j];
            if(world[i][j]==9){
                world[i][j]=0;
                cury=i;
                curx=j;
            }
        }
    }
    while(true){
        int sec=bfs();
        ans+=sec;
        if(!sec)break;
    }
    cout<<ans;


    

    return 0;   
}