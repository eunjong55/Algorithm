#include <stdio.h>
#include <limits.h>

int main()
{
  int n, s;
  scanf("%d %d", &n, &s);
  int arr[n];
  for(int i=0; i<n; i++) scanf("%d", &arr[i]);
  int min = INT_MAX;
  int left=0;
  int right=0;
  int sum = arr[0];
  int cnt = 1;

  while(right<n)
  {
    if(sum<s) {
      right+=1;
      sum+=arr[right];
      cnt++;
    }
    else if(sum >= s)
    {
      if(left==right)
      {
        right+=1;
        left+=1;
        sum = arr[left];
        cnt = 1;
      }
      if(min>cnt) min = cnt;
      sum-=arr[left];
      left+=1;
      cnt-=1;
    }
  }
  if(min == INT_MAX) printf("0");
  else printf("%d", min);
}