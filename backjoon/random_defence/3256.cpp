#include <iostream>
#include <string.h>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<sstream>
#include<map>
#include<deque>
using namespace std;
int dp[1001];

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    int n;
    cin>>n;
    int man=n;
    deque<int> arr;
    vector<int> seat;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        seat.push_back(x);
    }
    dp[0]=0;
    
    int fidx=0;
    int time=0;
    while(man>0){
        if(fidx<n){
            arr.push_front(fidx);
            fidx++;
            time++;
        }
        for(int i=0;i<seat.size();i++){
            for(int j=0;j<arr.size();j++){
                if(seat[j]==arr[i]){
                    time+=4;
                    man--;
                    continue;
                }
            }
        }
        for(int i=0;i<arr.size();i++){
            arr[i+1]=arr[i];
        }
        time++;
    }

    cout<<time;
    return 0;   
}