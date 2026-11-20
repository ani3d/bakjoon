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
    
    string input;
    
    int t;
    
    cin>>t;
    
    while(t--){
        long long int ans=0;    
        cin>>input;
        
        for(int i=0;i<input.size();i++){
            if(input[i]=='6') input[i]='9';
        }
        sort(input.rbegin(),input.rend());
        
        int total=1<<input.size();
        for(int brute=1;brute<total-1;brute++){
            string num1="";
            string num2="";
            

            for(int j=0;j<input.size();j++){
                if(brute&(1<<j)) num1+=input[j];
                else num2+=input[j];
                
            }

            long long int front=stoll(num1);
            long long int back=stoll(num2);

          

            ans=max(ans,front*back);
        }
        
        
        
        cout<<ans<<'\n';
        
        
        


    }







    return 0;
}