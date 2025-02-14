#include<iostream>
#include<cmath>

using namespace std;

int ascii(string x){
    int d = 0;
    int l = x.length();
    for(int i = 0; i < l; i++){
        int c = int(x[l - i - 1]);
        c = c * pow(10, i);
        d += c;
    }
    return d % 10;
}

class node {
public:
    string a;
    string m;
    node* next;

    node(string a, string m){
        this->a = a;
        this->m = m;
        this->next = nullptr;
    }
};

void insert(node* hash[]){
    cout << "Enter an element name to insert \n";
    string a;
    getline(cin, a);

    cout << "Enter meaning of word\n";
    string b;
    getline(cin, b);

    int v = ascii(a);
    node* temp = new node(a, b);

    if(hash[v] == nullptr){
        hash[v] = temp;
    }else{
        node* move = hash[v];
        hash[v] = temp;
        temp->next = move;
    }
}

void display(node* hash[]){
    for(int i = 0; i < 10; i++){
        node* temp = hash[i];
        if(temp == nullptr){
            cout << i << " "<< "No data at index "<< "\n";
            continue;
        }
        cout<< i << ' ';
        while(temp != nullptr){
            cout << temp->a << " = " << temp->m << " .";
            temp = temp->next;
        }
        cout << "\n";
    }
}


void search(node* hash[]){
    cout << "Enter word to search: ";
    string word;
    getline(cin, word);

    int v = ascii(word);
    node* temp = hash[v];

    while (temp != nullptr){
        if (temp->a == word) {
            cout << "Word found at index : "<< v << temp->a << " = " << temp->m << "\n";
            return;
        }
        temp = temp->next;
    }

    cout << "Word not found.\n";
}

int main() {
    node* hash[10] = {nullptr};
    int g;
    while (1) {
        cout << "Press 1 for insertion\n";
        cout << "Press 2 for Display\n";
        cout << "Press 3 for Search\n";
        cout << "Press 4 for Exit\n";
        cin >> g;
        cin.ignore();  
        switch (g) {
            case 1:
                insert(hash);
                break;
            case 2:
                display(hash);
                break;
            case 3:
                search(hash);
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid option press valid key\n";
                break;
        }
    }
    return 0;
}
