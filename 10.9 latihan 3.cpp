//10.9 No 3
#include <iostream>
#include <stdlib.h> // srand, rand
#include <time.h>   // time

using namespace std;

struct Node {
    int data;
    Node *anakKiri;
    Node *anakKanan;
    Node(int);
};

struct Tree {
    Node *root;
    Tree();
    void sisipDtNode(int);
    void preorderTraversal();
    void inorderTraversal();
    void postorderTraversal();
    int hitungNode();
    int hitungDaun();
    int hitungTinggi();

private:
    void sisipDt(Node *, int);
    void preorder(Node *);
    void inorder(Node *);
    void postorder(Node *);
    int hitungNodeRecursive(Node *);
    int hitungDaunRecursive(Node *);
    int hitungTinggiRecursive(Node *);
};

Node::Node(int dt) {
    data = dt;
    anakKiri = anakKanan = NULL;
}

Tree::Tree() {
    root = NULL;
}

void Tree::sisipDtNode(int dtSisip) {
    if (root == NULL)
        root = new Node(dtSisip);
    else
        sisipDt(root, dtSisip);
}

void Tree::preorderTraversal() {
    preorder(root);
}

void Tree::inorderTraversal() {
    inorder(root);
}

void Tree::postorderTraversal() {
    postorder(root);
}

int Tree::hitungNode() {
    return hitungNodeRecursive(root);
}

int Tree::hitungDaun() {
    return hitungDaunRecursive(root);
}

int Tree::hitungTinggi() {
    return hitungTinggiRecursive(root);
}

int Tree::hitungNodeRecursive(Node *node) {
    if (node == NULL)
        return 0;
    else
        return 1 + hitungNodeRecursive(node->anakKiri) + hitungNodeRecursive(node->anakKanan);
}

int Tree::hitungDaunRecursive(Node *node) {
    if (node == NULL)
        return 0;
    if (node->anakKiri == NULL && node->anakKanan == NULL)
        return 1;
    else
        return hitungDaunRecursive(node->anakKiri) + hitungDaunRecursive(node->anakKanan);
}

int Tree::hitungTinggiRecursive(Node *node) {
    if (node == NULL)
        return -1;
    else {
        int tinggiKiri = hitungTinggiRecursive(node->anakKiri);
        int tinggiKanan = hitungTinggiRecursive(node->anakKanan);

        return 1 + max(tinggiKiri, tinggiKanan);
    }
}

void Tree::sisipDt(Node *node, int dtSisip) {
    if (dtSisip < node->data) {
        if (node->anakKiri == NULL)
            node->anakKiri = new Node(dtSisip);
        else
            sisipDt(node->anakKiri, dtSisip);
    } else if (dtSisip > node->data) {
        if (node->anakKanan == NULL)
            node->anakKanan = new Node(dtSisip);
        else
            sisipDt(node->anakKanan, dtSisip);
    }
}

void Tree::preorder(Node *node) {
    if (node == NULL)
        return;
    cout << node->data << ", ";
    preorder(node->anakKiri);
    preorder(node->anakKanan);
}

void Tree::inorder(Node *node) {
    if (node == NULL)
        return;
    inorder(node->anakKiri);
    cout << node->data << ", ";
    inorder(node->anakKanan);
}

void Tree::postorder(Node *node) {
    if (node == NULL)
        return;
    postorder(node->anakKiri);
    postorder(node->anakKanan);
    cout << node->data << ", ";
}

int main() {
    Tree *tree = new Tree();
    int nilai;
    cout << "Sisip nilai data berikut: " << endl;
    // sisip data 10 bilangan acak dari 0-99 ke dalam tree
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        nilai = rand() % 100;
        cout << nilai << " ";
        tree->sisipDtNode(nilai);
    }
    cout << "\n\nPreorder Traversal" << endl;
    tree->preorderTraversal();
    cout << "\n\nInorder Traversal" << endl;
    tree->inorderTraversal();
    cout << "\n\nPostorder Traversal" << endl;
    tree->postorderTraversal();
    
    cout << "\n\nJumlah node dalam BST: " << tree->hitungNode() << endl;
    cout << "Jumlah daun dalam BST: " << tree->hitungDaun() << endl;
    cout << "Tinggi BST: " << tree->hitungTinggi() << endl;
    
    delete tree;
    return 0;
}
