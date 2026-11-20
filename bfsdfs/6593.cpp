#include <iostream>
#include <string.h>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<sstream>
#include<map>
#include <tuple>
using namespace std;


int l,r,c;
int dx[6]={0,-1,0,1,0,0};
int dy[6]={1,0,-1,0,0,0};
int dz[6]={0,0,0,0,1,-1};
char building[31][31][31];
bool visit[31][31][31];

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);

    while(cin>>l>>r>>c){
        if(l==0&&r==0&&c==0) break;
        int time[31][31][31];
        for(int i=0;i<l;i++){
            for(int j=0;j<r;j++){
                for(int k=0;k<c;k++){
                    visit[i][j][k]=false;
                    
                    time[i][j][k]=0;
                }
            }
        }
        queue<tuple<int,int,int>> q;
        
        int ex,ey,ez;
        for(int i=0;i<l;i++){
            for(int j=0;j<r;j++){
                for(int k=0;k<c;k++){
                    cin>>building[i][j][k];
                    if(building[i][j][k]=='S'){
                        q.push({i,j,k});
                        visit[i][j][k]=true;
                        time[i][j][k]=0;
                    }
                    if(building[i][j][k]=='E'){
                        ex=i;
                        ey=j;
                        ez=k;
                    }
                }
            }
            
        }
        
        while(!q.empty()){
            int x=get<0>(q.front());
            int y=get<1>(q.front());
            int z=get<2>(q.front());

            q.pop();

            for(int k=0;k<6;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];
                int nz=z+dz[k];

                if(nx<0||nx>=l||ny<0||ny>=r||nz<0||nz>=c) continue;
                if(building[nx][ny][nz]!='#'&&!visit[nx][ny][nz]){
                    q.push({nx,ny,nz});
                    visit[nx][ny][nz]=true;
                    time[nx][ny][nz]=time[x][y][z]+1;
                }
            }
        }
        
        if(time[ex][ey][ez]==0){
            cout<<"Trapped!"<<'\n';
        }
        else if(time[ex][ey][ez]!=0){
            cout<<"Escaped in "<<time[ex][ey][ez]<<" minute(s).\n";
        }

    }

    return 0;   
}