//problem link : https://www.acmicpc.net/problem/2579

#include<cstdio>
#include<cmath>

using namespace std;
int main()
{
  int n;
  scanf("%d", &n);
  int best[n+1];
  best[0] = 0;
  int s_list[n+1];
  
  for(int i=1; i<=n; i++) scanf("%d", &s_list[i]);
  for(int i=1;i<=n;i++)
  {
    if(i==1 || i==2) best[i] = best[i-1] + s_list[i];
    else
    {
      int max = -1;
      if(best[i-3]+ s_list[i-1] +s_list[i] > max) max = best[i-3]+ s_list[i-1] +s_list[i];
      if(best[i-2] + s_list[i] > max) max = best[i-2] + s_list[i];

      best[i] = max;
    }
  }
  printf("%d", best[n]);
}