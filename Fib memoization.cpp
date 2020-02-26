#include <iostream>
using namespace std;
int FM[100];
int Fib(int n)
{
    if (n<=1)
    {
        return n;
    }
    if (FM[n] != -1)
    {
        return FM[n];
    }
    FM[n] = Fib(n-1) + Fib(n-2);
    return FM[n];
}
int main()
{
  for(int i =0; i<100; i++)
  {
      FM[i] = -1;
  }
      int n;
      cout<<"enter n: ";
      cin>> n;
      int result = Fib(n);
      cout<< result;
  
  	return 0;
}
