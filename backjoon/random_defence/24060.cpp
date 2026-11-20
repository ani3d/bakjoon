#include <iostream>
#include <string.h>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<sstream>
using namespace std;



int inputcnt=0;

void merge_(int* A,int p,int q,int r,int k){
    int tmp[r+2];
    int i=p,j=q+1,t=1;
    while(i<=q&&j<=r){
        if(A[i]<=A[j]){
            tmp[t++]=A[i++];
        }
        else{
            tmp[t++]=A[j++];
        }
    }
    while(i<=q){
        tmp[t++]=A[i++];
    }
    while(j<=r){
        tmp[t++]=A[j++];
    }
    i=p,t=1;
    while(i<=r){
        A[i++]=tmp[t++];
        if(++inputcnt==k) cout<<tmp[t-1];
    }
    

}

void merge_sort(int* A,int start,int end,int k){
    int p=start,r=end;
    int q;
    if(p<r){
        q=(p+r)/2;
        merge_sort(A,p,q,k);
        merge_sort(A,q+1,r,k);
        merge_(A,p,q,r,k);
    }

}




int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);

    int n,k;
    cin>>n>>k;
    int *A=new int[n+1];
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    merge_sort(A,0,n-1,k);
    if(inputcnt<k) cout<<-1;



    delete[] A;
    



    return 0;
}