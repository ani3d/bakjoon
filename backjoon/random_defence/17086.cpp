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

int dx[8] = {-1,-1,0,1,1,1,0,-1};
int dy[8] = {0,1,1,1,0,-1,-1,-1};


int n,m;

int arr[51][51];

int Min;
int cnt;

int bfs(int x,int y){
    
    int visit[51][51]={};
    
    
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    visit[x][y]=0;

    while(!q.empty()){
        
        int a=q.front().first;
        int b=q.front().second;
        q.pop();
    
        
        for(int j=0;j<8;j++){
            int xx=a+dx[j];
            int yy=b+dy[j];

            if(xx<0||xx>=n||yy<0||yy>=m) continue;
            if(visit[xx][yy]) continue;

            if(arr[xx][yy]==1){
                return visit[a][b]+1;
            }
            if(arr[xx][yy]==0){
                q.push({xx,yy});
                visit[xx][yy]=visit[a][b]+1;
            }
            
        }
        
        
    }


    return 0;
}

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    
    cin>>n>>m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==0){
                int ans=bfs(i,j);
                Min=max(ans,Min);
            }
        }
    }
    
    cout<<Min;

    return 0;
}