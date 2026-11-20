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
int reward[4]={0,0,0,0};
void endgame(int score){
    if(score>=35&&score<65) reward[0]++;
    else if(score<95&&score>=65) reward[1]++;
    else if(score>=95&&score<125) reward[2]++;
    else if(score>=125) reward[3]++;
}

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    
    int n;cin>>n;
    int plus=1;
    int tplus=4;
    int score=0;
    int time=0;
    while(n--){
        int ju;
        cin>>ju;
        
        if(ju==1){
            endgame(score);
            time=0;
            score=0;
            plus=1;
            tplus=4;
            continue;
        }
        else if(ju==2){
            if(plus>1)plus/=2;
            else if(plus==1) tplus+=2;
        }
        else if(ju==4){
            time+=56;
        }
        else if(ju==5){
            if(tplus>1){
                tplus-=1;
            }
        }
        else if(ju==6){
            if(plus<32){
                plus*=2;
            }
        }
        time+=tplus;
        score+=plus;
        if(time>240){
            endgame(score);
            score=0;
            time=0;
            plus=1;
            tplus=4;
            
        }
    }
    for(int i=0;i<4;i++){
        cout<<reward[i]<<'\n';
    }

    return 0;   
}