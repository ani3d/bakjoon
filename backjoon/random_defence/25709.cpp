#include <iostream>

#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<sstream>
#include<map>
#include<deque>
using namespace std;

int n;
int ans{0};

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    
    cin>>n;

    while(true){
        bool minus=true;

        string temp=to_string(n);

        for(int i=0;i<temp.length();i++){
            if(temp[i]=='1'){
                bool check=false;
                string s="";
                for(int k=0;k<temp.length();k++){
                    if(k==i) continue;
                    if(temp[k]!='0') check=true;
                    if(check) s+=temp[k];
                }
                temp=s;
                minus=false;
                break;
            }
        }
        ans++;

        if(temp=="") break;

        n=stoi(temp);
        if(minus) n--;


    }
    cout<<ans;
    


    



    



    return 0;
}