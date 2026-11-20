#include <iostream>
#include <string.h>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<sstream>
using namespace std;

char map[101][101];
int visit[101][101];
int n;
int cnt;
int dx[]={1,-1,0,0};
int dy[]={0,0,-1,1};
void dfs(int x,int y){
    visit[x][y]=1;
    for(int i=0;i<4;i++){
        
        int xx=x+dx[i];
        int yy=y+dy[i];

        if(xx<0||xx>=n||yy<0||yy>=n) continue;
        if(visit[xx][yy]) continue;
        
        if(map[x][y]==map[xx][yy]){
            dfs(xx,yy);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!visit[i][j]){
                dfs(i,j);
                cnt++;
            }
        }
    }
    cout<<cnt<<' ';

    memset(visit,0,sizeof(visit));

    cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(map[i][j]=='G') map[i][j]='R';
            else(map[i][j]=map[i][j]);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!visit[i][j]){
                dfs(i,j);
                cnt++;
            }
        }
    }
    cout<<cnt<<'\n';


    return 0;
}