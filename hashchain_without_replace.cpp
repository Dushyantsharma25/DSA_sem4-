#include<iostream>
#include<cmath>


using namespace std;

int hash_f(int e){

	return e%10;

}


int main(){
	int n;
	cout<<"Enter size of array\n";
	cin>>n;
	int hash[10][2];for(int i=0;i<10;i++){hash[i][0]=-1;hash[i][1]=-1;}
	int a[n];
	cout<<"Enter elements of array\n";
	for(int i=0;i<n;i++){cin>>a[i];}
	
	int y;
	while(1){
		cout<<"To insert elements in hash table press 1\n";
		cout<<"To search a element press 2\n";
		cout<<"To display the hash table press 3\n";
		cout<<"To exit the menu press 4\n";

		cin>>y;

		if(y==1){
			int index = 0;
			for(int i=0;i<n;i++){
				if(hash[hash_f(a[i])][0]==-1){
					hash[hash_f(a[i])][0] = a[i];
				}else{
					index = hash_f(a[i]);
					int r = hash_f(a[i]);
					int l=0;
					int t=0;
					while(l<=10){
						int o = (r+l)%10;
						if(r==hash_f(hash[o][0])){index=o;}
						if(hash[o][0] == -1){
							hash[o][0] = a[i];
							if(hash[index][0]!=hash[o][0] && (hash_f(hash[index][0]) == hash_f(hash[o][0]))){
								hash[index][1]=o;
							}		
							t=1;
							break;
						}
						l++;
					}
					if(t==0){cout<<"hash array is full , anable to insert\n";}
				}
			}

		}else if(y==2){
			cout<<"Enter the value to search \n";
			int g=0;cin>>g;
			int d=0,t=0;
			int r = hash_f(g);
			if(hash[r][0] == g){
				cout<<g<<" Found at index = "<<r<<"\n";
			}else if(hash_f(hash[hash_f(g)][0] == hash_f(g))){
				int l=1;
				while(l<10){
					d = hash[r][1];
					if(hash[d][0] == -1){
						cout<<"Element not found \n";
						t=1;
						break;
					}else if(hash[d][0] == g){
						cout<<g<<" Found at index = "<<d<<"\n";
						t=1;
						break;
					}
					d = hash[d][1];
					l++;
				}
				if(t==0){
					cout<<"Element not found \n";
				}
			}
		}else if(y==3){
			cout<<"\n_____________\n";
			for(int i=0;i<10;i++){cout<<" | "<<i<<" | "<<hash[i][0]<<" | "<<hash[i][1]<<" | \n";}
			cout<<"=============\n";
		}else if(y==4){
			cout<<"\nThank you!\n";
			break;
		}


	}

	return 0;
}
