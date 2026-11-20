#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define MAX 8

int n,m,ans;
int map1[MAX][MAX];
int map2[MAX][MAX];
vector<pair<int,int>> virus;
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
void deep(int src[MAX][MAX],int dst[MAX][MAX]){
    for(int row=0;row<n;row++){
        for(int col=0;col<m;col++){
            dst[row][col]=src[row][col];
        }
    }
}
void spreadVirus(){
    queue<pair<int,int>> q;
    for(int i=0;i<virus.size();i++){
        q.push(virus[i]);
    }
    while(!q.empty()){
        int y=q.front().first;
        int x=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(ny>=0&&ny<n&&nx>=0&&nx<m&&map2[ny][nx]==0){
                map2[ny][nx]=2;
                q.push({ny,nx});
            }
        }
    }
    int safe=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(map2[i][j]==0)safe++;
        }
    }
    if(safe>ans){
        ans=safe;
    }
}

void Wall(int cnt,int st){
    if(cnt==3){
        deep(map1,map2);
        spreadVirus();
    }
    else{
        for(int row=st;row<n;row++){
            for(int col=0;col<m;col++){
                if(map1[row][col]==0){
                    map1[row][col]=1;
                    Wall(cnt+1,row);
                    map1[row][col]=0;
                }
            }
        }
    }
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int row=0;row<n;row++){
        for(int col=0;col<m;col++){
            cin>>map1[row][col];
            if(map1[row][col]==2){
                virus.push_back({row,col});
            }
        }
    }
    Wall(0,0);
    cout<<ans;
    return 0;
}