#include <stdio.h>

int main()
{
  int n;
  int m;
  
  scanf("%d %d", &n, &m);
  int nums[n];
  int sums[n];
  int res[m];

  for(int i=0; i<n; i++) scanf("%d", &nums[i]);
  int sum = 0;
  for(int i=0; i<n; i++)
  {
    sum+= nums[i];
    sums[i] = sum;
  }

  for(int i=0; i<m; i++)
  {
    int start, end;
    scanf("%d %d", &start, &end);
    res[i] = sums[end-1] - sums[start-2];
  }

  for(int i=0; i<m; i++) printf("%d\n", res[i]);
}
