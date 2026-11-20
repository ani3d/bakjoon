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


int n,m,k;
int len[1001][1001];
bool visit[1001][1001];
bool guard[1001][1001];
int dx1[6]={-1,0,1,1,0,-1};
int dy1[6]={0,-1,0,1,1,1};

int dx2[6]={-1,-1,0,1,1,0};
int dy2[6]={-1,0,1,0,-1,-1};

queue<pair<int,int>> q;
void bfs(){
    

    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        if(x%2!=0){
            for(int i=0;i<6;i++){
                int nx=x+dx1[i];
                int ny=y+dy1[i];

                if(nx<0||nx>=n||ny<0||ny>=m) continue;
                if(!visit[nx][ny]&&guard[nx][ny]!=true){
                    len[nx][ny]=len[x][y]+1;
                    q.push({nx,ny});
                    visit[nx][ny]=true;
                }
            } 
        }
        else {
            for(int i=0;i<6;i++){
                int nx=x+dx2[i];
                int ny=y+dy2[i];

                if(nx<0||nx>=n||ny<0||ny>=m) continue;
                if(!visit[nx][ny]&&guard[nx][ny]!=true){
                    len[nx][ny]=len[x][y]+1;
                    q.push({nx,ny});
                    visit[nx][ny]=true;
                }
            }    
        }
         
    }
    
}

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    
    cin>>n>>m>>k;

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            len[i][j]=-1;
        }
    }
    for(int i=0;i<k;i++){
        int x,y;
        cin>>x>>y;
        guard[x][y]=true;
    }
    
    len[0][0]=0;
    q.push({0,0});
    bfs();

    cout<<len[n-1][m-1];

    return 0;   
}