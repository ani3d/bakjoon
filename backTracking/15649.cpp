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

int n,m;
vector<int> result;
bool used[9];
void backtrack(int depth){
    if(depth==m){
        for(int num:result){
            cout<<num<<' ';

        }
        cout<<'\n';
        return;
    }

    for(int i=1;i<=n;i++){
        if(!used[i]){
            used[i]=true;
            result.push_back(i);

            backtrack(depth+1);
            used[i]=false;
            result.pop_back();
        }
    }


}

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    
   
    cin>>n>>m;
    backtrack(0);


    return 0;
}