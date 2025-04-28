#include<iostream>
using namespace std;

struct Node {
    int data ;
    Node* left;
    Node* right;

    Node ( int value){
     data = value ; 
    left = right = NULL;
    }
};

Node* insert(Node* root, int value){
    if(root == NULL) return root;
    if(value < root->data) root->left = insert(root->left,value);
    else root->right = insert(root->right,value);
    return root;
}

bool search(Node* root, int key) {
    if(root == NULL) return false ;
    if(root-> data == key ) return true ;
    if(key < root->data) return search(root->left, key);
    else return search(root->right,key);

}

// Inorder Traversal (Left → Node → Right)
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Preorder Traversal (Node → Left → Right)
void preorder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Postorder Traversal (Left → Right → Node)
void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}



int main() {
    Node* root = NULL;
    root = insert(root, 15);
    insert(root, 10);
    insert(root, 20);
    insert(root, 8);
    insert(root, 12);
    insert(root, 16);
    insert(root, 25);

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    cout << "Preorder Traversal: ";
    preorder(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    postorder(root);
    cout << endl;

    return 0;
}
