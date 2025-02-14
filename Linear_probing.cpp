#include<iostream>
#include<cmath>


using namespace std;


int hash_function(int a){

	return a%10;

}


int main(){

	cout<<"Enter size of array\n";
	int n;cin>>n;
	int a[n];	
	cout<<"Enter all elements of array\n";
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int hash[10];
	for(int i=0;i<10;i++){
		hash[i]=-1;
	}
	int m;
	while(1){
		
		cout<<"For insert a numbers press 1\n";
		cout<<"For delete a number press 2\n";
		cout<<"For display the hash list press 3\n";
		cout<<"For search a element press 4\n";
		cout<<"To Display load factor press 5\n";
		cout<<"For exit press 6\n";
		cin>>m;

		if(m==1){
			for(int i=0;i<n;i++){
				if(hash[hash_function(a[i])]==-1){
				hash[hash_function(a[i])] = a[i];
				}else{
					int r = hash_function(a[i]);
					int l=1;
					int t=0;
					while(l<10){
						int o = (r+l)%10;
						if(hash[o] == -1){
							hash[o] = a[i];
							t=1;
							break;
						}
						l++;
					}
					if(t==0){cout<<"hash array is full anable to insert\n";}
				}
			}
		}
		else if(m==2){
			cout<<"Enter a element to search\n";
			int e;cin>>e;
			int d=0;
			int comp = 0;
			if(hash[hash_function(e)]==e){cout<<"Element found at index "<<hash_function(e)<<"\n";d=1;comp++;}
			else if(hash[hash_function(e)]!=-1){
				int l=1;
				int r=hash_function(e);
				while(l<10){
					int o = (r+l)%10;
					if(hash[o] == -1){
						comp++;break;
					}else if(hash[o]==e){cout<<"Element found at index = "<<o<<"\n";d=1;comp++;cout<<"Element succesfully deleted\n";hash[o]=-2;}
					l++;
				}
			}
			if(d==0){cout<<"Element not found in hash table\n";}
			cout<<"Number of comparisions are = "<<comp<<"\n";
		}else if(m==3){
			cout<<"\nHash table is:-\n";
			for(int i=0;i<10;i++){cout<<i<<" "<<hash[i]<<"\n";}
		}else if(m==4){
			cout<<"Enter a element to search\n";
			int e;cin>>e;
			int d=0;
			int comp = 0;
			if(hash[hash_function(e)]==e){cout<<"Element found at index "<<hash_function(e)<<"\n";d=1;comp++;}
			else if(hash[hash_function(e)]!=-1){
				int l=1;
				int r=hash_function(e);
				while(l<10){
					int o = (r+l)%10;
					if(hash[o] == -1){
						comp++;break;
					}else if(hash[o]==e){cout<<"Element found at index = "<<o<<"\n";d=1;comp++;}
					l++;
				}
			}
			if(d==0){cout<<"Element not found in hash table\n";}
			cout<<"Number of comparisions are = "<<comp<<"\n";
		}else if(m==6){return 0;}
		else if(m==5){
			double g=0;
			for(int i=0;i<10;i++){if(hash[i]!=-1){g++;}}
			cout<<"Load factor of hash table is = "<<g/10.0<<"\n";
		}
		else{cout<<"Enter a valid option\n";}

	}

}
