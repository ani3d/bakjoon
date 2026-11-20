#include <iostream>
#include <string.h>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<sstream>
using namespace std;
int num[1025][1025];

int check(int x,int y,int n){
    int ans[4];

    if(n==1) return num[x][y];

    int lu=check(x,y,n/2);
    int ld=check(x+n/2,y,n/2);
    int ru=check(x,y+n/2,n/2);
    int rd=check(x+n/2,y+n/2,n/2);

    ans[0]=lu;
    ans[1]=ld;
    ans[2]=ru;
    ans[3]=rd;

    sort(ans,ans+4);
    return ans[1];


    

}

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    
    int n;
    cin>>n;

    
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>num[i][j];
        }
    }

    cout<<check(0,0,n);





    return 0;
}