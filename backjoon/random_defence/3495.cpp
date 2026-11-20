#include <iostream>
#include <string.h>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<sstream>

using namespace std;

char map[101][101];

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    
    int h,w;

    cin>>h>>w;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>map[i][j];
        }
    }
    int cnt=0;
    float answer=0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(map[i][j]=='/'||map[i][j]=='\\') cnt++;
            if(cnt%2!=0&&map[i][j]!='.') answer+=0.5; 
            if(cnt%2!=0&&map[i][j]=='.') answer+=1;
            if(cnt%2==0&&map[i][j]!='.') answer+=0.5;
        }
    }

    cout<<answer;



    return 0;
}