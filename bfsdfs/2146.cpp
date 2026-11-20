#include <iostream>
#include <string.h>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<sstream>
using namespace std;

int N;
int map[101][101];
int visit[101][101];
int res=987654321;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

vector<pair<int,int>> v;



void findland(int i,int j, int count){
    queue<pair<int,int>> q;

    map[i][j]=count;
    q.push({i,j});

    while(!q.empty()){
        int y=q.front().first;
        int x=q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int ny=y+dy[i];
            int nx=x+dx[i];

            if(ny<0||nx<0||ny>=N||nx>=N) continue;
            if(map[ny][nx]==0||map[ny][nx]==count) continue;

            q.push({ny,nx});
            map[ny][nx]=count;
        }
    }
}
    
void bfs(int num){
    queue<pair<pair<int,int>,int>> q;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(map[i][j]==num){

            
                visit[i][j]=1;
                q.push({{i,j},0});
            }
        }
    }

    while(!q.empty()){
        int y=q.front().first.first;
        int x=q.front().first.second;
        int n=q.front().second;

        q.pop();

        for(int i=0;i<4;i++){
            int ny=y+dy[i];
            int nx=x+dx[i];

            if(ny<0||nx<0||nx>=N||ny>=N) continue;
            if(map[ny][nx]!=0&&map[ny][nx]!=num){
                res=min(res,n);
                return;
            }
            if(visit[ny][nx]) continue;

            visit[ny][nx]=1;
            q.push({{ny,nx},n+1});
        }
    }
}

void solution(){
    int count=2;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(map[i][j]==1){
                findland(i,j,count);
                count++;
            }
        }
    }

    for(int i=2;i<count;i++){
        memset(visit,0,sizeof(visit));
        bfs(i);
    }

    cout<<res;
}


int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);

    cin>>N;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>map[i][j];
        }
    }
    
    solution();



    return 0;
}