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

int x[3];
int y[3];
int range[3];

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    
    int a,b;
    for(int i=0;i<3;i++){
        cin>>a>>b;
        x[i]=a;
        y[i]=b;
    }
    range[0]=(x[1]-x[0])*(x[1]-x[0])+(y[1]-y[0])*(y[1]-y[0]);
    range[1]=(x[1]-x[2])*(x[1]-x[2])+(y[1]-y[2])*(y[1]-y[2]);
    range[2]=(x[2]-x[0])*(x[2]-x[0])+(y[2]-y[0])*(y[2]-y[0]);
    //기울기
    
    int cross = (x[1]-x[0])*(y[2]-y[0]) - (y[1]-y[0])*(x[2]-x[0]);
    if (cross == 0) {
        cout << "X";
        return 0;
    }

    int maxrange=range[0];
    int idx=0;
    for(int i=0;i<2;i++){
        if(maxrange<range[i]){
            maxrange=range[i];
            idx=i;
        }
    }

   

    if(range[0]==range[1]&&range[1]==range[2]){
        cout<<"JungTriangle";
        return 0;
    }
    for(int i=0;i<2;i++){
       // cout<<range[i]<<' ';
    }
    for(int i=0;i<3;i++){
        if(range[0]==range[2]){
            int max=range[1];
            if(max*max>range[i]*range[i]){
                cout<<"Dunkak2Triangle";
                return 0;
            }else if(max*max==range[i]*range[i]){
                cout<<"Jikkak2Triangle";
                return 0;
            }
            else{
                cout<<"Yeahkak2Triangle";
                return 0;
            }
        }
        if(range[i]==range[i+1]){
            int max=range[2-i];
            if(max>range[i]){
                cout<<"Dunkak2Triangle";
                return 0;
            }else if(max==range[i]){
                cout<<"Jikkak2Triangle";
                return 0;
            }
            else {
                cout<<"Yeahkak2Triangle";
                return 0;
            }
        }
    }
    if(range[0]!=range[1]&&range[1]!=range[2]&&range[0]!=range[2]){
        if(idx==0){
            if((maxrange)>range[1]+range[2]){
                cout<<"DunkakTriangle";
                return 0;
            }
            else if((maxrange==range[1]+range[2])){
                cout<<"JikkakTriangle";
                return 0;
            }
            else {
                cout<<"YeahkakTriangle";
                return 0;
            }
        }
        else if(idx==1){
            if((maxrange)>range[0]+range[2]){
                cout<<"DunkakTriangle";
                return 0;
            }
            else if((maxrange==range[0]+range[2])){
                cout<<"JikkakTriangle";
                return 0;
            }
            else {
                cout<<"YeahkakTriangle";
                return 0;
            }

        }
        else if(idx==2){
            if((maxrange)>range[1]+range[0]){
                cout<<"DunkakTriangle";
                return 0;
            }
            else if((maxrange==range[1]+range[0])){
                cout<<"JikkakTriangle";
                return 0;
            }
            else {
                cout<<"YeahkakTriangle";
                return 0;
            }
        }

    }


    return 0;
}