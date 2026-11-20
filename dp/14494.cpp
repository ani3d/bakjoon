#include <iostream>
#include <string.h>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<sstream>
using namespace std;

int arr[1001][1001];

void chk(int n,int m){
    arr[1][1]=1;
    arr[2][1]=1;
    arr[1][2]=1;
    
    for(int i=1;i<=n;i++){
        arr[i][1]=1;
    }
    for(int i=1;i<=m;i++){
        arr[1][i]=1;
    }

    for(int i=2;i<=n;i++){
        for(int j=2;j<=m;j++){
            arr[i][j]=(arr[i-1][j]+(arr[i][j-1]+arr[i-1][j-1])%1000000007)%1000000007;
        }
    }

    
    

}

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);

    int n,m;
    cin>>n>>m;
    chk(n,m);
    cout<<arr[n][m];

        



    return 0;
}