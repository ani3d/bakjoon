#include <iostream>
#include <string.h>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<sstream>
using namespace std;
int n;
vector<int> v[100001];
bool visit[100001];
int ans[100001];
void bfs(){
    queue<int> q;
    visit[1]=true;
    q.push(1);

    while(!q.empty()){
        int par=q.front();
        q.pop();

        for(int i=0;i<v[par].size();i++){
            int child=v[par][i];
            if(!visit[child]){
                ans[child]=par;
                visit[child]=true;
                q.push(child);
            }
        }
    }

}
int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    cin>>n;
    int a,b;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    bfs();

    for(int i=2;i<=n;i++){
        cout<<ans[i]<<'\n';
    }


    



    return 0;
}