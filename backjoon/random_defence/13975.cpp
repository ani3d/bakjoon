#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long int t,k,money;

    cin>>t;
    while(t--){
        priority_queue<long long int,vector<long long int>,greater<long long int>> book;
        cin>>k;
        long long int a;    
        long long ans=0;   
        for(int i=0;i<k;i++){
            cin>>a;
            book.push(a);
        }
        // for(int i=0; i<k;i++){
        //     cout<<book.top()<<' ';
        //     book.pop();
        // }
       
        long long int temp=0;
        while(book.size()>1){
            temp+=book.top();
            book.pop();
            temp+=book.top();
            book.pop();
            ans+=temp;
            book.push(temp);
            temp=0;
        }
    
        cout<<ans<<'\n';
    }


    return 0;
}