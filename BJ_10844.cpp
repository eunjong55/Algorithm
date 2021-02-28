//problem link : https://www.acmicpc.net/problem/10844

#include <cstdio>

using namespace std;
long long counts[100][10] = {0, };

int main()
{
  int n;
  int res=0;
  scanf("%d", &n);
  for(int i=1; i<10; i++)
  {
    counts[0][i] = 1;
  }

  for(int i=1; i<n; i++)
  {
    for(int j=0; j<10; j++)
    {
      if(j==0) counts[i][1] += counts[i-1][0]%1000000000;
      else if(j==9) counts[i][8] += counts[i-1][9]%1000000000;
      else
      {
        counts[i][j-1] += counts[i-1][j]%1000000000;
        counts[i][j+1] += counts[i-1][j]%1000000000;
      }
    }
  }

  for(int i=0; i<10; i++)
  {
    res += counts[n-1][i]%1000000000;
    res = res %1000000000;
  }

  printf("%d", res%1000000000);
}