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
int n,k;
int dist[101][101];

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) dist[i][j]=0;
            else dist[i][j]=INF;
        }
    }
    int a,b;
    for(int i=1;i<=k;i++){
        cin>>a>>b;
        dist[a][b]=1;
        dist[b][a]=1;
    }
    for(int k=1;k<=n;k++){
        for(int j=1;j<=n;j++){
            for(int i=1;i<=n;i++){
                if(dist[i][k]+dist[k][j]<dist[i][j]) dist[i][j]=dist[i][k]+dist[k][j];
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(dist[i][j]>=7){
                cout<<"Big World!";
                return 0;
            }
        }
    }

    cout<<"Small World!";



    return 0;
}