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

int num[1000001];
int arr[1000001];

int binarysearch(int arr[],int len,int target){
    int l=0;
    int r=len-1;
    int mid;
    while(l<=r){
        mid=(l+r)/2;
        if(target==arr[mid]){
            return 1;
        }

        else if(target<arr[mid])
        {
            r=mid-1;
        }
        else l=mid+1;


    }
    return 0;

}


int t,n,m;
int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        for(int j=0;j<n;j++){
            cin>>num[j];
        }
        sort(num,num+n);

        cin>>m;
        for(int k=0;k<m;k++){
            cin>>arr[k];
        }

        for(int l=0;l<m;l++){
            if(binarysearch(num,n,arr[l])){
                cout<<1<<'\n';
            }
            else cout<<0<<'\n';
        }

    }
    


    return 0;
}