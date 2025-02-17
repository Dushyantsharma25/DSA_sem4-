#include<bits/stdc++.h>

using namespace std;



class node{
    public:
        int data;
        node* left;
        node* right;

        node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
        
};


void level_order(node* root){
    if(root == NULL){
        return;
    }

    queue<node*> p;
    p.push(root);
    while(!p.empty()){
        node* temp = p.front();
        p.pop();
        cout<<temp->data<<"\n";
        if(temp->left){p.push(temp->left);}
        if(temp->right){p.push(temp->right);}
    }
}

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

void insert_binary_tree(node* &root){
    int d;cout<<"Enter the element to insert\n";cin>>d;
    node* p = new node(d);
    if(root == NULL){
        root = p;
        cout<<"Value successfuly inserted\n";
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
    cout<<"\n";
    int n;cout<<"Enter number of trees you want to create\n";cin>>n;
    vector<node*> root(n,NULL);
    cout<<"\n";
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
        cout<<"8. To print in level order of tree.\n";
        cout<<"9. To cheack if both binary tree equal.\n";
        cout<<"10. To search a element in binary tree \n";
        cout<<"11. To make a clone of binary.\n";
        cout<<"12. To EXIT\n";
        cout<<"\n";
        cin>>c;


        if(c == 1){
            cout<<"\n";
            int y;cout<<"In which tree you want to insert data\n";cin>>y;
            y--;
            cout<<"\n";
            insert_binary_tree(root[y]);
            cout<<"\n";
        }else if(c == 2){
            cout<<"\n";
            cout<<"\nEnter the tree number you want to display\n";int y;cin>>y;
            y--;
            cout<<"\n";
            print_preorder(root[y]);
            cout<<"\n";
        }else if(c == 3){
            cout<<"\n";
            cout<<"\nEnter the tree number you want to display\n";int y;cin>>y;
            y--;
            cout<<"\n";
            print_inorder(root[y]);
            cout<<"\n";
        }else if(c == 4){
            cout<<"\n";
            cout<<"\nEnter the tree number you want to display\n";int y;cin>>y;
            y--;
            cout<<"\n";
            print_postorder(root[y]);
            cout<<"\n";
        }else if(c == 5){
            cout<<"\nEnter the tree number you want to display\n";int y;cin>>y;
            y--;
            cout<<"\n";
            vector<int> p = iterative_preorder(root[y]);
            for(auto i : p){cout<<i<<"\n";}
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
            cout<<"\nEnter the tree number you want to display\n";int y;cin>>y;
            y--;
            cout<<"\n";
            level_order(root[y]);
            cout<<"\n";
        }else if(c == 9){
            cout<<"\n";
            cout<<"Enter number of binary trees check for equality\n";
            int x,y;cin>>x>>y;x--;y--;
            cout<<"\n";
            if(cheack_equal(root[x],root[y])){
                cout<<"Both Binary trees are equal\n";
            }else{
                cout<<"Binary trees are not equal\n";
            }
            cout<<"\n";
        }else if(c == 10){
            cout<<"\n";
            int y,x;cout<<"Enter the number of tree in which you want to search the value\n";
            cin>>y;y--;cout<<"\n";
            cout<<"Enter the value you want to search \n";
            cin>>x;cout<<"\n";
            search_element_in_BST(root[y],x);
            cout<<"\n";
        }else if(c == 11){
            
        }else if(c == 12){
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
