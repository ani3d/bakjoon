#include <iostream>
#include <string.h>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<sstream>
using namespace std;


int n,m;
int map[101][101];
int visit[101][101];
int dis[101][101];
int dx[]={1,-1,0,0};
int dy[]={0,0,-1,1};

string s;
queue<pair<int,int>> q;
void bfs(int a,int b){
    q.push({a,b});

    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];

            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(dis[nx][ny]==0&&map[nx][ny]==1){
                dis[nx][ny]=dis[x][y]+1;
                q.push({nx,ny});
            }
        }


    }
}

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    
    cin>>n>>m;

    for(int i=0;i<n;i++){
        cin>>s;
        for(int j=0;j<m;j++){
            map[i][j]=s[j]-'0';
        }
    }

    bfs(0,0);

    cout<<dis[n-1][m-1]+1;



    return 0;
}