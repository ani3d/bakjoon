#include <iostream>
#include <string.h>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<sstream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);

    int n,m,b;
    int height;
    int mintime=1e9;
    int time=0;
    cin>>n>>m>>b;
    int mosth;
    int map[501][501];

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>map[i][j];
        }
    }


    for(int h=0;h<=256;h++){
        int inven=0;
        int remove=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int height=map[i][j]-h;
                if(height>=0) remove+=height;
                else if(height<0) inven-=height;
            }
        }
        if(remove+b>=inven){
            time=remove*2+inven;
            if(mintime>=time){
                mintime=time;
                mosth=h;
            }
        }


    }



    cout<<mintime<<' '<<mosth;


    return 0;
}