#include <iostream>
#include <string.h>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<sstream>
using namespace std;

long long int a[2000000];
int N,Q;
int x;

int k,add;


int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    
    cin>>N>>Q;
    int move=0;


    for(int i=0;i<N;i++){
        cin>>a[i];
    }

    for(int i=0;i<Q;i++){
        cin>>x;

        if(x==1){
            cin>>k>>add;
            k-=1;
            a[(move+k)%N]+=add;
        }
        else if(x==2){
            cin>>k;
            move=(move+N-k)%N;
        }
        else if(x==3){
            cin>>k;
            move=(move+k)%N;
        }
    }
    
    for(int i=0;i<N;i++){
        cout<<a[(move+i)%N]<<' ';
    }



    return 0;
}