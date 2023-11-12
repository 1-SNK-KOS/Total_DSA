#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

vector < int > inorderTraversal(node * root) {

vector<int> inorder;

node *cur = root;

while(cur){

if(cur->left == NULL){
  inorder.push_back(cur->data);
  cur = cur->right;
}
else{
  node *prev = cur;
  prev = prev->left;

  while(prev->right && prev->right!=cur){
    prev = prev->right;
  }

  if(prev->right == NULL){
    prev->right = cur;
    cur = cur->left;
  }
  else{
    prev->right = NULL;
    inorder.push_back(cur->data);
    cur = cur->right;
  }
}
  
}


return inorder ;
    
}


vector < int > preorderTraversal(node * root) {
 vector<int> preorder;

 node *cur = root;
//  preorder.push_back(cur->data);

 while(cur){

  if(cur->left == NULL){
    preorder.push_back(cur->data);
    cur = cur->right;
  }
  else{
    node *prev = cur;
    // preorder.push_back(prev->data);
    prev = prev->left;

    while(prev->right && prev->right!=cur){
      prev = prev->right;
    }

    if(prev->right == NULL){
      prev->right = cur;
      preorder.push_back(cur->data);
      cur = cur->left;
    }
    else{
      prev->right = NULL;
      cur = cur->right;
      // preorder.push_back(cur->data);
    }
  }
 }
 return preorder;
}

struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return (node);
}

int main() {

  struct node * root = newNode(1);
  root -> left = newNode(2);
  root -> right = newNode(3);
  root -> left -> left = newNode(4);
  root -> left -> right = newNode(5);
  root -> left -> right -> right = newNode(6);

  vector < int > inorder;
  inorder = inorderTraversal(root);

  cout << "The Inorder Traversal is: ";
  for (int i = 0; i < inorder.size(); i++) {
    cout << inorder[i] << " ";
  }

   cout<<endl;
   
  vector < int > preorder;
  preorder = preorderTraversal(root);

  cout << "The Preorder Traversal is: ";
  for (int i = 0; i < preorder.size(); i++) {
    cout << preorder[i] << " ";
  }

  return 0;
}