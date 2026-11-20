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

int parent[200001];
int visit[200001];

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    
    int n;
    cin>>n;
    fill_n(parent,200001,-1);
    int before=-1;
    int maxn=-1;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        
        if(num>maxn) maxn=num;

        if(visit[num]==1){
            before=num;
            continue;
        }
        
        if(parent[num]==-1){
            parent[num]=before;
        }
        visit[num]=1;
        before=num;
        
    }
    
    cout<<maxn+1<<'\n';
    for(int i=0;i<maxn+1;i++){
        cout<<parent[i]<<' ';
    }
    


    return 0;
}