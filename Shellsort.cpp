#include <iostream>
#include <cmath>
using namespace std;
int n,*a;
void show(int *a)
{
	cout<<endl;
	for (int i = 0; i < n; ++i)
	{
		cout<<a[i]<<"\t";
	}
}
void countsort(int *a){
	int max=a[0],min=a[0];
	for (int i = 0; i <n ; i++)
	{
		if(a[i]<min)
			min=a[i];
		if(a[i]>max)
			max=a[i];
	}
	int a2[max+1]={0};
	for (int i = 0; i <n ; i++)
	{
		for (int j = min; j <=max ; j++)
		{
			if(a[i]==j)
				a2[j]++;
		}
		
	}
	for (int i = min; i <=max ; i++)
	{
		a2[i+1]=a2[i]+a2[i+1];
	}
	
	int a3[n+1];
	for (int i = n-1; i >=0 ; i--)
	{
		for (int j = min; j <=max ; j++)
		{
			if(a[i]==j)
			{
				a3[a2[j]]=a[i];
				a2[j]--;
			}
		}
		
	}
	show(a3,1,n);
	
}
void shellsort(int *a)
{
	int gap=n;
	bool flag=true;
	for (int i = 0;gap!=1 ; ++i)
	{
		gap=floor(gap/2);
		
		cout<<"\ngap:"<<gap;
		for (int j = 0; j+gap<n; j++)
		{
			cout<<"\na[i]:"<<a[j];
			cout<<"\na[i+gap]:"<<a[j+gap];
			if(a[j]>a[j+gap])
			{
				a[j]=a[j]+a[j+gap];
				a[j+gap]=a[j]-a[j+gap];
				a[j]=a[j]-a[j+gap];
			}	
		}
	}
	countsort(a);
	show(a);
}
int main()
{
	cout<<"Enter no. of elements in array:";
	cin>>n;
	a=new int[n];
	cout<<"\n Enter elements:";
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}

	shellsort(a);
}