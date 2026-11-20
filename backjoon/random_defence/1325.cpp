#include <iostream>
#include <string.h>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<sstream>
using namespace std;


vector<int> v[10001];
bool visit[10001];
int result[10001];
int N,M;
int cnt=0,mm=0;

/*dfs 방식의 문제풀이
void dfs(int n){
    cnt++;

    for(int i=0;i<v[n].size();i++){
        int nn=v[n][i];

        if(visit[nn]) continue;

        visit[nn]=true;
        dfs(nn);
    }
}
    */
   //bfs 방식 풀이
void bfs(int n){
    queue<int> q;
    int count=1;

    q.push(n);
    visit[n]=true;

    while(!q.empty()){
        int a=q.front();

        q.pop();

        for(int i=0;i<v[a].size();i++){
            int na=v[a][i];
            
            if(visit[na]) continue;
            q.push(na);
            visit[na]=true;
            count++;
        }
    }
    result[n]=count;
    mm=max(count,mm);

}

//dfs 솔루션
/*
void solution() {
    for (int i = 1; i <= N; i++) {
        memset(visit, false, sizeof(visit));

        cnt = 0;

        visit[i] = true;
        dfs(i);

        result[i] = cnt;
        mm = max(mm, cnt);
    }

    for (int i = 1; i <= N; i++) {
        if (result[i] == mm) {
            cout << i << " ";
        }
    }
}
    */

//bfs 솔루션
void solution(){
    for(int i=1;i<=N;i++){
        memset(visit,false,sizeof(visit));
        cnt=0;
        visit[i]=true;
        bfs(i);
    }
        for(int i=1;i<=N;i++){
            if(result[i]==mm){
                cout<<i<<" ";
            }
        }
    
}


int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    
    cin>>N>>M;
    
    int a,b;
    for(int i=0;i<M;i++){
        cin>>a>>b;
        v[b].push_back(a);
    }
    
    solution();



    return 0;
}





