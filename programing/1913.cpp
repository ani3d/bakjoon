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

int arr[1000][1000];
int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    int n,find;
    cin>>n;
    cin>>find;
    int cur=n*n;
    
    int x=0;
    int y=0;
    int dir=0;
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};

    int findx=-1,findy=-1;

    for(int i=0;i<n*n;i++){
        arr[y][x]=cur;
        if(cur==find){
            findy=y+1;
            findx=x+1;
        }
        int nx=x+dx[dir];
        int ny=y+dy[dir];

        if(nx<0||nx>=n||ny<0||ny>=n||arr[ny][nx]!=0){
            dir=(dir+1)%4;
            nx=x+dx[dir];
            ny=y+dy[dir];
        }
        x=nx;
        y=ny;
        cur--;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<findy<<' '<<findx<<'\n';




    return 0;   
}