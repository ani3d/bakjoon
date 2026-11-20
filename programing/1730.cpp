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

bool sero[11][11];
bool garo[11][11];

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    int n;cin>>n;
    char ord;
    int sx=0,sy=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            garo[i][j]=false;
            sero[i][j]=false;
        }
    }
    cin>>ord;
    if(ord=='D'){
        sero[0][0]=true;
        sy+=1;
        sero[1][0]=true;
    }
    else if(ord=='R'){
        sx+=1;
        garo[0][0]=true;
        garo[0][1]=true;
    }
    while(cin>>ord){
        if(ord=='D'){
            if(sy>=n-1)continue;
            if(garo[sy][sx]){
                sero[sy][sx]=true;
            }
            sy+=1;
            sero[sy][sx]=true;
        }
        else if(ord=='U'){
            if(sy<=0)continue;
            if(garo[sy][sx]){
                sero[sy][sx]=true;
            }
            sy-=1;
            sero[sy][sx]=true;
        }
        else if(ord=='L'){
            if(sx<=0)continue;
            if(sero[sy][sx]){
                garo[sy][sx]=true;
            }
            sx-=1;
            garo[sy][sx]=true;
        }
        else if(ord=='R'){
            if(sx>=n-1)continue;
            if(sero[sy][sx]){
                garo[sy][sx]=true;
            }
            sx+=1;
            garo[sy][sx]=true;
        }
    }   

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(garo[i][j]&&sero[i][j]){
                cout<<'+';
            }
            else if(garo[i][j]&&!sero[i][j]){
                cout<<'-';
            }
            else if(!garo[i][j]&&sero[i][j]){
                cout<<'|';
            }
            else cout<<'.';

        }
        cout<<'\n';
    }
    

    return 0;   
}