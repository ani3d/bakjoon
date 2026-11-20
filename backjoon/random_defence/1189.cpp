#include <iostream>
#include <string.h>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<sstream>
using namespace std;

int r,c,k;
char map[6][6];
int visit[6][6];
int ans;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

void dfs(int x,int y,int cnt){
    
    if(cnt==k&&x==0&&y==c-1){
        ans++;
        return;
    }
    else if(cnt==k){
        return;
    }
    
    
    for(int i=0;i<4;i++){
        int xx=x+dx[i];
        int yy=y+dy[i];

        if(map[xx][yy]=='T') continue;
        if(visit[xx][yy]) continue;
        if(xx<0||xx>=r||yy<0||yy>=c) continue;

        visit[xx][yy]=1;
        dfs(xx,yy,cnt+1);
        visit[xx][yy]=0;
        
    }
}


int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0);
    
    cin>>r>>c>>k;

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>map[i][j];
        }
    }
    visit[r-1][0]=1;
    dfs(r-1,0,1);

    cout<<ans<<'\n';


    return 0;
}