#include<iostream>
using namespace std;


class node{
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

void hoffman_tree(node* root){

}

int main(){
    int n;cout<<"Enter number of nodes \n";cin>>n;
    int a[n];

    return 0;
}
