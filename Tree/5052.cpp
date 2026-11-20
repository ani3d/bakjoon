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

struct TrieNode{
    TrieNode* children[10];
    bool isend;

    TrieNode(){
        for(int i=0;i<10;++i){
            children[i]=nullptr;
        }
        isend=false;
    }

    bool insert(const string& number){
        TrieNode* node=this;
        for(char c: number){
            int idx=c-'0';
            if(!node->children[idx]){
                node->children[idx]=new TrieNode();
            }
            node=node->children[idx];

            if(node->isend) return false;

        }
        node->isend=true;

        for(int i=0;i<10;i++){
            if(node->children[i]) return false;
        }
        
        return true;

    }
};

bool isConsistent(vector<string>& phoneNumbers){
    TrieNode root;

    for(const string& number: phoneNumbers){
        if(!root.insert(number)) return false;
    }
    return true;
}


int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<string> phoneNumbers(n);

        for(int i=0;i<n;i++){
            cin>>phoneNumbers[i];
        }

        if(isConsistent(phoneNumbers)){
            cout<<"YES\n";
        }
        else cout<<"NO\n";
    }


    return 0;
}