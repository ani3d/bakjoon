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
    long long int x,y;
    bool operator<(const p&o) const{
        return x!=o.x?x<o.x:y<o.y;
    }
};

int ccw(p a,p b,p c){
    long long int ret=(b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
    if(ret>0) return 1;
    else if(ret==0) return 0;
    else return -1;
}

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    p a,b,c,d;
    cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y>>d.x>>d.y;
    long long int l1=ccw(a,b,c)*ccw(a,b,d);
    long long int l2=ccw(c,d,a)*ccw(c,d,b);
    if(l1<0&&l2<0) cout<<"1";
    else cout<<"0";
    

    return 0;   
}