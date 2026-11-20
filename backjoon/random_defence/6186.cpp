#include <iostream>
#include <string.h>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<sstream>
using namespace std;

int r,c;
int cnt=0;
int b[101][101];
bool visit[101][101];
int xd[4]={0,0,-1,1};
int yd[4]={1,-1,0,0};
char d;

void dfs(int x,int y){
    visit[x][y]=true;
    for(int i=0;i<4;i++){
        int xx=x+xd[i];
        int yy=y+yd[i];
        if(xx<0||xx>=r||yy<0||yy>=c) continue;

        if(b[xx][yy]=1&&visit[x][y]==false){
            dfs(xx,yy);
        }
    }
}
int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);

    cin>>r>>c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>d;
            if(d=='#'){
                b[i][j]=1;
            }
        }
        
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(b[i][j]==1){
                dfs(i,j);
                cnt++;
            }
        }
    }
    cout<<cnt<<'\n';

    



    return 0;
}