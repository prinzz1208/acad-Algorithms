#include <iostream>
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
int* ssort(int *a)
{
	for (int i = 0; i < n-1; ++i)
	{
		int min=i;
		for (int j = i; j <n ; ++j)
		{
			if(a[j]<a[min])
				min=j;
		}
		int temp=a[i];
		a[i]=a[min];
		a[min]=temp;
	}
	return a;
}
int* insort(int *a)
{
	for (int i = 1; i <n ; i++)
	{
		int temp=a[i];
		int j=i;
		while(j>0 && temp<a[j-1])
		{
			a[j]=a[j-1];
			j=j-1;
		}
		a[j]=temp;
	}
	return a;
}
int* bsort(int *a){
	for (int i = 0; i <n-1 ; i++)
	{
		for (int j = 0; j <n-i-1 ; j++)
		{
			if(a[j]>a[j+1])
			{
				a[j]=a[j]+a[j+1];
				a[j+1]=a[j]-a[j+1];
				a[j]=a[j]-a[j+1];
			}
		}

	}
	return a;

}

void merge(int *a,int f,int l){
	int mid=(f+l)/2;
	int i1=0,i2=f,i3=mid+1;
	int temp[100];
	while(i2<=mid && i3<=l)
	{
		if(a[i2]<a[i3])
		{
			cout<<"a[i2]:"<<a[i2];
			temp[i1++]=a[i2++];
		}
		else
		{
			cout<<"a[i3]:"<<a[i3];
			temp[i1++]=a[i3++];
		}
	}
	while(i2<=mid){
		temp[i1++]=a[i2++];
	}
	while(i3<=l){
		temp[i1++]=a[i3++];
	}

	for (int i = 0; i <=l ; ++i)
	{
		a[i]=temp[i];
	}
}

void mergesort(int *data,int first,int last){
	if	(first<last)
	{
		int mid	=(first+last)/2;
		mergesort(data,first,mid);
		mergesort(data,mid+1,last);
		merge(data,first,last);
	}
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

	bsort(a);
	show(a);
}
