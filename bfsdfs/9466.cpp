#include <iostream>
#include <string.h>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<sstream>
using namespace std;

int arr[100001];
bool visit[100001];
bool done[100001];
int t,n;
int cnt=0;

void dfs(int n){
    visit[n]=true;
    int next=arr[n];

    if(!visit[next]){
        dfs(next);
    }
    else if(!done[next]){
        for(int i=next;i!=n;i=arr[i]){
            cnt++;
        }
        cnt++;
    }
    done[n]=true;
    
}



int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    
    cin>>t;
    while(t--){
        cnt=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>arr[i];
            visit[i]=false;
            done[i]=false;
        }
        for(int i=1;i<=n;i++){
            if(!visit[i]){
                dfs(i);
            }
        }

        cout<<n-cnt<<'\n';
        
        
    }



    return 0;
}