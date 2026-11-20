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

int N,L;

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    
    cin>>N>>L;
    int alc[1000001];
    int time=0;
    int psum[1000001];
    int now;
    for(int i=0;i<N;i++){
        cin>>alc[i];
    }
    psum[0]=alc[0];
    for(int i=1;i<N;i++){
        psum[i]=psum[i-1]+alc[i];
    }

    
    
    for(int i=0;i<N;i++){
        if(i<L){
            now=psum[i];
            //cout<<now<<' ';
            if(now>=129&&now<=138){
                time++;
            }
        }
        else if(i>=L){
            now=psum[i]-psum[i-L];
            //cout<<now<<' ';
            if(now<=138&&now>=129){
                time++;
            }
        }
        
    }

    cout<<time;



    return 0;
}