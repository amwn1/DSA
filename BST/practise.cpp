
#include <iostream>
using namespace std;

struct Node {
    int data ; 
    Node* left;
    Node* right;

    Node(int value){
     data = value;
    left=right=NULL;
    }
};  // This is how you create a node structure 
 
// Below is how to insert a node 

Node* insert(Node* root, int value){
  if(root == NULL) return new Node(value);
  if(value < root->data) root->left = insert(root->left,value);
  else root->right = insert(root->right,value);
  return root;
}

bool search(Node* root, int value){
if(root == NULL) return false;
if(root->data == value) return true;
if(root->data < value) return search(root->right, value);
else return search(root->left,value);
}

int main(){
    Node*root = NULL;
    root = insert(root,15);
    insert(root,10);
    insert(root,20);
    insert(root,8);
    insert(root,12);
    insert(root,16);
    insert(root,25);
    insert(root,10);

    int key = 16;
    if(search(root,key)){
        cout << "Found" << endl;

    }
    else
    cout << "Not Found" << endl;
    return 0;

}