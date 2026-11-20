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
vector<int> circle[1001];
int visit[1001];
int color[1001];
bool finished[1001];
bool cycle=true;
void dfs(int cur,int prev){
    for(int next:circle[cur]){
        if(next==prev) continue;
        if(visit[next]==0){
            if(color[cur]==1){
                if(color[next]==1){
                    cout<<"impossible"<<'\n';
                }
                else color[next]=2;
                
            }
            else if(color[cur]==2){
                if(color[next]==2){
                    cout<<"impossible"<<'\n';
                }
                else color[next]=1;
            }
        }
        visit[next]=1;
        
        dfs(next,cur);

    }

}
int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    int t;cin>>t;
    while(t--){
        cycle=true;
        cin>>n>>m;
        for(int i=0;i<m;i++){
            int n1,n2;
            cin>>n1>>n2;
            circle[n1].push_back(n2);
            circle[n2].push_back(n1);
        }
        
        for(int i=1;i<=n;i++){
            if(visit[i]){
                continue;
            }
            cycle=true;
            dfs(i,0);
        }
        cout<<"possible"<<'\n';
        
    }
    

    return 0;   
}