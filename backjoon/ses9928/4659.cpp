#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    while(1){
        bool final=false;
        
        int mcnt=0;
        int jcnt=0;
        string s;
        cin>>s;
        if(s=="end") break;
        
        for(int i=0;i<s.length();i++){
            if(i+1<s.size()&&s[i]==s[i+1]){
                if(s[i]=='e'||s[i]=='o'){
                    continue;
                }
                else{
                    final=false;
                    break;
                }
            }
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                final=true;
                mcnt++;
                jcnt=0;
                
                
                if(mcnt==3){
                    final=false;
                    break;
                }
            }
            else{
                jcnt++;
                mcnt=0;
                
                if(jcnt==3){
                    final=false;
                    break;
                }
            }

        }
        if(final){
            cout<<"<"<<s<<"> is acceptable.\n";
        }
        else{
            cout<<"<"<<s<<"> is not acceptable.\n";
        }
    }



    return 0;
}