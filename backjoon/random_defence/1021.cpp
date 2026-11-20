#include <iostream>
#include <string.h>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<sstream>
#include<deque>
using namespace std;


deque<int> dq;
int N,M;
int ans;
int idx;

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    cin>>N>>M;

    for(int i=1;i<=N;i++){
        dq.push_back(i);
    }
    int x;

    while(M--){
        cin>>x;

        for(int i=0;i<dq.size();i++){
            if(dq[i]==x){
                idx=i;
                break;
            }
        }
        if(idx<=dq.size()/2){
            while(1){
                if(dq.front()==x){
                    dq.pop_front();
                    break;
                }
                ++ans;
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        else{
            while(1){
                if(dq.front()==x){
                    dq.pop_front();
                    break;
                }
                ++ans;
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }

    cout<<ans;





    return 0;
}