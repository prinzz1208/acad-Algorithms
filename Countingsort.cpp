#include <iostream>
using namespace std;
int *a,n;
void show(int *a,int m,int n)
{
	cout<<endl;
	for (int i = m; i <=n ; i++)
	{
		cout<<a[i]<<"\t";
	}

	cout<<endl;

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
int main()
{
	cout<<"Enter no. of Elements:";
	cin>>n;
	a=new int[n];
	cout<<"\nEnter elements:";
	for (int i = 0; i < n; i++)
	{
		cin>>a[i];
	}
	countsort(a);
}
