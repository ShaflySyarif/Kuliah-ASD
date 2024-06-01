#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node
{
    int key;
    int count;
    struct node *left, *right;
};

// A utility function to create a new BST node
struct node *newNode(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->count = 1;
    temp->left = temp->right = NULL;
    return temp;
}

// A utility function to do inorder traversal of BST
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d(%d) ", root->key, root->count);
        inorder(root->right);
    }
}

/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key);

    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        node->count += 1;  // increment the count of the node if the same value is found

    /* return the (unchanged) node pointer */
    return node;
}

/* Fungsi untuk mencari node dengan nilai minimum di sub-pohon yang diberikan */
struct node * minValueNode(struct node* node)
{
    struct node* current = node;

    /* loop down untuk mencari node paling kiri */
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

/* Fungsi untuk menghapus node dengan nilai tertentu */
struct node* deleteNode(struct node* root, int key)
{
    // base case
    if (root == NULL) return root;

    // Jika key yang akan dihapus lebih kecil dari root's key,
    // maka berada di sub-pohon kiri
    if (key < root->key)
        root->left = deleteNode(root->left, key);

    // Jika key yang akan dihapus lebih besar dari root's key,
    // maka berada di sub-pohon kanan
    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    // jika key sama dengan root's key, maka ini adalah node yang akan dihapus
    else
    {
        // jika count lebih besar dari 1, kurangi count dan kembalikan root
        if (root->count > 1)
        {
            root->count--;
            return root;
        }

        // node dengan hanya satu anak atau tanpa anak
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        // node dengan dua anak: Dapatkan inorder successor (node terkecil
        // dalam sub-pohon kanan)
        struct node* temp = minValueNode(root->right);

        // Copy inorder successor's content ke node ini
        root->key = temp->key;

        // Hapus inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

/* Fungsi untuk mencari node dengan nilai terkecil pada right subtree */
struct node * minValueRightSubtree(struct node* root)
{
    struct node* current = root;

    /* Jika root memiliki right subtree, cari node dengan nilai terkecil */
    if (root->right != NULL)
    {
        current = root->right;
        /* loop down untuk mencari node paling kiri */
        while (current && current->left != NULL)
            current = current->left;
    }

    return current;
}

/* Fungsi untuk menghapus node dengan nilai terkecil pada right subtree */
struct node* deleteMinRightSubtree(struct node* root)
{
    // base case
    if (root == NULL) return root;

    // Jika root memiliki right subtree, cari node dengan nilai terkecil
    if (root->right != NULL)
    {
        struct node* minRightSubtreeNode = minValueRightSubtree(root);

        // Hapus node dengan nilai terkecil pada right subtree
        root = deleteNode(root, minRightSubtreeNode->key);
    }
    return root;
}

// A utility function to do reverse inorder traversal of BST
void reverseInorder(struct node *root)
{
    if (root != NULL)
    {
        reverseInorder(root->right);
        printf("%d(%d) ", root->key, root->count);
        reverseInorder(root->left);
    }
}

int main()
{
    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    insert(root, 2);
    insert(root, 7);
    insert(root, 1);
    insert(root, 89);
    insert(root, 5);
    insert(root, 23);
    insert(root, 1);
    // print inoder traversal of the BST
    printf("Mencetak data yang ada : \n");
    inorder(root);
    printf("\n\nMencetak data dari terbesar ke kecil : \n");
    reverseInorder(root);
    // struct node* minNode = minValueRightSubtree(root);
    // printf("\nNilai terkecil pada right subtree adalah %d\n", minNode->key);

    // root = deleteNode(root, minNode->key);
    // root = deleteNode(root, 89);
    // deleteNode(root,5);
    // deleteNode(root,23);
    // inorder(root);
    // printf("Mencetak data setelah penghapusan : \n");
    // inorder(root);
    _getch();
    return 0;
}
