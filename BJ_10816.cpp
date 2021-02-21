//problem link : https://www.acmicpc.net/problem/10816

#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;
bool compare(int i, int j)
{
  if (i<j) return true;
  else return false;
}
int main()
{
  int m ,n;
  int i;
  scanf("%d", &m);
  int m_nums[m];
  for(i=0; i<m; i++) scanf("%d", &m_nums[i]);

  sort(m_nums, m_nums+m, compare);

  scanf("%d", &n);
  int n_nums[n];
  for(i=0; i<n; i++) scanf("%d", &n_nums[i]);

  for(i=0; i<n; i++)
  {
    int left = 0;
    int right = m-1;
    while(left<=right)
    {
      int mid = left+ (right-left)/2;
      if(m_nums[mid] < n_nums[i]) left = mid+1;
      else right = mid-1;
    }

    int left2 = 0;
    int right2 = m-1;
    while(left2<=right2)
    {
      int mid = left2+ (right2-left2)/2;
      if(m_nums[mid] <= n_nums[i]) left2 = mid+1;
      else right2 = mid-1;


    }
    printf("%d ", right2-right);
  }
  return 0;
}