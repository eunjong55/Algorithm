#include<cstdio>
#include<vector>
#include<cstring>

using namespace std;

int main()
{
  int n;
  scanf("%d", &n);
  int best[n+1];
  int list[n+1];

  memset(best, 0, sizeof(best));
  for(int i=1; i<n+1; i++)
  {
    scanf("%d", &list[i]);
    if(i==1)
    {
      best[i] = list[i];
    }
    else if(i==2)
    {
      best[i] = best[i-1]+list[i];
    }
    else
    {
      int max = -1;
      if(best[i-3]+list[i-1]+list[i] > max) max = best[i-3]+list[i-1]+list[i];
      if(best[i-2]+list[i] > max) max = best[i-2]+list[i];
      if(best[i-1] > max) max = best[i-1];
      best[i] = max;
    }
  }
  
  printf("%d\n", best[n]);
  
  return 0;
}
