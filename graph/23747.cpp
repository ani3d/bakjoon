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


int r,c,sr,sc;

int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
bool visit[1001][1001];
bool ward[1001][1001];

char world[1001][1001];
queue<pair<int,int>> q;
void bfs(){
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];

            if(nx>r||nx<0||ny>c||ny<0) continue;
            if(!visit[nx][ny]&&world[nx][ny]==world[x][y]){
                ward[nx][ny]=true;
                visit[nx][ny]=true;
                q.push({nx,ny});
            }

        }
    }
    

}

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    cin>>r>>c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>world[i][j];
        }
    }
    cin>>sr>>sc;
    sr--;
    sc--;
    
    string ord;
    cin>>ord;
    for(int i=0;i<ord.length();i++){
        if(ord[i]=='W'){
            ward[sr][sc]=true;
            visit[sr][sc]=true;
            q.push({sr,sc});
            bfs();
        }
        else if(ord[i]=='L'){
            sc--;
        }
        else if(ord[i]=='R'){
            sc++;
        }
        else if(ord[i]=='U'){
            sr--;
        }
        else if(ord[i]=='D'){
            sr++;
        }
    }
    
    ward[sr][sc]=true;
    for(int i=0;i<4;i++){
        int nx=sr+dx[i];
        int ny=sc+dy[i];

        if(nx>=r||nx<0||ny>=c||ny<0) continue;
        ward[nx][ny]=true;
    }

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(ward[i][j]){
                cout<<'.';
            }
            else cout<<'#';
        }
        cout<<'\n';
    }
    
    

    return 0;   
}