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
long long int n,m,a,b,c;
long long int dist[101][101];


int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    
    cin>>n;
    cin>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) dist[i][j]=0;
            else dist[i][j]=INF;
        }
    }
    for(int i=1;i<=m;i++){
        cin>>a>>b>>c;
        if(dist[a][b]==INF){
            dist[a][b]=c;
            
        }
        else{
            dist[a][b]=min(c,dist[a][b]);
        }
        
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dist[i][k]+dist[k][j]<dist[i][j]){
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(dist[i][j]==INF) cout<<0<<' ';
            else cout<<dist[i][j]<<' ';
        }
        cout<<'\n';
    }


    return 0;
}