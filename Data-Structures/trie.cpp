#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct trie{
    struct trie *child[26];
    bool isend;
};
int main(){
    struct trie* a=new trie();
    vector<string> words;
    int g;
    cout<<"Enter Number of words"<<endl;
    cin>>g;
    while(g--){
        string o;
        cin>>o;
        words.push_back(o);
    }
    for(auto x:words){
        struct trie* temp=a;
        for(int i=0;i<x.length();i++){
            if(temp->child[x[i]-'a']==NULL){
                temp->child[x[i]-'a']=new trie();
                temp->child[x[i]-'a']->isend=false;
            }
            temp=temp->child[x[i]-'a'];
        }
        temp->isend=true;
    }
    string s;
    cin>>s;
    struct trie* temp=a;
    for(int i=0;i<s.length();i++){
        if(temp->child[s[i]-'a']==NULL){
            cout<<"Not Found"<<endl;
            return 0;
        }
        temp=temp->child[s[i]-'a'];
    }
    cout<<"FOUND"<<endl;
}
