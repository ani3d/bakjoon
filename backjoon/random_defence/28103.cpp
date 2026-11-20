#include<iostream>
#include<vector>

using namespace std;
vector<long long> money;
vector<long long> cnt;
long long n,m,x;
void binary(long long int n,long long int s,long long int e,long long int x){
    long long temp=x;
    if(s>=e) return;
    else{

        
        long long int mid=(s+e)/2;
        bool flag=false;
        for(int i=0;i<money.size();i++){
            if((x-mid*money[i])>=mid){
                cnt[i]=mid;
                temp-=mid*money[i];
                flag=true;
                break;
            }
        }
        if(flag){
            binary(mid,0,mid-1,temp);
            binary(mid,mid+1,n,temp);
        }
        else{
            binary(n,0,mid-1,x);
            binary(n,mid,n,x);
        }
        
        
        
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    
    cin>>n>>m>>x;
    money.resize(m,0);
    cnt.resize(m,0);
    for(int i=0;i<m;i++){
        long long a;cin>>a;
        money[i]=a;
    }
    binary(n,0,n,x);

    for(auto & c:cnt){
        cout<<c<<' ';
    }




    return 0;
}
