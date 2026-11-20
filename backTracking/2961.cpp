#include <iostream>
#include <string.h>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<sstream>
#include<map>
#include<climits>

using namespace std;

int n;
vector<pair<int,int>> taste;
bool visit[10];
int Mindif=INT_MAX;

void Dfs(int sour,int bitter,int num){
    if(num>=1){
        Mindif=min(Mindif,abs(sour-bitter));
    }
    for(int i=0;i<n;i++){
        if(!visit[i]){
            visit[i]=true;
        
            Dfs(sour*taste[i].first,bitter+taste[i].second,num+1);
            visit[i]=false;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);

    cin>>n;
    taste.resize(n);
    for(int i=0;i<n;i++){
        cin>>taste[i].first>>taste[i].second;
    }
    Dfs(1,0,0);
    cout<<Mindif<<'\n';

    

    return 0;   
}