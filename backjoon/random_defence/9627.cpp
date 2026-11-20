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


string value;
string num[20];
int len=-1,temp,v;
string first[11]={"","one","two","three","four","five","six","seven","eight","nine","ten"};
string second[10]={"eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
string third[11]={"","","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
string hund="hundred";



vector<int> fullnum;
int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>num[i];
        len+=num[i].length();    
    }

    for(int i=1;i<1000;i++){
        temp=len+i;
        if(temp<=10){
            value=first[temp];
        }
        else if(temp<=19){
            value=second[temp-11];
        }
        else if(temp<=99){
            value=third[temp/10]+first[temp-(temp/10)*10];
        }
        else{
            value=first[(temp/100)]+hund;

            v=temp-(temp/100)*100;

            if(v<=10){
                value+=first[v];
            }
            else if(v<=19){
                value+=second[v-11];
            }
            else if(v<=99){
                value+=third[v/10]+first[v-(v/10)*10];
            }
        }
    

        if(value.length()+len==temp){
            for(int j=0;j<n;j++){
                if(num[j]!="$") cout<<num[j];
                else cout<<value;
                cout<<" ";
            }
            break;
        }
    }







    return 0;
}