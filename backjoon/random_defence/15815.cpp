#include <iostream>
#include <string.h>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<sstream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    string sum;
    cin>>sum;

    stack<int> num;
    for(int i=0;i<sum.length();i++){
        
        char c=sum[i];
        if(c>='0'&&c<='9'){
            num.push(c-'0');
        }

        else{
            int a,b;
            a=num.top();
            num.pop();
            b=num.top();
            num.pop();

            if(c=='+'){
                num.push(b+a);
            }
            else if(c=='-'){
                num.push(b-a);
            }
            else if(c=='*'){
                num.push(b*a);
            }
            else if(c=='/'){
                num.push(b/a);
            }
        }
    }
    cout<<num.top()<<'\n';


    return 0;
}