#include <iostream>
#include <string.h>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<sstream>
using namespace std;
//1 11 111 1111 -> 10의 제곱수로 커짐, 11은 1+10^1 111은 10^0+10^1+10^2;


int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    
    long long int n;
    long long num=1;
    int cnt=1;
    while(cin>>n){ 
        num=1;
        cnt=1;
        while(1){
            num=num%n;
            if(num==0){
                break;
            }
            else{
                cnt++;
                num=num*10+1;
                num%n;
            }
        }
        cout<<cnt<<'\n';
    }



    return 0;
}