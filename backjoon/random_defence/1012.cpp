#include <iostream>
#include <string.h>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<sstream>
using namespace std;

int b[50][50];
int m,n,t,k,ans;
int x,y;
int xd[4]={0,0,-1,1};
int yd[4]={1,-1,0,0};

void dfs(int x,int y){
    b[x][y]=0;
    for(int i=0;i<4;i++){
        int xx=x+xd[i];
        int yy=y+yd[i];
        if(xx<0||yy<0||xx>=m||yy>=n) continue;
        if(b[xx][yy]==1){
            dfs(xx,yy);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);

    
    cin>>t;
    for(int q=0;q<t;q++){
        cin>>m>>n>>k;
        for(int i=0;i<k;i++){
            cin>>x>>y;
            b[x][y]=1;
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(b[i][j]==1){
                    dfs(i,j);
                    ans++;
                }
            }
        }
        cout<<ans<<'\n';
        ans=0;
    }
       

    return 0;
}