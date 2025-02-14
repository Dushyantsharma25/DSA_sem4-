#include<bits/stdc++.h>

using namespace std;



class node{
    public:
        int data;
        node* left;
        node* right;

        node(){
            this->data = 0;
            this->left = NULL;
            this->right = NULL;
        }

        node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

bool cheack_equal(node* root1,node* root2){
    if(root1 == NULL && root2 == NULL){
        return true;
    }else if(root1 == NULL || root2 == NULL){
        return false;
    }else if(root1 -> data == root2 -> data){
        if(cheack_equal(root1->left,root2->left)){
            if(cheack_equal(root1->right,root2->right)){
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }
    }else{
        return false;
    }
}

void print_preorder(node* root){
    if(root == NULL){
        return;
    }

    cout<<root->data<<"\n";
    print_preorder(root->left);
    print_preorder(root->right);
}

void print_inorder(node* root){
    if(root == NULL){
        return;
    }
    
    print_inorder(root->left);
    cout<<root->data<<"\n";
    print_inorder(root->right);
}

void print_postorder(node* root){
    if(root == NULL){
        return;
    }

    
    print_postorder(root->left);
    print_postorder(root->right);
    cout<<root->data<<"\n";
}

vector<int> iterative_preorder(node* root){
    vector<int> preorder;

    stack<node*> p;
    p.push(root);
    while(!p.empty()){
        node* value = p.top();
        p.pop();
        preorder.push_back(value->data);

        if(value->right != NULL){
            p.push(value->right);
        }

        if(value->left != NULL){
            p.push(value->left);
        }
    }
    return preorder;
}

vector<int> iterative_inorder(node* root){
    vector<int> inorder;


}

void search_element_in_BST(node* root,int x){
    if(root == NULL){
        cout<<"Element not found\n";
        return;
    }
    node* temp = root;
    while(1){
        if(temp -> data > x){
            if((temp -> left)->data == x){
                cout<<"Value successfuly found\n";
                return;
            }else{
                temp = temp -> left;
            }
        }else if(temp -> data < x){
            if((temp -> right)->data == x){
                cout<<"Value successfuly found\n";
                return;
            }else{
                temp = temp -> right;
            }
        }else if(temp == NULL){
            cout<<"Element not found\n";
            return;
        }
    }
}

void insert_binary_tree(node* root){
    int d;cout<<"Enter the element to insert\n";cin>>d;
    node* p = new node(d);
    if(root == NULL){
        root = p;
        return;
    }
    node* temp = root;
    while(1){
        if(temp -> data > d){
            if(temp -> left == NULL){
                temp -> left = p;
                cout<<"Value successfuly inserted\n";
                return;
            }else{
                temp = temp -> left;
            }
        }else if(temp -> data < d){
            if(temp -> right == NULL){
                cout<<"Value successfuly inserted\n";
                temp -> right = p;
                return;
            }else{
                temp = temp -> right;
            }
        }
    }
}


int main(){
    int d;cout<<"Enter Data for root node of first binary search tree\n";cin>>d;
    node* root1 = new node(d);
    int g;cout<<"Enter Data for root node of second binary search tree\n";cin>>g;
    node* root2 = new node(g);
    int c;
    while(1){
        cout<<"\n";
        cout<<"1. To insert element in binary search tree.\n";
        cout<<"2. To print preorder of tree.\n";
        cout<<"3. To print inorder of tree.\n";
        cout<<"4. To print postorder of tree.\n";
        cout<<"5. To print iterative preorder of tree.\n";
        cout<<"6. To print iterative inorder of tree.\n";
        cout<<"7. To print iterative postorder of tree.\n";
        cout<<"8. To cheack if both binary tree equal.\n";
        cout<<"9. To EXIT\n";
        cout<<"\n";
        cin>>c;


        if(c == 1){
            cout<<"\n";
            cout<<"1. perform operation with first binary search tree\n";
            cout<<"2. perform operation with second binary search tree\n";
            int y;cin>>y;cout<<"\n";
            if(y == 1){insert_binary_tree(root1);}else if(y == 2){insert_binary_tree(root2);}else{cout<<"Invalid option\n";};
            cout<<"\n";
        }else if(c == 2){
            cout<<"\n";
            cout<<"1. perform operation with first binary search tree\n";
            cout<<"2. perform operation with second binary search tree\n";
            int y;cin>>y;cout<<"\n";
            if(y == 1){print_preorder(root1);}else if(y == 2){print_preorder(root2);}else{cout<<"Invalid option\n";};
            cout<<"\n";
        }else if(c == 3){
            cout<<"\n";
            cout<<"1. perform operation with first binary search tree\n";
            cout<<"2. perform operation with second binary search tree\n";
            int y;cin>>y;cout<<"\n";
            if(y == 1){print_inorder(root1);}else if(y == 2){print_inorder(root2);}else{cout<<"Invalid option\n";};
            cout<<"\n";
        }else if(c == 4){
            cout<<"\n";
            cout<<"1. perform operation with first binary search tree\n";
            cout<<"2. perform operation with second binary search tree\n";
            int y;cin>>y;cout<<"\n";
            if(y == 1){print_postorder(root1);}else if(y == 2){print_postorder(root2);}else{cout<<"Invalid option\n";};
            cout<<"\n";
        }else if(c == 5){
            cout<<"\n";
            cout<<"1. perform operation with first binary search tree\n";
            cout<<"2. perform operation with second binary search tree\n";
            int y;cin>>y;cout<<"\n";
            if(y == 1){
                vector<int> p = iterative_preorder(root1);
                for(auto i : p){cout<<i<<"\n";}
            }else if(y == 2){
                vector<int> p = iterative_preorder(root2);
                for(auto i : p){cout<<i<<"\n";}
            }else{
                cout<<"Invalid option\n";
            }
            cout<<"\n";
        }else if(c == 6){
            cout<<"\n";
            // in progress
            cout<<"\n";
        }else if(c == 7){
            cout<<"\n";
            // in progress
            cout<<"\n";
        }else if(c == 8){
            cout<<"\n";
            if(cheack_equal(root1,root2)){
                cout<<"Both binary trees are equal\n";
            }else{
                cout<<"Trees are not equal\n";
            }
            cout<<"\n";
        }else if(c == 9){
            cout<<"\n";
            cout<<"\nProgram successfully terminated\n";
            cout<<"\n";
        }else{
            cout<<"\n";
            cout<<"\nInvalid option \n";
            cout<<"\n";
        }

    }

    return 0;
}

