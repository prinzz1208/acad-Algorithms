#include <iostream>
#include "Tree.cpp"
using namespace std;

void show(int *a,int n){
  cout<<endl;
  for (int i = 0 ;i < n; i++)
  cout<<a[i]<<"\t";
  cout<<endl;
}

void heapsort(){

}

int main()
{
  int n=0;
  // cout<<"Enter no. of elements:";
  // cin>>n;
  // a=new int[n];
  // cout<<"\nEnter elements:";
  // for (int i = 0; i < n; i++)
  //   cin>>a[i];
  //
  // show(a,n);
  int a[]={20,330,510,1,150};
  n=5;
  tree t(a,5);
  // t.level();
  // t.heapify();
  // t.level();
  // t.update(a);
  // cout<<"a[0]:"<<a[0];
  // t.level();
  // show(a,n);
  for (int i = n-1; i >=0; i--) {
  t.level();
    t.update(a);
  show(a,n);
    t.heapify();
  }
  return 0;
}
