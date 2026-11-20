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

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    int n,k; cin>>n>>k;
    int fire[200001];
    for(int i=0;i<n;i++){
        cin>>fire[i];
    }
    sort(fire,fire+n);
    int st=0;
    int ed=n-1;
    int cnt=0;
    while(st<ed){
        if(fire[ed]>=k){
            cnt++;
            ed--;
        }
        else if(fire[ed]<k){
            if(fire[ed]+fire[st]>=k){
                cnt++;
                st++;
                ed--;
            }
            else if(fire[ed]+fire[st]<k){
                st++;
            }
        }
    }
    if(fire[st]>=k){
        cnt++;
    }
    if(cnt==0){
        cout<<-1<<'\n';
        return 0;
    }
    cout<<cnt<<'\n';






    return 0;   
}