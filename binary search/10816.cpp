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

int arr[500001];

int lower(int start,int end,int target){
    int mid;
    while(end>start){
        mid=(start+end)/2;
        if(arr[mid]>=target) end=mid;
        else start=mid+1;
    }
    return end;
}

int upper(int start,int end,int target){
    int mid;
    while(end>start){
        mid=(start+end)/2;
        if(arr[mid]>=target) end=mid;
        else start=mid+1;
    }
    return end;
}


int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    
    int n,m;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    sort(arr,arr+n);

    cin>>m;
    for(int i=0;i<m;i++){
        int num;
        cin>>num;
        cout<<upper_bound(arr,arr+n,num)-lower_bound(arr,arr+n,num)<<' ';
    }
    


    return 0;
}