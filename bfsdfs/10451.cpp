#include <iostream>
#include <string.h>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<sstream>
using namespace std;

int t,N;
vector<int> v[1001];
bool visit[1001];

void dfs(int n){
    visit[n]=true;

    for(int i=0;i<v[n].size();i++){
        if(!visit[v[n][i]]){
            dfs(v[n][i]);
        }
    }

}
int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    int cnt=0;

    cin>>t;
    while(t--){
        cin>>N;
        for(int i=1;i<=N;i++){
            int a1;
            cin>>a1;
            v[i].push_back(a1);
        }
        for(int i=1;i<=N;i++){
            if(!visit[i]){
                dfs(i);
                cnt++;
            }
        }
        cout<<cnt<<'\n';
        cnt=0;
        memset(v,0,sizeof(v));
        memset(visit,false,sizeof(visit));
    }



    return 0;
}