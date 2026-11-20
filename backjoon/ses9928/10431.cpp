#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int p;cin>>p;
    while(p--){
        int t; cin>>t;
        int height[21];
        int cnt=0;
        for(int i=0;i<20;i++){
            cin>>height[i];
        }
        for(int i=0;i<20;i++){
            for(int j=0;j<i;j++){
                if(height[j]>height[i]){
                    cnt++;
                }
            }
        }
        cout<<t<<' '<<cnt<<'\n';
    }


    return 0;
}