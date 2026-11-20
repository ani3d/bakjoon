#include <iostream>
#include <string.h>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;


int main() {
    ios::sync_with_stdio(0);// 
    cin.tie(0);

    int ans=3000;
    int n,m;
    cin>>n>>m;
    char chess[51][51];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>chess[i][j];
        }
    }
    int temp1=0,temp2=0;
    
    
    for(int x=0;x<n-7;x++){
        for(int y=0;y<m-7;y++){
            
            for(int i=x;i<x+8;i++){
                for(int j=y;j<y+8;j++){
                    if(((i-x+j-y)%2)==0){
                        if(chess[i][j]!='W')
                        temp1++;
                    }
                    else{
                        if(chess[i][j]!='B')
                        temp1++;
                    }
                }
            }
            for(int i=x;i<x+8;i++){
                for(int j=y;j<y+8;j++){
                    if(((i-x+j-y)%2)==0){
                        if(chess[i][j]!='B')
                        temp2++;
                    }
                    else{
                        if(chess[i][j]!='W')
                        temp2++;
                    }
                }
            }
            int res;
            if(temp1<temp2){
                res=temp1;
            }
            else res=temp2;
            
            if(res<ans) ans=res;
            temp1=0;
            temp2=0;
            
            
            
        }
    }
   cout<<ans;
    
    return 0;
}