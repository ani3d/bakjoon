#include <iostream>
#include <string.h>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<sstream>
using namespace std;
int cnt;
int m,n;
int map[101][101];
bool visit[101][101];
int dx[]={1,1,1,-1,-1,-1,0,0};
int dy[]={-1,1,0,-1,1,0,-1,1};

void dfs(int x,int y){
    visit[x][y]=true;
    
    for(int i=0;i<8;i++){
        int xx=x+dx[i];
        int yy=y+dy[i];

        if(xx<0||xx>=m||yy<0||yy>=n) continue;
        if(visit[xx][yy]) continue;

        if(map[xx][yy]=='#'){
            dfs(xx,yy);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    
    cin>>m>>n;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(map[i][j]=='#'){
                dfs(i,j);
                cnt++;
            }
        }
    }

    cout<<cnt<<'\n';



    return 0;
}