#include<bits/stdc++.h>
using namespace std;

void insertion(vector <pair<int,int>>& hash , int count){
    int n;
    cout<<"Enter the number that you want to insert =";
    cin>>n;
    count++;
    int index=n%10;
    if(hash[index].first==-1){
        hash[index].first=n;
    }
    else if (count != 10 && index == hash[index].first % 10)
    {
        while (hash[index].second != -1)
        {
            index = hash[index].second;
        }
        int chain_index = index;
        while (hash[index].first != -1)
        {
            index = (index + 1) % 10;
        }
        hash[chain_index].second = index;
        if (hash[index].first == -1)
        {
            hash[index].first = n;
        }
    }
    else{
        int new_index=index;
        int old_element=hash[index].first;
        hash[index].first=n;
        int new_chain_index=hash[index].second;
        hash[index].second=-1;
        while(hash[index].first!=-1){
            index=(index+1)%10;
        }
        if(hash[index].first==-1){
            hash[index].first=old_element;
            hash[index].second=new_chain_index;
        }
        for(int i=0; i<10; i++){
            if(hash[i].second==new_index){
                hash[i].second=index;
            }
        }
    }

}

void display(const vector<pair<int,int>> &hash)
{
   
    for (int i = 0; i < 10; i++)
    {
        if (hash[i].first == -1)
        {
            cout << i << "    : " << "-1" << "  " << hash[i].second << endl;
        }
        else
        {
            cout << i << "    : " << hash[i].first << "      " << hash[i].second << endl;
        }
    }
}



int search(const vector<pair<int,int>> &hash,int g){
    if(hash[g%10].first == -1){
        return -1;
    }else if(hash[g%10].first == g){
        return g%10;
    }
    int r = hash[g%10].second;
    while(r!=-1){
        if(hash[r].first == g){
            return r;
        }
        r = hash[r].second;
    }
    return -1;
}
int main(){
    vector<pair<int,int>> hash;for(int i=0;i<10;i++){hash.push_back(make_pair(-1,-1));}
    
    int choice;
    int count = 0;
    while(1){
        cout << endl;
        
        cout << "1.Insertion / 2.Display /  3.Searching / 4.Exit" << endl;
        
        cout << "Enter your choice " << endl;
        cin >> choice;
        if(choice == 1){
            insertion(hash , count);
        }else if(choice == 2){
            display(hash);
        }else if(choice == 3){
            cout<<" Enter the number to search\n";
            int g;cin>>g;
            int x = search(hash,g);
            
            if(x!=-1){
                cout<<"Element found at index = "<<x<<"\n";
            }else{
                cout<<"Element not found\n";
            }
        }else if(choice == 4){
            cout << "Exiting the programm..." << endl;
            cout << endl;
        }else{
            cout << "Invalid choice , please enter choice again" << endl;
        }
    }
}