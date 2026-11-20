#include <iostream>
#include <string.h>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<sstream>
using namespace std;

vector<int> vec[20001];
int visit[20001];
int k,v,e;

void dfs(int start){
    if(visit[start]==0){
        visit[start]=2;
    }

    for(int i=0;i<vec[start].size();i++){
        int x=vec[start][i];
        if(visit[x]==0){
            if(visit[start]==2){
                visit[x]=3;
            }
            else if(visit[start]==3){
                visit[x]=2;
            }
            dfs(x);
        }
    }
}

int chk(){
    for(int i=1;i<=v;i++){
        for(int j=0;j<vec[i].size();j++){
            int x=vec[i][j];
            if(visit[i]==visit[x]){
                return false;
            }
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    cin>>k;
    for(int i=0;i<k;i++){
        cin>>v>>e;
        for(int j=0;j<e;j++){
            int a1,a2;
            cin>>a1>>a2;
            vec[a1].push_back(a2);
            vec[a2].push_back(a1);
        }
        for(int j=1;j<=v;j++){
            if(visit[j]==0) dfs(j);
        }

        if(chk()==0) cout<<"NO\n";
        else cout<<"YES\n";

        memset(visit,0,sizeof(visit));
        memset(vec,0,sizeof(vec));
    }


    return 0;
}