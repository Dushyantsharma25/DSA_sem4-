#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node *left;
    node *right;

    node()
    {
        this->data = 0;
        this->left = NULL;
        this->right = NULL;
    }

    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void hoffman_code(node *a, string &d){
    if(a->left == NULL && a->right == NULL){
        cout<<a->data<<" "<<d<<endl;
        return;
    }
    if (a->left)
    {
        d += '0';
        hoffman_code(a->left, d);
    }
    d.pop_back();
    if (a->right)
    {
        d += '1';
        hoffman_code(a->right, d);
    }
    d.pop_back();
}

void hoffman_tree(vector<pair<int, node *>> &a){
    int n = a.size();
    sort(a.begin(), a.end());
    while (1)
    {
        int y = a[0].first + a[1].first;
        node *x = new node(y);

        x->left = a[0].second;
        x->right = a[1].second;
        a.push_back({y, x});
        a.erase(a.begin());
        a.erase(a.begin());
        sort(a.begin(), a.end());
        if (a.size() == 1)
        {
            return;
        }
    }
}

int main(){

    int n;
    cout << "Enter number of nodes to be insert.\n";
    cin >> n;

    vector<pair<int, node *>> a;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter element\n";
        int d;
        cin >> d;
        node *value = new node(d);
        a.push_back({d, value});
    }

    hoffman_tree(a);
    string s = "";
    hoffman_code(a[0].second, s);

    return 0;
}
