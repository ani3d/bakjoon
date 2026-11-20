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

int arr[101];
int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);

    int n;
    cin>>n;
    
    arr[1]=2;
    arr[2]=4;
    int plus=3;
    for(int i=3;i<=n;i++){
        arr[i]=arr[i-1]+plus;
        
        if(i%3!=0){
            plus++;
        }
    }
    cout<<arr[n];



    return 0;   
}