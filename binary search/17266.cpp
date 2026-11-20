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

int n,m,x;
int light[100001];

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    
    cin>>n;
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>x;
        light[i]=x;
    }
    int answer=99999999;

    int left=0,right=100000;

    while(left<=right){
        int mid=(left+right)/2;

        bool iscan=true;
        if(light[0]>mid) iscan=false;
        for(int i=0;i<m-1;i++){
            if(light[i+1]-light[i]>mid*2){
                iscan=false;
                break;
            }
        }
        if(n-light[m-1]>mid) iscan=false;
        if(!iscan) left=mid+1;
        else{
            answer=min(answer,mid);
            right=mid-1;
        }
    }
    cout<<answer;


    return 0;
}