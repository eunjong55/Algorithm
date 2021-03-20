#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

int main(int argc, char** argv)
{
  string first;
  string second;

  cin>>first;
  cin>>second;
  int n1 = first.length();
  int n2 = second.length();
  int cnt[n1][n2];
  int i,j;
  cnt[0][0] = 0;
  for(i=0; i<n1; i++)
  {
    for(j=0; j<n2; j++)
    {
      if(first.at(i) == second.at(j))
      {
        if(i==0) cnt[i][j] = 1;
        if(j==0) cnt[i][j] = 1;
        if(i>0&& j>0) cnt[i][j] = cnt[i-1][j-1] + 1;
      }
      else
      {
        if(i==0 && j>0) cnt[i][j] = cnt[i][j-1];
        if(j==0 && i>0) cnt[i][j] = cnt[i-1][j];
        if(i>0 && j>0) cnt[i][j] = max(cnt[i-1][j], cnt[i][j-1]); 
      }
    }
  }
  printf("%d", cnt[n1-1][n2-1]);
  return 0;
}