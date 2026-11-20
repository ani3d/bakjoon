#include <iostream>
#include <string.h>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<sstream>
using namespace std;


int a,b;
bool visit[10000];

queue<pair<int,string>> q;

void bfs(){
    q.push(make_pair(a,""));
    visit[a]=true;

    while(!q.empty()){
        int num=q.front().first;
        string ord=q.front().second;
        if(num==b){
            cout<<ord<<'\n';
            return;
        }
        q.pop();

        int d,s,l,r;
        d=(num*2)%10000;
        if(!visit[d]){
            visit[d]=true;
            q.push(make_pair(d,ord+"D"));
        }

        s=num-1;
        if(s==-1) s=9999;
        if(!visit[s]){
            visit[s]=true;
            q.push(make_pair(s,ord+"S"));
        }

        l=(num*10)%10000+(num/1000);
        if(!visit[l]){
            visit[l]=true;
            q.push(make_pair(l,ord+"L"));
        }

        r=num/10+(num%10)*1000;
        if(!visit[r]){
            visit[r]=true;
            q.push(make_pair(r,ord+"R"));
        }
    }
}


int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);

    int t;
    cin>>t;
    while(t--){
        cin>>a>>b;
        memset(visit,false,sizeof(visit));
        bfs();
        while(!q.empty()) q.pop();
    }
    



    return 0;
}