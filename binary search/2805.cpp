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

long long int tree[10000001];

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    
    long long int n,m,max=0;

    cin>>n>>m;

    for(int i=0;i<n;i++){
        cin>>tree[i];
    }
    sort(tree,tree+n);

    long long int low=0;
    long long int high=tree[n-1];

    while(low<=high){
        long long int sum=0;
        long long int cut=(high+low)/2;

        for(int i=0;i<n;i++){
            if(tree[i]-cut>0) sum=sum+tree[i]-cut;
        }
        if(sum>=m){
            max=cut;
            low=cut+1;
        }
        else high=cut-1;
    }

    cout<<max;


    return 0;
}