#include <iostream>
#include <string>
using namespace std;
int n=0;
string max;
void show(string *a,int n){
	cout<<endl;
	for (int i = 0; i < n; ++i)
		cout<<a[i]<<"\t";
	cout<<endl;
}
void countsort(string *a,int n,int x){
	cout<<"\nInitial:";
	show(a,n);
	int max=int(a[0][x]-'0'),min=int(a[0][x]-'0');
	for (int i = 0; i <n ; i++)
	{
		if(int(a[i][x]-'0')<min)
			min=int(a[i][x]-'0');
		if(int(a[i][x]-'0')>max)
			max=int(a[i][x]-'0');
	}

	int a2[max+1]={0};
	for (int i = 0; i <n ; i++)
		for (int j = min; j <=max ; j++)
			if(int(a[i][x]-'0')==j){
				a2[j]++;
			}

	for (int i = min; i <=max ; i++)
		a2[i+1]=a2[i]+a2[i+1];

	string a3[n+1];
	for (int i = n-1; i >=0 ; i--)
		for (int j = min; j <=max ; j++)
			if(int(a[i][x]-'0')==j){
				a3[a2[j]]=a[i];
				a2[j]--;
			}
	// cout<<"\nmin:"<<min<<" max:"<<max;
	if(max!=0)
		for (int i=1,j=0; i<=n; i++,j++) {
				// cout<<"\na3[i]:"<<a3[i];
				a[j]=a3[i];
		}
	cout<<"\nFinal:";
	show(a,n);

}
void radixsort(string *a){
	string max=a[0];
	for (int i = 0; i <n; ++i)
	{
		if(stoi(a[i])>stoi(max))
			max=a[i];
	}
	// cout<<"\nmax:"<<max;
	for (int i = 0; i < n; ++i)
		if(a[i].length()<max.length())
		{
			string temp;
			for (int j = 0; j <(max.length()-a[i].length()); ++j)
				temp+="0";
			temp+=a[i];
			a[i]=temp;
		}
	cout<<"\nmax.length()-1:"<<max.length()-1;
	for (int i = max.length()-1; i >= 0; --i)
			countsort(a,n,i);
}
int main()
{
	// cout<<"Enter no. of elements:";
	// cin>>n;
	// cout<<"\nEnter elements:";
	// string *s;
	// s=new string[n];
	// for (int i = 0; i < n; ++i)
	// 	cin>>s[i];

	string s2[]={"2","123550","510","1","150"};
	n=5;
	radixsort(s2);
	return 0;
}
