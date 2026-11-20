#include<iostream>
#include<vector>

using namespace std;
const int mod=1'000'000'009;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    

    int t;cin>>t;
    while(t--){

        long long holdp[100001];
        long long jjakdp[100001];
        holdp[1]=1;
        jjakdp[1]=0;
        jjakdp[2]=1;
        holdp[2]=1;
        holdp[3]=2;
        jjakdp[3]=2;

    
        int n;
        cin>>n;
        for(int i=4;i<=n;i++){
            holdp[i]=holdp[i-2]+jjakdp[i-3]+jjakdp[i-1];
            jjakdp[i]=holdp[i-1]+jjakdp[i-2]+holdp[i-3];
        }
        cout<<holdp[n]<<' '<<jjakdp[n]<<'\n';
    }


    return 0;
}