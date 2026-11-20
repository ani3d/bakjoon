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



int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    int n;
    cin>>n;
    p arr[10001];
    for(int i=0;i<n;i++){
        cin>>arr[i].x>>arr[i].y;
    }
    arr[n].x=arr[0].x;
    arr[n].y=arr[0].y;
    long double ans=0;
    for(int i=0;i<n;i++){
        long double temp=(arr[i].x*arr[i+1].y)-(arr[i+1].x*arr[i].y);
        ans+=temp;
    }
    cout<<fixed;
    cout.precision(1);
    cout<<abs(ans)/2.0L;

    

    return 0;   
}