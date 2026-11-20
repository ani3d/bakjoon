#include <iostream>
#include <string.h>
#include<string>
#include<algorithm>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;


int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);

    string word;
    cin>>word;
    int len=static_cast<int>(word.length());
    string ans;
    for(int i=1;i<=len-2;i++){
        for(int j=1;j<=len-i-1;j++){
            string a=word.substr(0,i);
            string b=word.substr(i,j);
            string c=word.substr(i+j);

            reverse(a.begin(),a.end());
            reverse(b.begin(),b.end());
            reverse(c.begin(),c.end());

            string ret=a+b+c;

            if(ans=="") ans=ret;
            else if(ans>ret) ans=ret;

        }

    }

    cout<<ans<<'\n';





    return 0;
}