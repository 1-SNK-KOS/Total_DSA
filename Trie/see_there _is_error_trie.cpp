#include<bits/stdc++.h>
using namespace std;

class TrieNode{
 public:
    char data;
    TrieNode *child[26];
    bool isterminal ;

    TrieNode(char c){
          data = c;
          for(int i=0;i<26;i++){
            child[i] = NULL;
          }
          isterminal = false;
    }

};

class Trie{

public :
TrieNode *root;

Trie(){
    root = new TrieNode('\0');
}


// We will do with help of recursion
void insert_helper(TrieNode *root , string word){
// Base case
if(word.length() == 0){ 
    root->isterminal = true;
    return ;
}
// case to check : present or not 
// we assume it is only uppercase letter
int idx = word[0] - 'A';
TrieNode *temp ;
// present
if(root->child[idx]!=NULL){
    temp = root->child[idx];
}
else{
    // absent
    temp = new TrieNode(word[0]);
    root->child[idx] = temp;
}

insert_helper(temp,word.substr(1));
}
/*
// absent
if(root -> child[idx] == NULL){
  TrieNode *node = new TrieNode(word[0]);
   
  root->child[idx] = node;
}

// present (so just go to next)
insert_helper(root->child[idx],word.substr(1));
*/

/*TrieNode *temp = root->child[idx];

if(temp == NULL){
 TrieNode *node = new TrieNode(word[0]);
 temp = node;

 root->child[idx] = temp;
//  insert_helper(temp,word.substr(1));
}
// else {
//     insert_helper(temp,word.substr(1));
// }

insert_helper(temp,word.substr(1));
*/
// }

void insert(string word){
    insert_helper(root,word);
    return;
}
};


int main()
{

Trie *t = new Trie();
// Word Inserted
cout<<"Trie Created"<<endl;
t->insert("abcde");

cout<<"Word inserted successfully"<<endl;
return 0 ;
}