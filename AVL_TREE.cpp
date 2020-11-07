#include<bits/stdc++.h>
using namespace std;

// AVL TREE IMPLEMENTATION

/*
Tree Input
9
20 25 30 10 5 15 27 19 16

10
10 20 30 40 50 60 70 80 90 100

*/

struct node {
    int val;
    node* left;
    node* right;
    int height;
    node(int d) {
        val = d;
        left = NULL;
        right = NULL;
        height = 1;
    }
};


node* root = NULL;

int height(node* root)
{
    if(!root) return 0;

    return root->height;
}

int bf(node* root)
{
    if(!root) return 0;

    return height(root->left) - height(root->right);
}

node* rightRotate(node* root)
{
    // Note down the affected nodes
    node* c = root;
    node* b = c->left;
    node* t3 = b->right;

    // Rotate

    b->right = c;
    c->left = t3;

    c->height = max(height(c->left)  ,  height(c->right)) + 1;
    b->height = max(height(b->left)  ,  height(b->right)) + 1;

    return b;
}

node* leftRotate(node* root)
{
    node* c = root;
    node* b = c->right;
    node* t3 = b->left;

    //Rotate

    b->left = c;
    c->right = t3;

    c->height = max(height(c->left)  ,  height(c->right)) + 1;
    b->height = max(height(b->left)  ,  height(b->right)) + 1;

    return b;
}

node* insert(node* root , int d)
{
    if(!root) {
        node* newNode = new node(d);
        return newNode;
    }

    if(d < root->val) root->left = insert(root->left , d );
    else if(d > root->val) root->right = insert(root->right  ,  d );

    root->height = max(height(root->left)  ,  height(root->right)) + 1;

    int balanceFactor = bf(root);

    // LL CASE

    if(balanceFactor > 1 and d < root->left->val)
    {
        return rightRotate(root);
    }

    // RR CASE

    if(balanceFactor < -1 and d > root->right->val)
    {
        return leftRotate(root);
    }

    // LR CASE

    if(balanceFactor > 1 and d > root->left->val)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RL CASE

    if(balanceFactor < -1 and d < root->right->val)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}


// MAX NODE VALUE IN LEFT SUBTREE
node* getMaxSuccessor(node* root)
{
    node* temp = root;

    while(temp->right) temp = temp->right;

    return temp;
}

node* deleteNode(node* root , int d)
{
    if(!root) return NULL;

    if(d < root->val) root->left = deleteNode(root->left , d);
    else if(d > root->val) root->right = deleteNode(root->right , d);
    else if(d == root->val)
    {
        if(!root->left or !root->right)
        {
            root =  (root->left ? root->left : root->right);
        }

        if(!root) return NULL;

        node* max_successor = getMaxSuccessor(root->left);

        int new_d = max_successor->val;

        root->val = max_successor->val;

        root->left = deleteNode(root->left , new_d);
    }



    root->height = max(height(root->left)  ,  height(root->right)) + 1;

    // Get BF

    int b = bf(root);

    // LL
    if(b > 1 and bf(root->left) >= 0) {
        return rightRotate(root);
    }

    //RR
    if(b < -1 and bf(root->right) <= 0) {
        return leftRotate(root);
    }

    //LR
    if(b > 1 and bf(root->left) < 0) {
        root->left = rightRotate(root->left);
        return leftRotate(root);
    }

    //RL
    if(b < -1 and bf(root->right) > 0) {
        root->right = leftRotate(root->right);
        return rightRotate(root);
    }

    return root;



}

void display(node* root)
{
    if(!root) return ;

    cout<<root->val<<" ";

    display(root->left);
    display(root->right);
}



int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++) {
        int a;
        cin>>a;
        root = insert(root , a);
    }

    display(root);

    deleteNode(root , 50);

    cout<<endl;

    display(root);

}
