#include <iostream>
#include <string.h>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<sstream>
#include<unordered_map>
using namespace std;

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);

    int t;
    cin>>t;
    int n,m;
    
    while(t--){
        unordered_map<int,int> arr;
        vector<long long> ans;
        long long int team1=0;
        long long int team2=0;
        cin>>n>>m;
        long long cnt1=(n+1)/2;
        long long cnt2=n/2;
        team1=cnt1*cnt1;
        team2=cnt2*(cnt2+1);
        
        ans.push_back(team1-team2);
        for(int i=1;i<m;i++){
            int temp;
            cin>>temp;
            arr[temp]++;
            if(temp&1){
                if(arr[temp]&1){
                    team2+=temp;
                    team1-=temp;
                }
                else{
                    team1+=temp;
                    team2-=temp;
                }
            }
            else{
                if(arr[temp]&1){
                    team1+=temp;
                    team2-=temp;
                   
                }
                else{
                    team1-=temp;
                    team2+=temp;
                   
                }
            }
            ans.push_back(team1-team2);
            

        }
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<' ';
        }
        cout<<'\n';
        cout.flush();
        
    }
    


    
    

    return 0;
}