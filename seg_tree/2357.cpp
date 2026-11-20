#include<iostream>
#include<vector>

using namespace std;

int n,q;
vector<long long> tree1;
vector<long long>tree2;
vector<long long> a;
pair<int,int> dis;
void build(){
    for(int i=0;i<n;i++){
        tree1[n+i]=a[i];
        tree2[n+i]=a[i];
    }
    for(int i=n-1;i>0;i--){
        if(tree1[2*i]==0){
            tree1[i]=tree1[2*i+1];
        }
        else if(tree1[2*i+1]==0){
            tree1[i]=tree1[2*i];
        }
        else{
            tree1[i]=min(tree1[2*i],tree1[2*i+1]);
        }
        tree2[i]=max(tree2[2*i],tree2[2*i+1]);
    }
    
}
// void update(int where,long long value){
//     where+=n;
//     tree1[where]=value;

//     while(where>1){
//         where>>=1;
//         tree1[where]=tree1[where<<1]+tree1[where<<1|1];
//     }
// }
// long long query(int left,int right){
//     long long sum=0;
//     left+=n;
//     right+=n;

//     while(left<=right){
//         if(left&1)sum+=tree1[left++];
//         if(!(right&1)) sum+=tree1[right--];
//         left>>=1;
//         right>>=1;
//     }
//     return sum;
// }

void search(int st,int ed){
    long long int curst=n+st;
    long long int cured=n+ed;
    long long int minans=1000'000'001;
    long long int maxans=0;
    while(curst<=cured){
        if(curst%2==1){
            minans=min(minans,tree1[curst]);
            maxans=max(maxans,tree2[curst]);
        }
        if(cured%2==0){
            minans=min(minans,tree1[cured]);
            maxans=max(maxans,tree2[cured]);
        }
        curst=(curst+1)/2;
        cured=(cured-1)/2;
    }
    cout<<minans<<' '<<maxans<<'\n';

    
}

int main(){
    iostream::sync_with_stdio(false);
    cin.tie(0);
    int m;
    cin>>n>>m;
    a.resize(n);
    tree1.resize(4*n);
    tree2.resize(4*n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    build();
    // for(int i=0;i<tree1.size()-1;i++){
    //     cout<<tree1[i]<<' ';
    // }
    while(m--){
        cin>>dis.first>>dis.second;
        int st=dis.first;
        int ed=dis.second;
        search(st-1,ed-1);

    }




    return 0;
}