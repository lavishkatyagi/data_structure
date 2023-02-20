#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n,x;
	vector<int>hash[15];
	cout<<"enter the no of elements : ";
	cin>>n;	
	for(int i=0;i<n;i++){
		cin>>x;
		int r = x%10;
		hash[r].push_back(x);
	}
	for(int i=0;i<n;i++){
		cout<<i<<" : ";
		for(int j=0;j<hash[i].size();j++){
			cout<<hash[i][j]<<",";
		}
		cout<<endl;
	}
}