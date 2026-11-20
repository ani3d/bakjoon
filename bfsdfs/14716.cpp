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

int arr[251][251];
bool visit[251][251];
queue<pair<int,int>> q;
int m,n;
int dx[8]={1,0,-1,0,1,1,-1,-1};
int dy[8]={0,-1,0,1,-1,1,1,-1};
void bfs(){
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();

        for(int i=0;i<8;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];

            if(nx<0||nx>=m||ny<0||ny>=n) continue;
            if(arr[nx][ny]==1&&!visit[nx][ny]){
                q.push({nx,ny});
                visit[nx][ny]=true;
            }

        }
    }
}

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);

    cin>>m>>n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    int cnt=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
        if(arr[i][j]==1&&!visit[i][j]){
            q.push({i,j});
            visit[i][j]=true;
            bfs();
            cnt++;
        }
    }

    cout<<cnt;

    return 0;   
}