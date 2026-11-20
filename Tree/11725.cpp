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



int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);

    int n,a,b;

    vector<int> v[100001];
    bool visit[100001];
    int ans[100001];
    queue<int> q;
    visit[1]=true;
    q.push(1);

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

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

    for(int i=2;i<=n;i++){
        cout<<ans[i]<<'\n';
    }

    



    return 0;
}