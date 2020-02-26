#include<iostream>
#include<string>
using namespace std;

int lcs(string str1, string str2, int len1, int len2)
{
  int i, j;
  int LCS[len1+1][len2+1];
  for(i=0;i<=len1;i++)
    LCS[i][0]=0;
  for(j=0;j<=len2;j++)
    LCS[0][j]=0;
  for(i=1;i<=len1;i++)
      {
          for(j=1;j<=len2;j++)
          {
              if(str1[i-1]==str2[j-1])
              {
                  LCS[i][j]=1+LCS[i-1][j-1];
              }
              else
              {
                  LCS[i][j]=max(LCS[i-1][j],LCS[i][j-1]);
              }
          }
      }
      return LCS[len1][len2];

}

int main()
{
    string str1,str2;

    cout<<"Enter 1st string   ";
    getline(cin, str1);

    cout<<"Enter 2nd string   ";
    getline(cin, str2);

    int len1=str1.length();
    int len2=str2.length();

    cout<<"The length of Longest common subsequence found is "<<lcs(str1,str2,len1,len2);

    cout<<endl;
    return 0;
}
