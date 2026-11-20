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


int n,m;
char arr[3001][3001];
bool visit[3001][3001];
int len[3001][3001];
queue<pair<int,int>> q;
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
void bfs(){
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];

            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(visit[nx][ny]!=true&&arr[nx][ny]!='1'){
                q.push({nx,ny});
                visit[nx][ny]=true;
                len[nx][ny]=len[x][y]+1;
                
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);

    
    cin>>n>>m;
    int sx,sy;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            if(arr[i][j]=='2'){
                sx=i;
                sy=j;
            }
        }
    }
    
    
    q.push({sx,sy});
    visit[sx][sy]=true;
    bfs();
    int minlen=1e9;
    bool flag=false;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]=='3'||arr[i][j]=='4'||arr[i][j]=='5'){
                if(len[i][j]!=0&&len[i][j]<minlen){
                    minlen=(int)(len[i][j]);
                    flag=true;
                }
            }
        }
    }
    
    if(flag==true){
        cout<<"TAK"<<'\n';
        cout<<minlen;
    }
    else cout<<"NIE";

    
    return 0;   
}