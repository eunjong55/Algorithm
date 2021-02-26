#include<cstdio>
#include<vector>
#include<cstring>

using namespace std;

int main()
{
  int n;
  scanf("%d", &n);
  int r_best[n];
  int g_best[n];
  int b_best[n];

  for(int i=0; i<n; i++)
  {
    int r_cost, g_cost, b_cost;
    scanf("%d %d %d", &r_cost, &g_cost, &b_cost);
    if(i==0)
    {
      r_best[i] = r_cost;
      g_best[i] = g_cost;
      b_best[i] = b_cost;
    }
    else
    {
      if(g_best[i-1] + r_cost < b_best[i-1] + r_cost)
      {
        r_best[i] = g_best[i-1]+r_cost;
      }
      else
      {
        r_best[i] = b_best[i-1]+r_cost;
      }
      
      if(r_best[i-1] + g_cost < b_best[i-1] + g_cost)
      {
        g_best[i] = r_best[i-1]+g_cost;
      }
      else
      {
        g_best[i] = b_best[i-1]+g_cost;
      }
      
      if(r_best[i-1] + b_cost < g_best[i-1] + b_cost)
      {
        b_best[i] = r_best[i-1]+b_cost;
      }
      else
      {
        b_best[i] = g_best[i-1]+b_cost;
      }
    }
  }
  int min = 1000001;
  if(r_best[n-1]<min) min = r_best[n-1];
  if(g_best[n-1]<min) min = g_best[n-1];
  if(b_best[n-1]<min) min = b_best[n-1];

  printf("%d", min);
  return 0;
}