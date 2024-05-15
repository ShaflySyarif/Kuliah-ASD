//10.10

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

const int MAX_SIZE = 40;

struct Node {
    int data;
    Node *left;
    Node *right;
};

class Tree {
private:
    Node* root;
    int nodeCount;
    Node* createNode(int data);
    Node* sisipDtNode(Node* root, int data);
    void inorderTraversal(Node* root);
    void preorderTraversal(Node* root);
    void postorderTraversal(Node* root);
public:
    Tree();
    void sisipDtNode(int data);
    void generateRandomNodes(int count);
    void inorderTraversal();
    void preorderTraversal();
    void postorderTraversal();
};

Tree::Tree() {
    root = NULL;
    nodeCount = 0;
}

Node* Tree::createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* Tree::sisipDtNode(Node* root, int data) {
    if (root == NULL) {
        nodeCount++;
        root = createNode(data);
    } else if (data < root->data) {
        root->left = sisipDtNode(root->left, data);
    } else if (data > root->data) {
        root->right = sisipDtNode(root->right, data);
    }
    return root;
}

void Tree::sisipDtNode(int data) {
    if (nodeCount < 10) {
        if (data <= MAX_SIZE) {
            root = sisipDtNode(root, data);
        } else {
            cout << data << " ";
        }
    }
}

void Tree::generateRandomNodes(int count) {
    srand(time(NULL));
    while (nodeCount < count) {
        int data = rand() % 100;
        sisipDtNode(data);
    }
}

void Tree::inorderTraversal() {
    inorderTraversal(root);
    cout << endl;
}

void Tree::inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

void Tree::preorderTraversal() {
    preorderTraversal(root);
    cout << endl;
}

void Tree::preorderTraversal(Node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void Tree::postorderTraversal() {
    postorderTraversal(root);
    cout << endl;
}

void Tree::postorderTraversal(Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->data << " ";
    }
}

int main() {
    Tree tree;

    cout << "Data yang melebihi indeks: " << endl;
    tree.generateRandomNodes(10);
    cout << endl << endl;

    cout << "Data yang telah dimasukkan dan dilakukan Traversal : " << endl;
    cout << "Preorder Traversal BST: ";
    tree.preorderTraversal();

    cout << "Inorder Traversal BST: ";
    tree.inorderTraversal();

    cout << "Postorder Traversal BST: ";
    tree.postorderTraversal();

    return 0;
}
