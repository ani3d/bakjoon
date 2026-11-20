#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int w,h,n,m;
    cin>>w>>h>>n>>m;

    int garo=(w+n)/(n+1);
    int sero=(h+m)/(m+1);
    // cout<<garo<<' '<<sero<<'\n';
    int ans=garo*sero;
    cout<<ans<<'\n';




    return 0;
}