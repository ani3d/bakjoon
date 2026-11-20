#include <iostream>
#include <string.h>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<sstream>
using namespace std;

int m,n;
int arr[1001][1001];
int visit[1001][1001];
int cnt;

queue<pair<int,int>> q;

int dx[]={1,-1,0,0};
int dy[]={0,0,-1,1};


void bfs(){
    while(!q.empty()){
        int y=q.front().first;
        int x=q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];

            if(nx<0||nx>=m||ny<0||ny>=n) continue;

            if(arr[ny][nx]==0){
                arr[ny][nx]=arr[y][x]+1;
                q.push({ny,nx});
            }
        }

    }
}




int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    
    cin>>m>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            if(arr[i][j]==1){
                q.push({i,j});
            }
        }
    }

    bfs();

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==0){
                cout<<-1;
                return 0;
            }

            if(cnt<arr[i][j]){
                cnt=arr[i][j];
            }

        }
    }

    cout<<cnt-1;


    return 0;
}