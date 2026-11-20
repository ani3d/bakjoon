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

char map[101][101];
int visit[101][101];
int dx[]={1,-1,0,0};
int dy[]={0,0,-1,1};


void dfs(int x,int y){
    visit[x][y]=1;

    for(int i=0;i<4;i++){
        int xx=x+dx[i];
        int yy=y+dy[i];

        if(xx<0||xx>=n||yy<0||yy>=m) continue;
        if(!visit[xx][yy]&&map[xx][yy]!='.'){
            visit[xx][yy]=1;
            dfs(xx,yy);
        }
    }
}


int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    
    int cnt=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>map[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(map[i][j]=='*'&&!visit[i][j]){
                dfs(i,j);
                cnt++;
            }
        }
    }

    cout<<cnt<<'\n';

    return 0;
}