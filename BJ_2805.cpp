//problem link : https://www.acmicpc.net/problem/2805

#include<cstdio>
using namespace std;

int main()
{
  int n, m;
  int max =-1;
  scanf("%d %d", &n, &m);
  int heights[n];
  for(int i=0; i<n; i++) {
    scanf("%d", &heights[i]);
    if(heights[i]>max) max = heights[i];
  }

  long long left = 0;
  long long right = max;
  while(left<=right)
  {
    long long mid = left+(right-left)/2;
    long long cnt = 0;
    bool isFeasible = false;
    for(int i=0; i<n; i++)
    {
      if(heights[i] > mid) cnt += (heights[i] - mid);
      if(cnt >= m) {
        isFeasible = true;
        break;
      }
    }
    if(isFeasible) left = mid+1;
    else right = mid-1;
  }
  printf("%lld", right);
  return 0;
}