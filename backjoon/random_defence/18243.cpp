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

int n,k;
vector<int> v[101];
int cnt=0;


bool bfs(int k){
    queue<int> q;
    q.push(k);
    int sol[101]={};
    bool visit[101]={};
    visit[k]=true;
    

    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int i:v[x]){
            if(visit[i]==false){
                visit[i]=true;
                sol[i]=sol[x]+1;
                q.push(i);
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(visit[i]==false||sol[i]>6){
            return false;
        }
    }
    return true;
}


int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    
    cin>>n>>k;
    for(int i=0;i<k;i++){
        int a1,a2; cin>>a1>>a2;
        v[a1].push_back(a2);
        v[a2].push_back(a1);
    }
    for(int i=1;i<=n;i++){
        if(!bfs(i)){
            cout<<"Big World!";
            return 0;
        }
    }

    cout<<"Small World!";

    return 0;
}