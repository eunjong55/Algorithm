problem link : https://www.acmicpc.net/problem/1300

#include<cstdio>
#include<vector>
#include<cmath>

using namespace std;
int n;
int main()
{
  int k;
  scanf("%d", &n);
  scanf("%d", &k);

  int left = 1;
  int right = k; 

  int result = -1;
  while(left<=right)
  {
    int mid = (left+right)/2;
    int cnt = 0;
    for(int i=1; i<=n; i++)
    {
      if(mid > i*n)
      {
        cnt+=n;
      }
      else
      {
        cnt += mid / i;
      }
    }
    if(cnt < k)
    {
      left = mid+1;
    }
    else{
      right = mid-1;
      result = mid;
    }
  }
  printf("%d", result);
  return 0;
}