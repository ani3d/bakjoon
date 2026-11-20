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

int arr[1001];
int prefix[1001];

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    
    int t;
    cin>>t;

    while(t--){
        int max=-987654321;
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }
        for(int i=1;i<=n;i++){
            prefix[i]=prefix[i-1]+arr[i];
        }

        for(int i=n;i>=1;i--){
            for(int j=0;j<i;j++){
                int dif=prefix[i]-prefix[j];
                
                if(dif>max){
                    max=dif;
                }
            }
        }

        cout<<max<<'\n';


    }
    




    return 0;
}