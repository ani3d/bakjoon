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
const int INF=1e9;

int dist[1000001];
vector<pair<int,int>> nodes[300001];

void Dijkstra(int start){
    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(0,start));
    dist[start]=0;

    while(!pq.empty()){
        int here=pq.top().second;
        int cost=-pq.top().first;
        pq.pop();

        if(dist[here]<cost) continue;

        for(int i=0;i<nodes[here].size();i++){
            int via=cost+nodes[here][i].first;

            if(via<dist[nodes[here][i].second]){
                dist[nodes[here][i].second]=via;
                pq.push(make_pair(-via,nodes[here][i].second));
            } 

        }


    }
}

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    
    int N,M,K,X;

    cin>>N>>M>>K>>X;
    for(int i=1;i<=N;i++){
        dist[i]=INF;
    }
    for(int i=1;i<=M;i++){
        int a,b;
        cin>>a>>b;
        nodes[a].push_back({1,b});
    }

    Dijkstra(X);
    vector<int> answer;
    for(int i=1;i<=N;i++){
        if(dist[i]==K){
            answer.push_back(i);
        }
    }

    if(answer.empty()){
        cout<<-1;
    }
    else{
        for(int i=0;i<answer.size();i++){
            cout<<answer[i]<<'\n';
        }
    }







    return 0;
}