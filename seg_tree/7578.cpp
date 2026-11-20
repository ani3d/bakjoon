#include<iostream>
#include<vector>

using namespace std;
int n;
vector<long long> tree;
int serial_num[500001];
int bline[500001];
void update(int node,int start,int end,int idx){
    if(start<=idx&&idx<=end){
        tree[node]+=1;
        if(start!=end){
            int mid=start+(end-start)/2;
            update(node*2,start,mid,idx);
            update(node*2+1,mid+1,end,idx);
        }
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
long long Sum(int node,int start,int end,int left,int right){
    if(left>end||right<start) return 0;
    if(left<=start&&end<=right) return tree[node];
    int mid=start+(end-start)/2;
    return Sum(node*2,start,mid,left,right)+Sum(node*2+1,mid+1,end,left,right);
}
int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);

    cin>>n;
    tree.resize(4*n);
    for(int i=1;i<=n;i++){
        cin>>serial_num[i];
    }
    int num;
    for(int i=1;i<=n;i++){
        int num;cin>>num;
        bline[num]=i;
    }
    long long result=0;
    for(int i=1;i<=n;i++){
        int bidx=bline[serial_num[i]];
        long long tmp=Sum(1,1,n,bidx+1,n);
        result+=tmp;
        update(1,1,n,bidx);
    }
    cout<<result<<'\n';

    return 0;
}