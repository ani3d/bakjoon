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

int num[301][301];



int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);

    int n,m;
    int linesum[301]={0,};
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>num[i][j];
        }
    }
    int k; cin>>k;
    for(int i=0;i<k;i++){
        int p,w,e,r;
        int sum=0;
        cin>>p>>w>>e>>r;
        for(int j=p;j<=e;j++){
            for(int q=w;q<=r;q++){
                sum+=num[j][q];
            }
        }
        cout<<sum<<'\n';

    }
    
    
    
    
    




    return 0;
}