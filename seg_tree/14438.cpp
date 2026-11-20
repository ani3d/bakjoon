#include<iostream>
#include<vector>

using namespace std;
int n,m,k;

vector<long long> tree;
vector<long long> a;
void build(){
    for(int i=0;i<n;i++){
        tree[i+n]=a[i];
    }
    for(int i=n-1;i>0;i--){
        tree[i]=min(tree[i<<1],tree[i<<1|1]);
    }
}
void update(int where,long long value){
    where+=n;
    tree[where]=value;
    while(where>1){
        where>>=1;
        tree[where]=min(tree[where<<1],tree[where<<1|1]);
    }
}
// long long query(int left,int right){
//     long long sum=1;
//     left+=n;
//     right+=n;
//     while(left<=right){
//         if(left&1)sum=(sum*tree[left++]);
//         if(!(right&1))sum=(sum*tree[right--]); 
//         left>>=1;
//         right>>=1;
//     }
//     return sum;
// }
void search(int st,int ed){
    long long int curst=n+st;
    long long int cured=n+ed;
    long long int minans=1'000'000'001;
    while(curst<=cured){
        if(curst%2==1){
            minans=min(minans,tree[curst]);
        }
        if(cured%2==0){
            minans=min(minans,tree[cured]);
        }
        curst=(curst+1)/2;
        cured=(cured-1)/2;
    }
    cout<<minans<<'\n';
}




int main(){
    iostream::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    a.resize(n);
    tree.resize(4*n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    build();
    cin>>m;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        if(a==1){
            update(b-1,c);
        }
        else if(a==2){
            search(b-1,c-1);
        }
    }


    return 0;
}