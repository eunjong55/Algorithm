#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

int main(int argc, char** argv)
{
  int n;
  scanf("%d", &n);
  int nums[n];
  int i;
  for(i=0; i<n; i++)
  {
    scanf("%d", &nums[i]);
  }

  int dp[n];
  for(i=0; i<n; i++)
  {
    if(i==0 && nums[i]>0) dp[i] = nums[i];
    else
    {
      if(dp[i-1]+nums[i]>=0) dp[i] = dp[i-1]+nums[i];
      else dp[i] = 0; 
    }
  }
  int max = -1;
  for(i=0; i<n; i++)
  {
    if(max<dp[i]) max = dp[i];
  }

  if(max == 0)
  {
    max = -1000;
    for(i=0; i<n; i++)
    {
      if(max<nums[i]) max = nums[i];
    }
  }

  printf("%d", max);
  return 0;
}