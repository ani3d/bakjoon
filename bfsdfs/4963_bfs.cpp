#include <iostream>
#include <string.h>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<sstream>
using namespace std;

int w,h;
int map[51][51];
int visit[51][51];
int dx[]={1,1,0,-1,-1,-1,0,1};
int dy[]={0,1,1,1,0,-1,-1,-1};





void bfs(int a,int b){
    queue<pair<int,int>> q;
    q.push(make_pair(a,b));
    
    while(!q.empty()){
        int y=q.front().first;
        int x=q.front().second;
        q.pop();

        for(int i=0;i<8;i++){
            int nextx=x+dx[i];
            int nexty=y+dy[i];

            if(nextx<0||nextx>=w||nexty<0||nexty>=h) continue;

            if(map[nexty][nextx]==1&&!visit[nexty][nextx]){
                q.push({nexty,nextx});
                visit[nexty][nextx]=1;
            }
        }
    }
    

}

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    
    while(1){
        int cnt=0;
        cin>>w>>h;
        if(!w&&!h) break;

        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin>>map[i][j];
            }
        }

        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(!visit[i][j]&&map[i][j]){
                    visit[i][j]=1;
                    bfs(i,j);
                    cnt++;
                }
            }
        }
        cout<<cnt<<'\n';

        memset(visit,0,sizeof(visit));
        memset(map,0,sizeof(map));
    }
    return 0;
}