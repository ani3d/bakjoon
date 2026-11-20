#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int q;cin>>q;
    
    long long Minn=-(1e18+1);
    long long Maxn=1e18+1;
    
    int cnt=0;
    int flag=0;
    int ans=111223;
    int cutans=111223;
    
    while(q--){
        cnt++;
        long long int x;
        cin>>x;
        char ord;
        cin>>ord;
        
        if(ord=='^'){
            Minn=max(Minn,x+1);
        }

        if(ord=='v'){
            Maxn=min(Maxn,x-1);
        }

        if(Maxn==Minn){
            flag=1;
            ans=min(ans,cnt);
        }
        
        if(Maxn<Minn){
            flag=2;
            cutans=min(cutans,cnt);
        }   
    }
    
    if(flag==0){
        cout<<"Hmm..."<<'\n';
    }
    else if(flag==1){
        cout<<"I got it!"<<'\n';
        cout<<ans<<'\n';
    }
    else if(flag==2){
        cout<<"Paradox!\n";
        cout<<cutans<<'\n';
    }



    return 0;
}