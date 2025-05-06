#include<fstream>

#include<iostream>

using namespace std;


fstream don;


int main(){

    don.open("don.txt");
    string f;
    cout<<"write any thing in this file\n";

    while(true){
        getline(cin,f);
        don<<f<<"\n";
        if(f==""){break;}
    }

    don.close();

    don.open("don.txt");
    while(getline(don,f)){

        cout<<f<<"\n";
        
    }

    don.close();


    return 0;
}
