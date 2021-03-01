// problem link : https://www.acmicpc.net/problem/2110

#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;
int n, c;
bool compare(int i, int j)
{
  if(i<j) return true;
  else return false;
}

bool isfeasible(int house[], int dist)
{
  int d = 0;
  int count = 1;
  for(int i=0; i<n; i++)
  {
    if(i==0) continue;
    d += house[i] - house[i-1];
    if(d>= dist)
    {
      d=0;
      count +=1;
      if(count == c) return true;
    }
  }
  return false;
}

int main()
{
  scanf("%d %d", &n, &c);
  int house[n];
  for(int i=0; i<n; i++)
  {
    scanf("%d", &house[i]);
  }
  sort(house, house+n);

  int left = 0;
  int right = house[n-1];
  int mid;
  while(left <= right)
  {
    mid = left + (right-left)/2;
    if (isfeasible(house, mid)) left = mid+1;
    else right = mid-1;
  }
  printf("%d", right);
}