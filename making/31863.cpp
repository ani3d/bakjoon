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
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int dest=0;
int building=0;
char world[1001][1001];
int visit[1001][1001];
int strong[1001][1001];
void boom(int x,int y){
    queue<pair<int,int>> q;
    for(int dir=0;dir<4;dir++){
        for(int dist=1;dist<=2;dist++){
            int midx=x+dx[dir];
            int midy=y+dy[dir];

            int nx=x+dx[dir]*dist;
            int ny=y+dy[dir]*dist;

            if(dist==2){
                if(midx<0||midy<0||midx>=n||midy>=m) continue;
                if(world[midx][midy]=='|') continue;
            }

            if(nx<0||ny<0||nx>=n||ny>=m) continue;;
            if(world[nx][ny]=='|') continue;
            
            if(world[nx][ny]=='*'&&visit[nx][ny]==0){
                
                visit[nx][ny]=1;
                q.push({nx,ny});
                dest++;
            }
            else if(world[nx][ny]=='#'){
                strong[nx][ny]++;
                if(strong[nx][ny]==2){
                    
                    dest++;
                    q.push({nx,ny});

                }
                
            }
        }
    }
    
    while(!q.empty()){
        int xx=q.front().first;
        int yy=q.front().second;
        q.pop();

        for(int dir=0;dir<4;dir++){

            
            int nx=xx+dx[dir];
            int ny=yy+dy[dir];
            
            if(nx<0||ny<0||nx>=n||ny>=m) continue;
            if(world[nx][ny]=='|'){
                continue;
            }
            
            

            if(world[nx][ny]=='*'){
                if(visit[nx][ny]==0){
                    visit[nx][ny]=1;
                    q.push({nx,ny});
                    
                    dest++;
                }
            }
            else if(world[nx][ny]=='#'){
                strong[nx][ny]++;
                if(strong[nx][ny]==2){
                    
                    dest++;
                    q.push({nx,ny});

                }
                
            }
            

        }

    }
}
int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    cin>>n>>m;
    
    
    int tx,ty;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>world[i][j];
            if(world[i][j]=='*'||world[i][j]=='#'){
                building++;
            }
            if(world[i][j]=='@'){
                tx=i;
                ty=j;
            }
        }
    }
    boom(tx,ty);

    cout<<dest<<' '<<building-dest;

    
    return 0;   
}