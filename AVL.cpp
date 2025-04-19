#include <bits/stdc++.h>

using namespace std;

class node
{
public:
    int data;
    int height;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        this->height = 0;
        this->left = NULL;
        this->right = NULL;
    }
};

int getheight(node *root)
{
    if (root == NULL)
        return 0;
    return 1 + max(getheight(root->left), getheight(root->right));
}

int bf(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return getheight(root->left) - getheight(root->right);
}

node* leftrotate(node* root){
    node* child = root->right;
    node* childleft = child->left;
    child->left = root;
    root->right = childleft;
    root->height = getheight(root);
    child->height = getheight(child);
    return child;
}

node* rightrotate(node* root){
    node* child = root->left;
    node* childright = child->right;
    child->right = root;
    root->left = childright;
    root->height = getheight(root);
    child->height = getheight(child);
    return child;
}

node *insert(node *root, int k)
{
    if (root == NULL)
    {
        return new node(k);
    }
    else if (root->data < k)
    {
        root->right = insert(root->right, k);
    }
    else if (root->data > k)
    {
        root->left = insert(root->left, k);
    }else{
        return root;
    }

    root ->height = getheight(root);

    int BF = bf(root);

    //rr
    if((BF) < -1 && k > root->data){
        return leftrotate(root);
    }
    //ll
    else if(BF > 1 && k < root->data){
        return rightrotate(root);
    }

    //lr
    else if(BF > 1 && k > root->data){
        root->left = leftrotate(root);
        return rightrotate(root);
    }
    //rl
    else if(BF < -1 && k < root->data){
        root->right = rightrotate(root);
        return leftrotate(root);
    }

    return root;
}

void postorder(node *root)
{
    if (root == NULL)
        return;
    
    cout << root->data << " ";
    postorder(root->left);
    postorder(root->right);
}
int main()
{   
    node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 25);
    root = insert(root, 35);


    postorder(root);
}
