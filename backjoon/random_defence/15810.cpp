#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int n,m;
    cin>>n>>m;
    vector<long long int> time;
    for(int i=0;i<n;i++){
        int t;cin>>t;
        time.push_back(t);
    }
    long long int cnt=0;
    sort(time.begin(),time.end());
    long long int nowtime=-1;
    long long int l=1;long long int r=1e15;
    while(l<=r){
        long long mid=(l+r)/2;
        long long cnt=0;
        for(int i=0;i<n;i++){
            cnt+=(mid/time[i]);
        }
        if(cnt>=m){
            nowtime=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    cout<<nowtime<<'\n';
    return 0;
}