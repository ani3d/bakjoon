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
int n,m,h;
int sx,sy;
vector<int> milk;
vector<pair<int,int>> mint;
int ans;
void dfs(int x,int y,int hp,int cnt){
    
    int go_home=abs(x-sx)+abs(y-sy);
    if(hp>=go_home){
        ans=max(cnt,ans);
    }
    for(int i=0;i<mint.size();i++){
        int need=abs(x-mint[i].first)+abs(y-mint[i].second);
        if(milk[i]) continue;
        if(hp<need)continue;
        milk[i]=1;
        dfs(mint[i].first,mint[i].second,hp-need+h,cnt+1);
        milk[i]=0;
    }
    
}

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);

    cin>>n>>m>>h;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int a;
            cin>>a;
            if(a==1){
                sx=i;
                sy=j;
            }
            else if(a==2){
                mint.push_back({i,j});
            }
        }
    }
    milk.resize(mint.size(),0);
    dfs(sx,sy,m,0);
    cout<<ans<<'\n';
    

    return 0;   
}