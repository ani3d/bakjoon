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

int t,h,w;

int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};

vector<vector<int>> height;
vector<vector<pair<int,int>>> parent;
map<pair<int,int>,char> basin;
char current;

pair<int,int> find(pair<int,int> cell){
    int x=cell.first,y=cell.second;
    if(parent[x][y]!=cell) parent[x][y]=find(parent[x][y]);
    return parent[x][y];
}

void flow(int x,int y){
    int minh=height[x][y];
    pair<int,int> next={x,y};

    for(int d=0;d<4;++d){
        int nx=x+dx[d],ny=y+dy[d];
        if(nx>=0&&ny>=0&&nx<h&&ny<w){
            if(height[nx][ny]<minh){
                minh=height[nx][ny];
                next={nx,ny};
            }

        }
    }
    if(next!=make_pair(x,y)){
        parent[x][y]=next;
    }
}

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    
    
    cin>>t;
    for(int test=1;test<=t;test++){
        cin>>h>>w;
        height.assign(h,vector<int>(w));
        parent.assign(h,vector<pair<int,int>>(w));

        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin>>height[i][j];
            }
        }

        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                parent[i][j]={i,j};
            }
        }

        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                flow(i,j);
            }
        }

        cout<<"Case #"<<test<<":\n";
        basin.clear();
        current='a';
        
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                pair<int,int> root=find({i,j});
                if(!basin.count(root)){
                    basin[root]=current++;
                }
                cout<<basin[root]<<" ";
            }
            cout<<'\n';
        }
    }
    


    return 0;
}