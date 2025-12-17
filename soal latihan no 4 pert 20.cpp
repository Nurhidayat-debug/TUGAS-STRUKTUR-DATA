#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* left;
    Node* right;
};


Node* buatNode(int nilai) {
    Node* nodeBaru = new Node;
    nodeBaru->data = nilai;
    nodeBaru->left = NULL;
    nodeBaru->right = NULL;
    return nodeBaru;
}


void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}


void preorder(Node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}


void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

int main() {
    /*
        Struktur Tree:
               10
              /  \
             5   15
            / \    \
           3   7    20
    */

    Node* root = buatNode(10);
    root->left = buatNode(5);
    root->right = buatNode(15);
    root->left->left = buatNode(3);
    root->left->right = buatNode(7);
    root->right->right = buatNode(20);

    cout << "Hasil Traversal Tree:\n";

    cout << "Inorder   : ";
    inorder(root);
    cout << endl;

    cout << "Preorder  : ";
    preorder(root);
    cout << endl;

    cout << "Postorder : ";
    postorder(root);
    cout << endl;

    return 0;
}
