//problem link : https://www.acmicpc.net/problem/1654

#include<cstdio>

using namespace std;

int main()
{
  int max = -1;
  int k ,n;
  scanf("%d %d", &k, &n);
  int lines[k];
  for(int i=0; i<k; i++)
  {
    scanf("%d", &lines[i]);
    if(lines[i]>max) max = lines[i];
  }
  long long left = 1;
  long long right = max;
  while(left<=right)
  {
    long long mid = left+(right-left)/2;
    int cnt = 0;
    bool isFeasible = false;
    for(int i=0; i<k; i++)
    {
      cnt += lines[i] / mid;
      if(cnt >= n){
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