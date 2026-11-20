#include<iostream>
#include<vector>

using namespace std;
int n,m,k;
const int MOD=1'000'000'007;
vector<long long> tree;
vector<long long> a;
void build(){
    for(int i=0;i<n;i++){
        tree[i+n]=a[i];
    }
    for(int i=n-1;i>0;i--){
        tree[i]=(tree[i<<1]*tree[i<<1|1])%MOD;
    }
}
void update(int where,long long value){
    where+=n;
    tree[where]=value;
    while(where>1){
        where>>=1;
        tree[where]=(tree[where<<1]*tree[where<<1|1])%MOD;
    }
}
long long query(int left,int right){
    long long sum=1;
    left+=n;
    right+=n;
    while(left<=right){
        if(left&1)sum=(sum*tree[left++])%MOD;
        if(!(right&1))sum=(sum*tree[right--])%MOD; 
        left>>=1;
        right>>=1;
    }
    return sum;
}



int main(){
    iostream::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m>>k;
    a.resize(n);
    tree.resize(4*n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    build();
    
    for(int i=0;i<m+k;i++){
        int a,b,c;
        cin>>a>>b>>c;
        if(a==1){
            update(b-1,c);
        }
        else if(a==2){
            cout<<query(b-1,c-1)<<'\n';
            
        }
    }


    return 0;
}