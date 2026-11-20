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

int a[20001];
int b[20001];
int cnt;
int bsearch(int arr[],int size,int target){
    int start=0;
    int end=size-1;
    int mid;
    int result=size;
    while(start<=end){
        mid=(start+end)/2;
        if(arr[mid]>target){
            result=mid;
            end=mid-1;
        }  
        else{
            start=mid+1;
        }
    }
    return size-result;
}
int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    int t,n,m;

    cin>>t;
    while(t--){
        cnt=0;
        cin>>n>>m;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<m;i++){
            cin>>b[i];
        }

        sort(a,a+n);
        

        for(int i=0;i<m;i++){
            cnt+=bsearch(a,n,b[i]);
        }
        cout<<cnt<<'\n';
        
    }



    return 0;
}