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

int n,m,k;
int dr[]={-1,0,1,0};
int dc[]={0,1,0,-1};
int off[9][9];
bool cansee[9][9];
vector<pair<int,int>> cctv;
int min_blind=64;
vector<vector<int>> base={
    {},
    {0},
    {0,2},
    {0,1},
    {0,1,2},
    {0,1,2,3}
};
int num_rot[]={0,4,2,4,4,1};

void copy(int src[9][9],int dst[9][9]){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dst[i][j]=src[i][j];
        }
    }
}

void check(int cur_map[9][9],int r,int c,int dir){
    while(1){
        r+=dr[dir];
        c+=dc[dir];

        if(r<0||r>=n||c<0||c>=m) return;
        if(cur_map[r][c]==6) return;

        if(cur_map[r][c]==0){
            cur_map[r][c]=-1;
        }
    }
}

void apply(int cur_map[9][9],int r,int c,int type,int rotation){
    vector<int>& dirs=base[type];
    for(int base:dirs){
        int final_dir=(base+rotation)%4;
        check(cur_map,r,c,final_dir);
    }
}

void solve(int cctv_idx){
    if(cctv_idx==cctv.size()){
        int blind=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(off[i][j]==0){
                    blind++;
                }
            }
        }
        min_blind=min(min_blind,blind);
        return;
    }
    int r=cctv[cctv_idx].first;
    int c=cctv[cctv_idx].second;
    int type=off[r][c];

    for(int rot=0;rot<num_rot[type];rot++){
        int backup[9][9];
        copy(off,backup);
        apply(off,r,c,type,rot);
        solve(cctv_idx+1);
        copy(backup,off);
    }
}

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>off[i][j];
            if(off[i][j]>=1&&off[i][j]<=5){
                cctv.push_back({i,j});
            }
        }
    }
    solve(0);

    cout<<min_blind<<'\n';
    return 0;   
}