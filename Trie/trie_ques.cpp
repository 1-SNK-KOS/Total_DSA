#include <bits/stdc++.h>

struct Node{
    Node *links[26];
    bool flag = false;
    int countprefix = 0;

    public:
    bool containKey(char ch){
        return links[ch - 'a']!=NULL;
    }

    void put(char ch){
        links[ch - 'a'] = new Node();
    }

    Node *get(char ch){
        return links[ch - 'a'];
    }

    void setEnd(){
        flag = true;
    }

    bool setEnd(){
        return flag;
    }

    void setprefix(){
        countprefix++;
    }

    int getprefix(){
        return countprefix;
    }
};

class Trie{
 Node *root;

 public:
 Trie(){
     root = new Node();
 }

 void insert(string &word,vector<string>&str){

     Node *node = root;

    //  if(!root->containKey(word[0])) root->setprefix();

     for(int i=0;i<word.length();i++){

        //  if(node->containKey(word[i])->getEnd()) 

         if(!node->containKey(word[i]) && i==word.length()-1){
             node->put(word[i]);
         }
         else if(!(node->containKey(word[i]))->setEnd() || !node->containKey(word[i]) && i!=word.length()-1){
             return;
         }
         node = node->get(word[i]);
         node->setprefix();
     }
       
      node->setEnd();
      str.push_back(word);
   }

};

string completeString(int n, vector<string> &arr){
    // Write your code here.

    Trie *t = new Trie();

    string s="";
    vector<string>str;

    for(int i=0;i<n;i++){
        t->insert(arr[i],str); 
    }
     int maxi = 0;
     
    for(int i=0;i<str.size();i++){
       if(maxi<str[i].size()){
           maxi = str[i].size();
           s = str[i];
       }
       else if(maxi == str[i].size()){
           for(int j=0;i<str[i].size();i++){
               if(s[j]!=str[i][j]){
                   if(s[j]<str[i][j]){
                       break;
                   }
                   else{
                       s = str[i];
                   }
               }
           }
       }
    }
  return s;    
}