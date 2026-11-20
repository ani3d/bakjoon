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

vector<int> v[10001];
int visit[10001];


int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    
    int a,b;
    cin>>a>>b;

    int N,M;
    cin>>N>>M;
    fill_n(visit,10001,-1);
    int cnt=0;

    for(int i=0;i<M;i++){
        int n1,n2;
        cin>>n1>>n2;
        v[n1].push_back(n2);
        v[n2].push_back(n1);
    }

    queue<int> q;
    q.push(a);
    visit[a]=0;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        if(x==b) break;
        else{
            for(int i=0;i<v[x].size();i++){
                int next=v[x][i];
                if(visit[next]==-1){
                    visit[next]=visit[x]+1;
                    q.push(next);
                }
            }
        }
    }
    
    cout<<visit[b];


    return 0;
}