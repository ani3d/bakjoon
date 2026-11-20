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

struct p{
    int x,y;
};

int ccw(p a,p b,p c){
    long long int ret=(b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
    return !ret? 0:(ret<0?-1:1);
}

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    p arr[4];
    for(int i=0;i<3;i++){
        cin>>arr[i].x>>arr[i].y;
    }
    int ans=ccw(arr[0],arr[1],arr[2]);
    cout<<ans;

    return 0;   
}