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

int arr[1024][1024];
vector<int> v(4);
int temp[1024][1024];

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    
    while(n!=1){
        for(int i=0;i<n;i+=2){
            for(int j=0;j<n;j+=2){
                v[0]=arr[i][j];
                v[1]=arr[i+1][j];
                v[2]=arr[i][j+1];
                v[3]=arr[i+1][j+1];

                sort(v.begin(),v.end());
                temp[i/2][j/2]=v[2];
            }
        }
        
        
        n=n/2;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                arr[i][j]=temp[i][j];
            }
        }



    }

    cout<<arr[0][0];


    return 0;
}