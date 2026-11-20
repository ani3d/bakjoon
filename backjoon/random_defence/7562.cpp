#include <iostream>
#include <string.h>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<sstream>
using namespace std;

int t,l;
int cx,cy,tx,ty;

int dx[]={-2,-2,-1,-1,1,1,2,2};
int dy[]={1,-1,2,-2,2,-2,1,-1};

int graph[301][301];
bool visit[301][301];

queue<pair<int,int>> q;

void bfs(int x,int y){
    q.push({x,y});
    visit[x][y]=true;
    while(!q.empty()){
        int a=q.front().first;
        int b=q.front().second;
        q.pop();

        if(a==tx&&b==ty){
            cout<<graph[a][b]<<'\n';
            while(!q.empty()){
                q.pop();
            }
            break;
        }
        for(int i=0;i<8;i++){
            int na=a+dx[i];
            int nb=b+dy[i];
            if(0<=na&&0<=nb&&na<l&&nb<l&&!visit[na][nb]){
                q.push({na,nb});
                visit[na][nb]=true;
                graph[na][nb]=graph[a][b]+1;
            }
        }
    }

}


int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    cin>>t;

    for(int i=0;i<t;i++){
        cin>>l;
        cin>>cx>>cy;
        cin>>tx>>ty;

        bfs(cx,cy);

        while(!q.empty()){
            q.pop();
        }
        for(int i=0;i<301;i++){
            for(int j=0;j<301;j++){
                visit[i][j]=0;
                graph[i][j]=0;
            }
        }
    }
    



    return 0;
}