#include <iostream>
#include <string.h>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<sstream>
using namespace std;

int map[26][26];
bool visit[26][26];
int house;
int n;
int t;
int dx[]={-1,1,0,0};
int dy[]={0,0,1,-1};
vector<int> v;


void dfs(int x,int y){
    visit[x][y]=true;
    house++;

    for(int i=0;i<4;i++){
        int xx=x+dx[i];
        int yy=y+dy[i];

        if(xx<0||xx>=n||yy<0||yy>=n) continue;
        
        if(map[xx][yy]==1&&!visit[xx][yy]){
            dfs(xx,yy);
            
        }
        
    }
}

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);

    cin>>n;
    int cnt=0;
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        for(int j=0;j<n;j++){
            map[i][j]=str[j]-'0';
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(map[i][j]==1&&visit[i][j]==false){
                house=0;
                dfs(i,j);
                cnt++;
                v.push_back(house);
            }
        }
    }
    sort(v.begin(),v.end());
    cout<<cnt<<'\n';

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<'\n';
    }

    

    



    return 0;
}